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
	void slot_uploadFinished(QNetworkReply *reply);
	void slot_uploadError(QNetworkReply::NetworkError);
	void slot_sendDownloadRequest();
	void slot_writeToFile();
	void slot_downloadFinished(QNetworkReply *reply);
	void slot_downloadError(QNetworkReply::NetworkError);

private:
	Ui::Page2 *ui;
	QNetworkAccessManager *m_networkManager;
	QNetworkReply *m_uploadReply;
	QNetworkReply *m_downloadReply;
	QFile *m_file;
	QString m_filePath;
	QEventLoop *m_loop;
};
