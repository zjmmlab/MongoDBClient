#include "stdafx.h"
#include "mongodbclient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MongoDBClient w;
	w.show();
	return a.exec();
}
