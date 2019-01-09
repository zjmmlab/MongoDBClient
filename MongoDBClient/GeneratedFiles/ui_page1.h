/********************************************************************************
** Form generated from reading UI file 'page1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE1_H
#define UI_PAGE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page1
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *resultJson;
    QHBoxLayout *horizontalLayout;
    QLineEdit *imagesUrl;
    QPushButton *searchImages;

    void setupUi(QWidget *Page1)
    {
        if (Page1->objectName().isEmpty())
            Page1->setObjectName(QStringLiteral("Page1"));
        Page1->resize(539, 431);
        verticalLayout = new QVBoxLayout(Page1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        resultJson = new QTextEdit(Page1);
        resultJson->setObjectName(QStringLiteral("resultJson"));

        verticalLayout->addWidget(resultJson);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        imagesUrl = new QLineEdit(Page1);
        imagesUrl->setObjectName(QStringLiteral("imagesUrl"));
        imagesUrl->setMinimumSize(QSize(0, 20));

        horizontalLayout->addWidget(imagesUrl);

        searchImages = new QPushButton(Page1);
        searchImages->setObjectName(QStringLiteral("searchImages"));
        searchImages->setMinimumSize(QSize(120, 20));
        searchImages->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(searchImages);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Page1);

        QMetaObject::connectSlotsByName(Page1);
    } // setupUi

    void retranslateUi(QWidget *Page1)
    {
        Page1->setWindowTitle(QApplication::translate("Page1", "Form", Q_NULLPTR));
        searchImages->setText(QApplication::translate("Page1", "Search", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Page1: public Ui_Page1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE1_H
