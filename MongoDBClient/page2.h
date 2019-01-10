#pragma once

namespace Ui {
	class Page2;
}

class Page2 : public QWidget
{
	Q_OBJECT

public:
	explicit Page2(QWidget *parent = Q_NULLPTR);
	~Page2();

private slots:
	void slot_loadFiles();
	void slot_sendUploadRequest();
	void slot_sendDownloadRequest();
	void slot_writeToFile();
	void slot_replyFinished(QNetworkReply *reply);
	void slot_outputError(QNetworkReply::NetworkError);

private:
	Ui::Page2 *ui;
	QNetworkAccessManager *m_networkManager;
	QNetworkReply *m_networkReply;
	QFile *m_file;
	QString m_filePath;
};
