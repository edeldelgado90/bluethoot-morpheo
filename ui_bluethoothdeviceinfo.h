/********************************************************************************
** Form generated from reading UI file 'bluethoothdeviceinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUETHOOTHDEVICEINFO_H
#define UI_BLUETHOOTHDEVICEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BluethoothDeviceInfo
{
public:
    QWidget *dockWidgetContents;
    QLabel *name;
    QLabel *address;
    QPushButton *pushButton;

    void setupUi(QDockWidget *BluethoothDeviceInfo)
    {
        if (BluethoothDeviceInfo->objectName().isEmpty())
            BluethoothDeviceInfo->setObjectName(QString::fromUtf8("BluethoothDeviceInfo"));
        BluethoothDeviceInfo->setEnabled(true);
        BluethoothDeviceInfo->resize(515, 145);
        BluethoothDeviceInfo->setFloating(false);
        BluethoothDeviceInfo->setFeatures(QDockWidget::NoDockWidgetFeatures);
        BluethoothDeviceInfo->setAllowedAreas(Qt::NoDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        name = new QLabel(dockWidgetContents);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(0, 0, 511, 31));
        QFont font;
        font.setPointSize(14);
        name->setFont(font);
        name->setFrameShape(QFrame::NoFrame);
        name->setScaledContents(false);
        name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        address = new QLabel(dockWidgetContents);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(0, 30, 511, 21));
        QFont font1;
        font1.setPointSize(10);
        address->setFont(font1);
        address->setScaledContents(false);
        address->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 70, 101, 41));
        BluethoothDeviceInfo->setWidget(dockWidgetContents);

        retranslateUi(BluethoothDeviceInfo);

        QMetaObject::connectSlotsByName(BluethoothDeviceInfo);
    } // setupUi

    void retranslateUi(QDockWidget *BluethoothDeviceInfo)
    {
        BluethoothDeviceInfo->setWindowTitle(QCoreApplication::translate("BluethoothDeviceInfo", "DockWidget", nullptr));
        name->setText(QCoreApplication::translate("BluethoothDeviceInfo", "Device Name", nullptr));
        address->setText(QCoreApplication::translate("BluethoothDeviceInfo", "Device Name", nullptr));
        pushButton->setText(QCoreApplication::translate("BluethoothDeviceInfo", "Force Sleep", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BluethoothDeviceInfo: public Ui_BluethoothDeviceInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETHOOTHDEVICEINFO_H
