/********************************************************************************
** Form generated from reading UI file 'deviceinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEINFO_H
#define UI_DEVICEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceInfo
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *name;
    QLabel *address;
    QPushButton *pushButton;

    void setupUi(QFrame *DeviceInfo)
    {
        if (DeviceInfo->objectName().isEmpty())
            DeviceInfo->setObjectName(QString::fromUtf8("DeviceInfo"));
        DeviceInfo->resize(585, 103);
        verticalLayoutWidget = new QWidget(DeviceInfo);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 551, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(verticalLayoutWidget);
        name->setObjectName(QString::fromUtf8("name"));
        QFont font;
        font.setPointSize(14);
        name->setFont(font);
        name->setFrameShape(QFrame::NoFrame);
        name->setScaledContents(false);
        name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(name);

        address = new QLabel(verticalLayoutWidget);
        address->setObjectName(QString::fromUtf8("address"));
        QFont font1;
        font1.setPointSize(10);
        address->setFont(font1);
        address->setScaledContents(false);
        address->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(address);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(DeviceInfo);

        QMetaObject::connectSlotsByName(DeviceInfo);
    } // setupUi

    void retranslateUi(QFrame *DeviceInfo)
    {
        DeviceInfo->setWindowTitle(QCoreApplication::translate("DeviceInfo", "Frame", nullptr));
        name->setText(QCoreApplication::translate("DeviceInfo", "Device Name", nullptr));
        address->setText(QCoreApplication::translate("DeviceInfo", "Device Name", nullptr));
        pushButton->setText(QCoreApplication::translate("DeviceInfo", "Force Sleep", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceInfo: public Ui_DeviceInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEINFO_H
