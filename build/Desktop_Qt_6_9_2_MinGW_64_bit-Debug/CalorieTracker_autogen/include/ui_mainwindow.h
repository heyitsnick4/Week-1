/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QPushButton *B_home;
    QStackedWidget *stackedWidget;
    QWidget *p1;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_8;
    QPushButton *B_exit;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *B_edit;
    QLabel *Title;
    QPushButton *B_days;
    QPushButton *B_calculate;
    QWidget *p2;
    QGridLayout *gridLayout_6;
    QListView *calcMenuList;
    QGridLayout *gridLayout_5;
    QLabel *caloriesTotalText;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonSubtract;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QWidget *p3;
    QGridLayout *gridLayout_7;
    QListView *editMenuList;
    QGridLayout *gridLayout;
    QPushButton *pushButtonSave;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *lineEditCalories;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonRemove;
    QLineEdit *lineEditName;
    QSpacerItem *verticalSpacer_2;
    QWidget *p4;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_9;
    QListView *dailyTrackerList;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(545, 471);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        B_home = new QPushButton(centralwidget);
        B_home->setObjectName("B_home");

        gridLayout_3->addWidget(B_home, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        p1 = new QWidget();
        p1->setObjectName("p1");
        gridLayout_4 = new QGridLayout(p1);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName("gridLayout_8");
        B_exit = new QPushButton(p1);
        B_exit->setObjectName("B_exit");

        gridLayout_8->addWidget(B_exit, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_8->addItem(verticalSpacer_6, 5, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        B_edit = new QPushButton(p1);
        B_edit->setObjectName("B_edit");

        gridLayout_8->addWidget(B_edit, 2, 1, 1, 1);

        Title = new QLabel(p1);
        Title->setObjectName("Title");
        QFont font;
        font.setPointSize(24);
        Title->setFont(font);

        gridLayout_8->addWidget(Title, 0, 1, 1, 1);

        B_days = new QPushButton(p1);
        B_days->setObjectName("B_days");

        gridLayout_8->addWidget(B_days, 3, 1, 1, 1);

        B_calculate = new QPushButton(p1);
        B_calculate->setObjectName("B_calculate");

        gridLayout_8->addWidget(B_calculate, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_8, 0, 0, 1, 1);

        stackedWidget->addWidget(p1);
        p2 = new QWidget();
        p2->setObjectName("p2");
        gridLayout_6 = new QGridLayout(p2);
        gridLayout_6->setObjectName("gridLayout_6");
        calcMenuList = new QListView(p2);
        calcMenuList->setObjectName("calcMenuList");

        gridLayout_6->addWidget(calcMenuList, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        caloriesTotalText = new QLabel(p2);
        caloriesTotalText->setObjectName("caloriesTotalText");

        gridLayout_5->addWidget(caloriesTotalText, 1, 1, 1, 1);

        pushButtonAdd = new QPushButton(p2);
        pushButtonAdd->setObjectName("pushButtonAdd");

        gridLayout_5->addWidget(pushButtonAdd, 1, 0, 1, 1);

        pushButtonSubtract = new QPushButton(p2);
        pushButtonSubtract->setObjectName("pushButtonSubtract");

        gridLayout_5->addWidget(pushButtonSubtract, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_5->addItem(verticalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 1, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 1, 1, 1);

        stackedWidget->addWidget(p2);
        p3 = new QWidget();
        p3->setObjectName("p3");
        gridLayout_7 = new QGridLayout(p3);
        gridLayout_7->setObjectName("gridLayout_7");
        editMenuList = new QListView(p3);
        editMenuList->setObjectName("editMenuList");

        gridLayout_7->addWidget(editMenuList, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButtonSave = new QPushButton(p3);
        pushButtonSave->setObjectName("pushButtonSave");

        gridLayout->addWidget(pushButtonSave, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 4, 1, 1, 1);

        lineEditCalories = new QLineEdit(p3);
        lineEditCalories->setObjectName("lineEditCalories");

        gridLayout->addWidget(lineEditCalories, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        pushButtonRemove = new QPushButton(p3);
        pushButtonRemove->setObjectName("pushButtonRemove");

        gridLayout->addWidget(pushButtonRemove, 3, 1, 1, 1);

        lineEditName = new QLineEdit(p3);
        lineEditName->setObjectName("lineEditName");

        gridLayout->addWidget(lineEditName, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout, 0, 2, 1, 1);

        stackedWidget->addWidget(p3);
        p4 = new QWidget();
        p4->setObjectName("p4");
        gridLayout_10 = new QGridLayout(p4);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName("gridLayout_9");
        dailyTrackerList = new QListView(p4);
        dailyTrackerList->setObjectName("dailyTrackerList");

        gridLayout_9->addWidget(dailyTrackerList, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 0, 0, 1, 1);

        stackedWidget->addWidget(p4);

        gridLayout_3->addWidget(stackedWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        B_home->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        B_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        B_edit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        Title->setText(QCoreApplication::translate("MainWindow", "Calorie Tracker", nullptr));
        B_days->setText(QCoreApplication::translate("MainWindow", "Days", nullptr));
        B_calculate->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        caloriesTotalText->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButtonSubtract->setText(QCoreApplication::translate("MainWindow", "Subtract", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButtonRemove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
