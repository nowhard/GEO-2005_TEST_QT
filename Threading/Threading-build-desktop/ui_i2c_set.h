/********************************************************************************
** Form generated from reading UI file 'i2c_set.ui'
**
** Created: Thu 28. Feb 11:37:47 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_I2C_SET_H
#define UI_I2C_SET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_I2C_Set
{
public:
    QGroupBox *groupBox;
    QDateTimeEdit *dateTimeEdit;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *pushButton_2;
    QCheckBox *checkBox_17;
    QCheckBox *checkBox_18;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;
    QProgressBar *progressBar;
    QLabel *label_17;
    QLabel *label_18;

    void setupUi(QDialog *I2C_Set)
    {
        if (I2C_Set->objectName().isEmpty())
            I2C_Set->setObjectName(QString::fromUtf8("I2C_Set"));
        I2C_Set->resize(820, 360);
        I2C_Set->setMinimumSize(QSize(820, 360));
        I2C_Set->setMaximumSize(QSize(820, 360));
        groupBox = new QGroupBox(I2C_Set);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 311, 311));
        dateTimeEdit = new QDateTimeEdit(groupBox);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(30, 30, 161, 22));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 60, 161, 22));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 90, 271, 71));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 20, 16, 16));
        QFont font;
        font.setKerning(true);
        checkBox->setFont(font);
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(50, 20, 16, 18));
        checkBox_2->setFont(font);
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(80, 20, 16, 18));
        checkBox_3->setFont(font);
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(110, 20, 16, 18));
        checkBox_4->setFont(font);
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(140, 20, 16, 18));
        checkBox_5->setFont(font);
        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(170, 20, 16, 18));
        checkBox_6->setFont(font);
        checkBox_7 = new QCheckBox(groupBox_2);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(200, 20, 16, 18));
        checkBox_7->setFont(font);
        checkBox_8 = new QCheckBox(groupBox_2);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(230, 20, 16, 18));
        checkBox_8->setFont(font);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 41, 16));
        QFont font1;
        font1.setUnderline(true);
        label->setFont(font1);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 40, 31, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 40, 31, 16));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(200, 40, 31, 16));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(170, 40, 31, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 40, 31, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(110, 40, 31, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(80, 40, 31, 16));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setGeometry(QRect(30, 170, 271, 71));
        checkBox_9 = new QCheckBox(groupBox_3);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setEnabled(true);
        checkBox_9->setGeometry(QRect(20, 20, 16, 16));
        checkBox_9->setFont(font);
        checkBox_10 = new QCheckBox(groupBox_3);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setEnabled(true);
        checkBox_10->setGeometry(QRect(50, 20, 16, 18));
        checkBox_10->setFont(font);
        checkBox_11 = new QCheckBox(groupBox_3);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setEnabled(true);
        checkBox_11->setGeometry(QRect(80, 20, 16, 18));
        checkBox_11->setFont(font);
        checkBox_12 = new QCheckBox(groupBox_3);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        checkBox_12->setEnabled(true);
        checkBox_12->setGeometry(QRect(110, 20, 16, 18));
        checkBox_12->setFont(font);
        checkBox_13 = new QCheckBox(groupBox_3);
        checkBox_13->setObjectName(QString::fromUtf8("checkBox_13"));
        checkBox_13->setEnabled(true);
        checkBox_13->setGeometry(QRect(140, 20, 16, 18));
        checkBox_13->setFont(font);
        checkBox_14 = new QCheckBox(groupBox_3);
        checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));
        checkBox_14->setEnabled(true);
        checkBox_14->setGeometry(QRect(170, 20, 16, 18));
        checkBox_14->setFont(font);
        checkBox_15 = new QCheckBox(groupBox_3);
        checkBox_15->setObjectName(QString::fromUtf8("checkBox_15"));
        checkBox_15->setEnabled(true);
        checkBox_15->setGeometry(QRect(200, 20, 16, 18));
        checkBox_15->setFont(font);
        checkBox_16 = new QCheckBox(groupBox_3);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));
        checkBox_16->setEnabled(true);
        checkBox_16->setGeometry(QRect(230, 20, 16, 18));
        checkBox_16->setFont(font);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 40, 41, 16));
        QFont font2;
        font2.setUnderline(false);
        label_9->setFont(font2);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 40, 31, 16));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(230, 40, 31, 16));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(200, 40, 16, 16));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(170, 40, 31, 16));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(140, 40, 31, 16));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(110, 40, 31, 16));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(80, 40, 16, 16));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 262, 75, 31));
        checkBox_17 = new QCheckBox(groupBox);
        checkBox_17->setObjectName(QString::fromUtf8("checkBox_17"));
        checkBox_17->setGeometry(QRect(20, 270, 101, 18));
        checkBox_18 = new QCheckBox(groupBox);
        checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));
        checkBox_18->setGeometry(QRect(200, 50, 111, 18));
        groupBox_4 = new QGroupBox(I2C_Set);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(330, 10, 481, 311));
        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 270, 75, 31));
        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(390, 270, 75, 31));
        pushButton_4->setCheckable(false);
        pushButton_4->setFlat(false);
        tableWidget = new QTableWidget(groupBox_4);
        if (tableWidget->columnCount() < 32)
            tableWidget->setColumnCount(32);
        if (tableWidget->rowCount() < 1024)
            tableWidget->setRowCount(1024);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 461, 241));
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->setRowCount(1024);
        tableWidget->setColumnCount(32);
        progressBar = new QProgressBar(groupBox_4);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(100, 270, 291, 31));
        progressBar->setValue(0);
        label_17 = new QLabel(I2C_Set);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 330, 81, 16));
        label_18 = new QLabel(I2C_Set);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(110, 330, 21, 16));

        retranslateUi(I2C_Set);

        QMetaObject::connectSlotsByName(I2C_Set);
    } // setupUi

    void retranslateUi(QDialog *I2C_Set)
    {
        I2C_Set->setWindowTitle(QApplication::translate("I2C_Set", "I2C \320\247\320\260\321\201\321\213/\320\237\320\260\320\274\321\217\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("I2C_Set", "\320\232\320\260\320\273\320\265\320\275\320\264\320\260\321\200\321\214", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("I2C_Set", "\320\237\320\276\320\275\320\265\320\264\320\265\320\273\321\214\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("I2C_Set", "\320\222\321\202\320\276\321\200\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("I2C_Set", "\320\241\321\200\320\265\320\264\320\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("I2C_Set", "\320\247\320\265\321\202\320\262\320\265\321\200\320\263", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("I2C_Set", "\320\237\321\217\321\202\320\275\320\270\321\206\320\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("I2C_Set", "\320\241\321\203\320\261\320\261\320\276\321\202\320\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("I2C_Set", "\320\222\320\276\321\201\320\272\321\200\320\265\321\201\320\265\320\275\321\214\320\265", 0, QApplication::UnicodeUTF8)
        );
        groupBox_2->setTitle(QApplication::translate("I2C_Set", "REG 1: CAL\\Control", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        checkBox_2->setText(QString());
        checkBox_3->setText(QString());
        checkBox_4->setText(QString());
        checkBox_5->setText(QString());
        checkBox_6->setText(QString());
        checkBox_7->setText(QString());
        checkBox_8->setText(QString());
        label->setText(QApplication::translate("I2C_Set", "OSCEN", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("I2C_Set", "TSEN", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("I2C_Set", "CAL0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("I2C_Set", "CAL1", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("I2C_Set", "CAL2", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("I2C_Set", "CAL3", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("I2C_Set", "CAL4", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("I2C_Set", "CALS", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("I2C_Set", "REG 0: Flags\\Control", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QString());
        checkBox_10->setText(QString());
        checkBox_11->setText(QString());
        checkBox_12->setText(QString());
        checkBox_13->setText(QString());
        checkBox_14->setText(QString());
        checkBox_15->setText(QString());
        checkBox_16->setText(QString());
        label_9->setText(QApplication::translate("I2C_Set", "Tamper", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("I2C_Set", "CF", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("I2C_Set", "R", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("I2C_Set", "W", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("I2C_Set", "CAL", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("I2C_Set", "TST", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("I2C_Set", "-", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("I2C_Set", "-", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("I2C_Set", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        checkBox_17->setText(QApplication::translate("I2C_Set", "\320\236\320\277\321\200\320\276\321\201 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", 0, QApplication::UnicodeUTF8));
        checkBox_18->setText(QApplication::translate("I2C_Set", "\320\222\320\267\321\217\321\202\321\214 \321\201\320\270\321\201\321\202\320\265\320\274\320\275\321\203\321\216", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("I2C_Set", "\320\237\320\260\320\274\321\217\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("I2C_Set", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("I2C_Set", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("I2C_Set", "\320\236\321\210\320\270\320\261\320\272\320\270 I2C", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("I2C_Set", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class I2C_Set: public Ui_I2C_Set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_I2C_SET_H
