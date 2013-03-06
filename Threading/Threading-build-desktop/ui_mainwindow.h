/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 28. Feb 11:37:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_COM;
    QAction *action_2;
    QAction *action_3;
    QAction *action_5;
    QWidget *centralWidget;
    QGroupBox *groupBox_3;
    QTableWidget *tableWidget;
    QCheckBox *checkBox;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QGroupBox *groupBox_7;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QSpinBox *spinBox;
    QLabel *label_32;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QGroupBox *groupBox;
    QGroupBox *groupBox_5;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_17;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QGroupBox *groupBox_6;
    QCheckBox *checkBox_18;
    QCheckBox *checkBox_19;
    QCheckBox *checkBox_20;
    QCheckBox *checkBox_21;
    QCheckBox *checkBox_22;
    QCheckBox *checkBox_23;
    QCheckBox *checkBox_24;
    QCheckBox *checkBox_25;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_3;
    QMenu *menuI2C;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1000, 700));
        MainWindow->setMaximumSize(QSize(1000, 700));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferDefault);
        MainWindow->setFont(font);
        action_COM = new QAction(MainWindow);
        action_COM->setObjectName(QString::fromUtf8("action_COM"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(280, 10, 711, 311));
        tableWidget = new QTableWidget(groupBox_3);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 691, 211));
        tableWidget->setMouseTracking(false);
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setFrameShadow(QFrame::Raised);
        tableWidget->setTabKeyNavigation(true);
        tableWidget->setProperty("showDropIndicator", QVariant(true));
        tableWidget->setDragEnabled(false);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(9);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(20);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 250, 91, 18));
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 240, 171, 61));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 20, 16, 18));
        checkBox_2->setCheckable(true);
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(30, 20, 16, 18));
        checkBox_3->setCheckable(true);
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(50, 20, 16, 18));
        checkBox_4->setCheckable(true);
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(70, 20, 16, 18));
        checkBox_5->setCheckable(true);
        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(90, 20, 16, 18));
        checkBox_6->setCheckable(true);
        checkBox_7 = new QCheckBox(groupBox_2);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(110, 20, 16, 18));
        checkBox_7->setCheckable(true);
        checkBox_8 = new QCheckBox(groupBox_2);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(130, 20, 16, 18));
        checkBox_8->setCheckable(true);
        checkBox_9 = new QCheckBox(groupBox_2);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(150, 20, 16, 18));
        checkBox_9->setCheckable(true);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 40, 16, 16));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 40, 16, 16));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 40, 16, 16));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(50, 40, 16, 16));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(70, 40, 16, 16));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(90, 40, 16, 16));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(110, 40, 16, 16));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(130, 40, 16, 16));
        groupBox_7 = new QGroupBox(groupBox_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(510, 240, 191, 61));
        label_28 = new QLabel(groupBox_7);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 20, 46, 13));
        label_29 = new QLabel(groupBox_7);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(10, 40, 46, 13));
        label_30 = new QLabel(groupBox_7);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(120, 20, 46, 13));
        label_31 = new QLabel(groupBox_7);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(120, 40, 46, 13));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 280, 61, 22));
        spinBox->setMinimum(100);
        spinBox->setMaximum(1000);
        spinBox->setSingleStep(100);
        label_32 = new QLabel(groupBox_3);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(90, 280, 101, 16));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setEnabled(true);
        groupBox_4->setGeometry(QRect(10, 10, 261, 121));
        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 90, 71, 21));
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 51, 16));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 51, 16));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 60, 51, 16));
        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 20, 161, 20));
        lineEdit_2->setMaxLength(20);
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(90, 40, 161, 20));
        lineEdit_3->setMaxLength(40);
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(groupBox_4);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(90, 60, 161, 20));
        lineEdit_4->setMaxLength(5);
        lineEdit_4->setReadOnly(true);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 140, 261, 181));
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 20, 171, 61));
        checkBox_10 = new QCheckBox(groupBox_5);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setGeometry(QRect(10, 20, 16, 18));
        checkBox_11 = new QCheckBox(groupBox_5);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setGeometry(QRect(30, 20, 16, 18));
        checkBox_12 = new QCheckBox(groupBox_5);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        checkBox_12->setGeometry(QRect(50, 20, 16, 18));
        checkBox_13 = new QCheckBox(groupBox_5);
        checkBox_13->setObjectName(QString::fromUtf8("checkBox_13"));
        checkBox_13->setGeometry(QRect(70, 20, 16, 18));
        checkBox_14 = new QCheckBox(groupBox_5);
        checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));
        checkBox_14->setGeometry(QRect(90, 20, 16, 18));
        checkBox_15 = new QCheckBox(groupBox_5);
        checkBox_15->setObjectName(QString::fromUtf8("checkBox_15"));
        checkBox_15->setGeometry(QRect(110, 20, 16, 18));
        checkBox_16 = new QCheckBox(groupBox_5);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));
        checkBox_16->setGeometry(QRect(130, 20, 16, 18));
        checkBox_17 = new QCheckBox(groupBox_5);
        checkBox_17->setObjectName(QString::fromUtf8("checkBox_17"));
        checkBox_17->setGeometry(QRect(150, 20, 16, 18));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 40, 16, 16));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 40, 16, 16));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(130, 40, 16, 16));
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(50, 40, 16, 16));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(90, 40, 16, 16));
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(70, 40, 16, 16));
        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(30, 40, 16, 16));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(110, 40, 16, 16));
        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 80, 171, 61));
        checkBox_18 = new QCheckBox(groupBox_6);
        checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));
        checkBox_18->setGeometry(QRect(10, 20, 16, 18));
        checkBox_19 = new QCheckBox(groupBox_6);
        checkBox_19->setObjectName(QString::fromUtf8("checkBox_19"));
        checkBox_19->setGeometry(QRect(30, 20, 16, 18));
        checkBox_20 = new QCheckBox(groupBox_6);
        checkBox_20->setObjectName(QString::fromUtf8("checkBox_20"));
        checkBox_20->setGeometry(QRect(50, 20, 16, 18));
        checkBox_21 = new QCheckBox(groupBox_6);
        checkBox_21->setObjectName(QString::fromUtf8("checkBox_21"));
        checkBox_21->setGeometry(QRect(70, 20, 16, 18));
        checkBox_22 = new QCheckBox(groupBox_6);
        checkBox_22->setObjectName(QString::fromUtf8("checkBox_22"));
        checkBox_22->setGeometry(QRect(90, 20, 16, 18));
        checkBox_23 = new QCheckBox(groupBox_6);
        checkBox_23->setObjectName(QString::fromUtf8("checkBox_23"));
        checkBox_23->setGeometry(QRect(110, 20, 16, 18));
        checkBox_24 = new QCheckBox(groupBox_6);
        checkBox_24->setObjectName(QString::fromUtf8("checkBox_24"));
        checkBox_24->setGeometry(QRect(130, 20, 16, 18));
        checkBox_25 = new QCheckBox(groupBox_6);
        checkBox_25->setObjectName(QString::fromUtf8("checkBox_25"));
        checkBox_25->setGeometry(QRect(150, 20, 16, 18));
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(150, 40, 16, 16));
        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 40, 16, 16));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(130, 40, 16, 16));
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(50, 40, 16, 16));
        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(90, 40, 16, 16));
        label_25 = new QLabel(groupBox_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(70, 40, 16, 16));
        label_26 = new QLabel(groupBox_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(30, 40, 16, 16));
        label_27 = new QLabel(groupBox_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(110, 40, 16, 16));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 150, 71, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 18));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menuI2C = new QMenu(menuBar);
        menuI2C->setObjectName(QString::fromUtf8("menuI2C"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuI2C->menuAction());
        menu->addAction(action_COM);
        menu->addAction(action_5);
        menu_3->addAction(action_2);
        menuI2C->addAction(action_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\223\320\225\320\236-2005 \320\242\320\225\320\241\320\242", 0, QApplication::UnicodeUTF8));
        action_COM->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 COM \320\277\320\276\321\200\321\202\320\260", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        action_3->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        action_5->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\272\320\260\320\275\320\260\320\273\320\276\320\262", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273\321\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "\320\241\320\261\320\276\321\200 \320\264\320\260\320\275\320\275\321\213\321\205", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\320\275\320\276\320\271 \321\200\320\265\320\263\320\270\321\201\321\202\321\200", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QString());
        checkBox_3->setText(QString());
        checkBox_4->setText(QString());
        checkBox_5->setText(QString());
        checkBox_6->setText(QString());
        checkBox_7->setText(QString());
        checkBox_8->setText(QString());
        checkBox_9->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\270", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\271\320\274\320\260\321\203\321\202", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "CRC", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264 \320\276\320\277\321\200\320\276\321\201\320\260 (\320\274\321\201)", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\201\320\270\321\217", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\276\320\262", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264\320\275\320\276\320\271 1", 0, QApplication::UnicodeUTF8));
        checkBox_10->setText(QString());
        checkBox_11->setText(QString());
        checkBox_12->setText(QString());
        checkBox_13->setText(QString());
        checkBox_14->setText(QString());
        checkBox_15->setText(QString());
        checkBox_16->setText(QString());
        checkBox_17->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264\320\275\320\276\320\271 2", 0, QApplication::UnicodeUTF8));
        checkBox_18->setText(QString());
        checkBox_19->setText(QString());
        checkBox_20->setText(QString());
        checkBox_21->setText(QString());
        checkBox_22->setText(QString());
        checkBox_23->setText(QString());
        checkBox_24->setText(QString());
        checkBox_25->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        menuI2C->setTitle(QApplication::translate("MainWindow", "I2C \320\247\320\260\321\201\321\213/\320\277\320\260\320\274\321\217\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
