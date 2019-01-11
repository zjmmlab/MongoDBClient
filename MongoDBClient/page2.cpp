#include "stdafx.h"
#include "page2.h"
#include "ui_Page2.h"

Page2::Page2(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Page2)
{
	ui->setupUi(this);

	m_networkManager = new QNetworkAccessManager(this);
	m_uploadReply = Q_NULLPTR;
	m_downloadReply = Q_NULLPTR;
	m_deleteReply = Q_NULLPTR;
	m_file = Q_NULLPTR;
	m_loop = new QEventLoop(this);

	connect(ui->open, SIGNAL(clicked(bool)), this, SLOT(slot_loadFiles()));
	connect(ui->upload, SIGNAL(clicked(bool)), this, SLOT(slot_sendUploadRequest()));
	connect(ui->download, SIGNAL(clicked(bool)), this, SLOT(slot_sendDownloadRequest()));
	connect(ui->remove, SIGNAL(clicked(bool)), this, SLOT(slot_sendDeleteRequest()));
}

Page2::~Page2()
{
	delete ui;

	if (m_networkManager != Q_NULLPTR)
	{
		m_networkManager->deleteLater();
		m_networkManager = Q_NULLPTR;
	}

	if (m_file != Q_NULLPTR)
	{
		m_file->deleteLater();
		m_file = Q_NULLPTR;
	}

	if (m_loop != Q_NULLPTR)
	{
		delete m_loop;
		m_loop = Q_NULLPTR;
	}
}

void Page2::slot_loadFiles()
{
	m_filePaths = QFileDialog::getOpenFileNames(this,
		tr("Select one or more files to open"),
		"",
		tr("Image Files (*.png *.jpg *.bmp);; All files (*.*)"));

	ui->filePaths->addItems(m_filePaths);
}

void Page2::slot_sendUploadRequest()
{
	if (m_filePaths.length() < 1) return;

	QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

	QHttpPart textPart;
	textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"desc\""));	
	textPart.setBody(ui->description->text().toUtf8());
	multiPart->append(textPart);

	for (int i = 0; i < m_filePaths.length(); i++) {
		
		qDebug("UploadFileList [%d] [%s]", i, m_filePaths[i].toStdString().c_str());
		
		QFile *file = new QFile(m_filePaths[i]);

		QHttpPart imagePart;
		imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
		QString disposition("form-data; name=\"image\"; filename=\"" + file->fileName() + "\"");
		imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(disposition));

		file->open(QIODevice::ReadOnly);
		imagePart.setBodyDevice(file);
		file->setParent(multiPart);

		multiPart->append(imagePart);
	}	

	QSettings settings(QDir::currentPath() + "/Config.ini", QSettings::IniFormat);
	QUrl url(settings.value("Url/UploadMultiFilesUrl").toString());
	QNetworkRequest request(url);
	m_uploadReply = m_networkManager->post(request, multiPart);
	multiPart->setParent(m_uploadReply);

	connect(m_uploadReply, SIGNAL(finished()), this, SLOT(slot_uploadFinished()));
	connect(m_uploadReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slot_uploadError(QNetworkReply::NetworkError)));
	connect(m_uploadReply, SIGNAL(uploadProgress(qint64, qint64)), this, SLOT(slot_sendProgress(qint64, qint64)));
	
	emit showProgressBar(true);
	m_loop->exec();
}

void Page2::slot_uploadFinished()
{
	if (m_uploadReply->error() == QNetworkReply::NoError) {
		qDebug() << "upload finished";		
		m_uploadReply->deleteLater();
		m_uploadReply = NULL;		
		m_loop->exit();
		emit showProgressBar(false);
		m_filePaths.clear();
		ui->filePaths->clear();
	}
	else
	{
		QMessageBox::critical(NULL, tr("Error"), "Failed!");
	}
}

void Page2::slot_uploadError(QNetworkReply::NetworkError)
{
	qDebug() << "Error: " << m_uploadReply->error();
}

void Page2::slot_sendDownloadRequest()
{
	ui->imageView->clear();

	m_file = new QFile(QApplication::applicationDirPath() + "/" + "temp.jpg");
	m_file->open(QIODevice::WriteOnly);

	QUrl url(ui->imageUrl->text());

	if (!url.isValid()) return;
	
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/octet-stream"));
	m_downloadReply = m_networkManager->get(request);

	connect(m_downloadReply, SIGNAL(readyRead()), this, SLOT(slot_writeToFile()));
	connect(m_downloadReply, SIGNAL(finished()), this, SLOT(slot_downloadFinished()));
	connect(m_downloadReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slot_downloadError(QNetworkReply::NetworkError)));
	connect(m_downloadReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(slot_sendProgress(qint64, qint64)));
	
	emit showProgressBar(true);
	m_loop->exec();
}

void Page2::slot_writeToFile()
{
	m_file->write(m_downloadReply->readAll());
}

void Page2::slot_downloadFinished()
{
	if (m_downloadReply->error() == QNetworkReply::NoError)
	{
		qDebug() << "download finished";
		m_file->flush();
		m_file->close();
		m_downloadReply->deleteLater();
		m_downloadReply = NULL;

		QImage img(QApplication::applicationDirPath() + "/" + "temp.jpg");
		ui->imageView->setPixmap(QPixmap::fromImage(img));

		m_loop->exit();
		emit showProgressBar(false);
		
	}
	else
	{
		QMessageBox::critical(NULL, tr("Error"), "Failed!");
	}
}

void Page2::slot_downloadError(QNetworkReply::NetworkError)
{
	qDebug() << "Error: " << m_downloadReply->error();
}

void Page2::slot_sendDeleteRequest()
{
	QUrl url(ui->imageUrl->text());

	if (!url.isValid()) return;

	QNetworkRequest request(url);
	m_deleteReply = m_networkManager->deleteResource(request);
	connect(m_deleteReply, SIGNAL(finished()), this, SLOT(slot_deleteFinished()));
	m_loop->exec();
}

void Page2::slot_deleteFinished()
{
	if (m_deleteReply->error() == QNetworkReply::NoError)
	{
		qDebug() << "The \'Delete file\' request return : " << m_deleteReply->readAll();
		ui->imageUrl->clear();
		ui->imageView->clear();
	}
	else
	{
		QMessageBox::critical(NULL, tr("Error"), "Failed!");
	}

	m_deleteReply->deleteLater();
	m_loop->exit();
}

void Page2::slot_sendProgress(qint64 bytesSent, qint64 bytesTotal)
{
	emit doProgress(bytesSent, bytesTotal);
}