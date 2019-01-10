#include "stdafx.h"
#include "page2.h"
#include "ui_Page2.h"

Page2::Page2(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Page2)
	, m_filePath("")
{
	ui->setupUi(this);

	m_networkManager = new QNetworkAccessManager(this);
	m_networkReply = Q_NULLPTR;
	m_file = Q_NULLPTR;	

	connect(ui->open, SIGNAL(clicked(bool)), this, SLOT(slot_loadFiles()));
	connect(ui->upload, SIGNAL(clicked(bool)), this, SLOT(slot_sendUploadRequest()));
	connect(ui->download, SIGNAL(clicked(bool)), this, SLOT(slot_sendDownloadRequest()));
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
}

void Page2::slot_loadFiles()
{
	m_filePath = QFileDialog::getOpenFileName(this,
		tr("Open Image"),
		"",
		tr("Image Files (*.png *.jpg *.bmp);; All files (*.*)"));

	ui->filePaths->addItem(m_filePath);

}

void Page2::slot_sendUploadRequest()
{

}

void Page2::slot_sendDownloadRequest()
{
	m_file = new QFile(QApplication::applicationDirPath() + "/" + "temp.jpg");
	m_file->open(QIODevice::WriteOnly);

	QUrl url(ui->downloadUrl->text());

	if (!url.isValid()) return;
	
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/octet-stream"));
	m_networkReply = m_networkManager->get(request);

	connect(m_networkReply, SIGNAL(readyRead()), this, SLOT(slot_writeToFile()));
	connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_replyFinished(QNetworkReply*)));
	connect(m_networkReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slot_outputError(QNetworkReply::NetworkError)));
}

void Page2::slot_writeToFile()
{
	m_file->write(m_networkReply->readAll());
}

void Page2::slot_replyFinished(QNetworkReply *reply)
{
	if (reply->error() == QNetworkReply::NoError)
	{
		m_networkReply->deleteLater();
		m_file->flush();
		m_file->close();

		QImage img(QApplication::applicationDirPath() + "/" + "temp.jpg");
		ui->imageView->setPixmap(QPixmap::fromImage(img));
	}
	else
	{
		QMessageBox::critical(NULL, tr("Error"), "Failed!");
	}
}

void Page2::slot_outputError(QNetworkReply::NetworkError)
{
	qDebug() << "Error: " << m_networkReply->error();
}