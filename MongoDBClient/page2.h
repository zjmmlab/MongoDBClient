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

private:
	Ui::Page2 *ui;
};
