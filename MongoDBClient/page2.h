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

signals:
	void showProgressBar(bool bShow);
	void doProgress(qint64 bytesSent, qint64 bytesTotal);

private slots:
	void slot_loadFiles();
	void slot_sendUploadRequest();
	void slot_uploadFinished();
	void slot_uploadError(QNetworkReply::NetworkError);
	void slot_sendDownloadRequest();
	void slot_writeToFile();
	void slot_downloadFinished();
	void slot_downloadError(QNetworkReply::NetworkError);
	void slot_sendDeleteRequest();
	void slot_deleteFinished();
	void slot_sendProgress(qint64 bytesSent, qint64 bytesTotal);

private:
	Ui::Page2 *ui;
	QNetworkAccessManager *m_networkManager;
	QNetworkReply *m_uploadReply;
	QNetworkReply *m_downloadReply;
	QNetworkReply *m_deleteReply;
	QFile *m_file;
	QStringList m_filePaths;
	QEventLoop *m_loop;
};
