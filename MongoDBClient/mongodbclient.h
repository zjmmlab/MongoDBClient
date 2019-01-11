#pragma once

#include "page1.h"
#include "page2.h"

class MongoDBClient : public QWidget
{
	Q_OBJECT

public:
	MongoDBClient(QWidget *parent = Q_NULLPTR);

private slots:
	void slot_ShowProgressBar(bool bShow);
	void slot_doProgress(qint64 bytesSent, qint64 bytesTotal);

private:
	Page1 *m_page1;
	Page2 *m_page2;
	QProgressBar *m_progress;
	QStackedWidget *m_stacked;
};
