#pragma once

namespace Ui {
	class Page1;
}

class Page1 : public QWidget
{
	Q_OBJECT

public:
	explicit Page1(QWidget *parent = Q_NULLPTR);
	~Page1();

private slots:
	void slot_sendRequest();
	void slot_requestFinished();

private:
	Ui::Page1 *ui;
	QNetworkAccessManager *m_networkManager;
	QNetworkReply *m_networkReply;
	QEventLoop *m_loop;
};

