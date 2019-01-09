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

	m_stacked = new QStackedWidget;
	m_page1 = new Page1;
	m_page2 = new Page2;
	m_stacked->addWidget(m_page1);
	m_stacked->addWidget(m_page2);

	QHBoxLayout *hLayout = new QHBoxLayout();
	hLayout->setSpacing(10);
	hLayout->setContentsMargins(12, 12, 12, 0);
	hLayout->addWidget(comboBox);
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
}
