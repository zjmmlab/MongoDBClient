#include "stdafx.h"
#include "mongodbclient.h"

MongoDBClient::MongoDBClient(QWidget *parent)
	: QWidget(parent)
{
	QComboBox *comboBox = new QComboBox;
	comboBox->setMinimumHeight(20);
	comboBox->setFixedWidth(120);
	comboBox->addItem("Page1");
	comboBox->addItem("Page2");

	m_progress = new QProgressBar;
	m_progress->setTextVisible(true);
	m_progress->setValue(100);
	m_progress->hide();

	m_stacked = new QStackedWidget;
	m_page1 = new Page1;
	m_page2 = new Page2;
	m_stacked->addWidget(m_page1);
	m_stacked->addWidget(m_page2);

	QHBoxLayout *hLayout = new QHBoxLayout();
	hLayout->setSpacing(10);
	hLayout->setContentsMargins(12, 12, 12, 0);
	hLayout->addWidget(comboBox);
	hLayout->addStretch();
	hLayout->addWidget(m_progress);

	QVBoxLayout *vLayout = new QVBoxLayout();
	vLayout->setSpacing(0);
	vLayout->setContentsMargins(0, 0, 0, 0);
	vLayout->addLayout(hLayout);
	vLayout->addWidget(m_stacked);
	setLayout(vLayout);

	QFile f(":qdarkstyle/style.qss");
	if (!f.exists())
	{
		printf("Unable to set stylesheet, file not found\n");
	}
	else
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		qApp->setStyleSheet(ts.readAll());
	}

	connect(comboBox, SIGNAL(currentIndexChanged(int)), m_stacked, SLOT(setCurrentIndex(int)));
	connect(m_page2, SIGNAL(showProgressBar(bool)), this, SLOT(slot_ShowProgressBar(bool)));
	connect(m_page2, SIGNAL(doProgress(qint64, qint64)), this, SLOT(slot_doProgress(qint64, qint64)));
}

void MongoDBClient::slot_ShowProgressBar(bool bShow)
{
	if (bShow)
	{
		m_progress->setValue(0);
		m_progress->show();

	}
	else
	{		
		QEventLoop loop;
		QTimer::singleShot(500, &loop, SLOT(quit()));
		loop.exec();

		m_progress->hide();
	}
}

void MongoDBClient::slot_doProgress(qint64 bytesSent, qint64 bytesTotal)
{
	if (bytesTotal > 0)
	{
		qDebug() << "loaded" << bytesSent << "of" << bytesTotal;
		m_progress->setMaximum(100);
		m_progress->setValue(((double)bytesSent / (double)bytesTotal) * 100);
	}
}
