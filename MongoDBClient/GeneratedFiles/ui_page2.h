/********************************************************************************
** Form generated from reading UI file 'page2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE2_H
#define UI_PAGE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page2
{
public:
    QHBoxLayout *horizontalLayout_4;
    QLabel *imageView;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *filePaths;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *description;
    QHBoxLayout *horizontalLayout;
    QPushButton *open;
    QPushButton *upload;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *imageUrl;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *download;
    QPushButton *remove;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Page2)
    {
        if (Page2->objectName().isEmpty())
            Page2->setObjectName(QStringLiteral("Page2"));
        Page2->resize(1143, 759);
        horizontalLayout_4 = new QHBoxLayout(Page2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        imageView = new QLabel(Page2);
        imageView->setObjectName(QStringLiteral("imageView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageView->sizePolicy().hasHeightForWidth());
        imageView->setSizePolicy(sizePolicy);
        imageView->setMinimumSize(QSize(800, 600));
        imageView->setFrameShape(QFrame::Box);
        imageView->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(imageView);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(Page2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(276, 0));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        filePaths = new QListWidget(groupBox);
        filePaths->setObjectName(QStringLiteral("filePaths"));

        verticalLayout->addWidget(filePaths);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 20));

        horizontalLayout_3->addWidget(label);

        description = new QLineEdit(groupBox);
        description->setObjectName(QStringLiteral("description"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy2);
        description->setMinimumSize(QSize(0, 20));

        horizontalLayout_3->addWidget(description);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        open = new QPushButton(groupBox);
        open->setObjectName(QStringLiteral("open"));

        horizontalLayout->addWidget(open);

        upload = new QPushButton(groupBox);
        upload->setObjectName(QStringLiteral("upload"));

        horizontalLayout->addWidget(upload);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Page2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMaximumSize(QSize(276, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        imageUrl = new QLineEdit(groupBox_2);
        imageUrl->setObjectName(QStringLiteral("imageUrl"));

        verticalLayout_2->addWidget(imageUrl);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        download = new QPushButton(groupBox_2);
        download->setObjectName(QStringLiteral("download"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(download->sizePolicy().hasHeightForWidth());
        download->setSizePolicy(sizePolicy3);
        download->setMinimumSize(QSize(75, 0));
        download->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_2->addWidget(download);

        remove = new QPushButton(groupBox_2);
        remove->setObjectName(QStringLiteral("remove"));
        sizePolicy3.setHeightForWidth(remove->sizePolicy().hasHeightForWidth());
        remove->setSizePolicy(sizePolicy3);
        remove->setMinimumSize(QSize(75, 20));

        horizontalLayout_2->addWidget(remove);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(Page2);

        QMetaObject::connectSlotsByName(Page2);
    } // setupUi

    void retranslateUi(QWidget *Page2)
    {
        Page2->setWindowTitle(QApplication::translate("Page2", "Form", Q_NULLPTR));
        imageView->setText(QApplication::translate("Page2", "Show Image", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Page2", "Upload", Q_NULLPTR));
        label->setText(QApplication::translate("Page2", "Description:", Q_NULLPTR));
        open->setText(QApplication::translate("Page2", "Open ...", Q_NULLPTR));
        upload->setText(QApplication::translate("Page2", "Upload", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Page2", "Download/Delete", Q_NULLPTR));
        download->setText(QApplication::translate("Page2", "Download", Q_NULLPTR));
        remove->setText(QApplication::translate("Page2", "Delete", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Page2: public Ui_Page2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE2_H
