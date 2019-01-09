#pragma once

#include <QtWidgets/QWidget>
#include "ui_mongodbclient.h"

class MongoDBClient : public QWidget
{
	Q_OBJECT

public:
	MongoDBClient(QWidget *parent = Q_NULLPTR);

private:
	Ui::MongoDBClientClass ui;
};
