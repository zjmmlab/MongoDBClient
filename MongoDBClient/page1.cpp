#include "stdafx.h"
#include "page1.h"
#include "ui_Page1.h"

Page1::Page1(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Page1)
{
	ui->setupUi(this);

	QSettings settings(QDir::currentPath() + "/Config.ini", QSettings::IniFormat);
	ui->imagesUrl->setText(settings.value("Url/imagesUrl").toString());

	m_networkManager = new QNetworkAccessManager(this);
	m_loop = new QEventLoop(this);

	connect(ui->searchImages, SIGNAL(clicked(bool)), this, SLOT(slot_sendRequest()));
}


Page1::~Page1()
{
	delete ui;

	if (m_networkManager != Q_NULLPTR)
	{
		m_networkManager->deleteLater();
		m_networkManager = Q_NULLPTR;
	}

	if (m_loop != Q_NULLPTR)
	{
		delete m_loop;
		m_loop = Q_NULLPTR;
	}
}

void Page1::slot_sendRequest()
{
	QNetworkRequest request;
	QUrl url(ui->imagesUrl->text());

	if (!url.isValid()) return;

	request.setUrl(QUrl(ui->imagesUrl->text()));
	m_networkReply = m_networkManager->get(request);
	connect(m_networkReply, SIGNAL(finished()), this, SLOT(slot_requestFinished()));
	m_loop->exec();
}

void Page1::slot_requestFinished()
{
	if (m_networkReply->error() == QNetworkReply::NoError)
	{
		qDebug() << "request finished, get images info from http server.";
		QByteArray bytes = m_networkReply->readAll();
		QJsonDocument doc = QJsonDocument::fromJson(bytes);
		ui->resultJson->setText(doc.toJson());
	}	
	else
	{
		QMessageBox::critical(NULL, tr("Error"), "Failed!");
	}

	m_networkReply->deleteLater();
	m_loop->exit();
}