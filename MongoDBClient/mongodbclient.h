#pragma once

#include "page1.h"
#include "page2.h"

class MongoDBClient : public QWidget
{
	Q_OBJECT

public:
	MongoDBClient(QWidget *parent = Q_NULLPTR);

private:
	Page1 *m_page1;
	Page2 *m_page2;
	QProgressBar *m_progress;
	QStackedWidget *m_stacked;
};
