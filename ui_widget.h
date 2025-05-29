/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QLabel *label;
    QSlider *horizontalSliderVolume;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelCurrent;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTotal;
    QSlider *horizontalSlider;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonFore;
    QPushButton *pushButtonPause;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(591, 750);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 373, 651));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName("listWidget");

        gridLayout->addWidget(listWidget, 0, 0, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        horizontalSliderVolume = new QSlider(layoutWidget);
        horizontalSliderVolume->setObjectName("horizontalSliderVolume");
        horizontalSliderVolume->setValue(99);
        horizontalSliderVolume->setOrientation(Qt::Orientation::Horizontal);

        gridLayout->addWidget(horizontalSliderVolume, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelCurrent = new QLabel(layoutWidget);
        labelCurrent->setObjectName("labelCurrent");

        horizontalLayout_2->addWidget(labelCurrent);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labelTotal = new QLabel(layoutWidget);
        labelTotal->setObjectName("labelTotal");

        horizontalLayout_2->addWidget(labelTotal);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 2);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout->addWidget(horizontalSlider, 3, 0, 1, 2);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setFlat(true);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonOpen = new QPushButton(groupBox);
        pushButtonOpen->setObjectName("pushButtonOpen");

        horizontalLayout->addWidget(pushButtonOpen);

        pushButtonFore = new QPushButton(groupBox);
        pushButtonFore->setObjectName("pushButtonFore");

        horizontalLayout->addWidget(pushButtonFore);

        pushButtonPause = new QPushButton(groupBox);
        pushButtonPause->setObjectName("pushButtonPause");

        horizontalLayout->addWidget(pushButtonPause);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout->addWidget(pushButton_4);


        gridLayout->addWidget(groupBox, 4, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\255\214\346\233\262\345\210\227\350\241\250", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\351\237\263\351\207\217\357\274\232", nullptr));
        labelCurrent->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        labelTotal->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        groupBox->setTitle(QString());
        pushButtonOpen->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200", nullptr));
        pushButtonFore->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\246\226", nullptr));
        pushButtonPause->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\246\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
