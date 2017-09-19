/********************************************************************************
** Form generated from reading UI file 'Calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLineEdit *express_lineEdit;
    QGridLayout *gridLayout;
    QPushButton *rank;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *clear;
    QPushButton *sin;
    QPushButton *lBracket;
    QPushButton *rBracket;
    QPushButton *pushButton_5;
    QPushButton *backSpace;
    QPushButton *cos;
    QPushButton *seven;
    QPushButton *eight;
    QPushButton *nine;
    QPushButton *operDivide_pushButton;
    QPushButton *tan;
    QPushButton *four;
    QPushButton *five;
    QPushButton *six;
    QPushButton *operMultiply_pushButton;
    QPushButton *ln;
    QPushButton *one;
    QPushButton *two;
    QPushButton *three;
    QPushButton *operSubtract_pushButton;
    QPushButton *log;
    QPushButton *zero;
    QPushButton *point_pushButton;
    QPushButton *result_pushButton;
    QPushButton *operAdd_pushButton;
    QHBoxLayout *horizontalLayout;
    QLineEdit *result_lineEdit;
    QPushButton *pushButton_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CalculatorClass)
    {
        if (CalculatorClass->objectName().isEmpty())
            CalculatorClass->setObjectName(QStringLiteral("CalculatorClass"));
        CalculatorClass->resize(471, 630);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalculatorClass->sizePolicy().hasHeightForWidth());
        CalculatorClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(CalculatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        express_lineEdit = new QLineEdit(centralWidget);
        express_lineEdit->setObjectName(QStringLiteral("express_lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(express_lineEdit->sizePolicy().hasHeightForWidth());
        express_lineEdit->setSizePolicy(sizePolicy1);
        express_lineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"	font: 16pt \"Arial\";\n"
"}"));
        express_lineEdit->setFrame(false);

        gridLayout_2->addWidget(express_lineEdit, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rank = new QPushButton(centralWidget);
        rank->setObjectName(QStringLiteral("rank"));
        sizePolicy1.setHeightForWidth(rank->sizePolicy().hasHeightForWidth());
        rank->setSizePolicy(sizePolicy1);
        rank->setMinimumSize(QSize(45, 45));
        rank->setMaximumSize(QSize(45, 45));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Handwriting"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        rank->setFont(font);
        rank->setIconSize(QSize(26, 26));
        rank->setFlat(true);

        gridLayout->addWidget(rank, 0, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(45, 45));
        pushButton->setMaximumSize(QSize(45, 45));
        pushButton->setFont(font);
        pushButton->setIconSize(QSize(26, 26));
        pushButton->setFlat(true);

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(45, 45));
        pushButton_3->setMaximumSize(QSize(45, 45));
        pushButton_3->setFont(font);
        pushButton_3->setIconSize(QSize(26, 26));
        pushButton_3->setFlat(true);

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(45, 45));
        pushButton_2->setMaximumSize(QSize(45, 45));
        pushButton_2->setFont(font);
        pushButton_2->setIconSize(QSize(26, 26));
        pushButton_2->setFlat(true);

        gridLayout->addWidget(pushButton_2, 0, 3, 1, 1);

        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));
        sizePolicy1.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy1);
        clear->setMinimumSize(QSize(45, 45));
        clear->setMaximumSize(QSize(45, 45));
        clear->setFont(font);
        clear->setIconSize(QSize(26, 26));
        clear->setFlat(true);

        gridLayout->addWidget(clear, 0, 4, 1, 1);

        sin = new QPushButton(centralWidget);
        sin->setObjectName(QStringLiteral("sin"));
        sizePolicy1.setHeightForWidth(sin->sizePolicy().hasHeightForWidth());
        sin->setSizePolicy(sizePolicy1);
        sin->setMinimumSize(QSize(45, 45));
        sin->setMaximumSize(QSize(45, 45));
        sin->setFont(font);
        sin->setIconSize(QSize(26, 26));
        sin->setFlat(true);

        gridLayout->addWidget(sin, 1, 0, 1, 1);

        lBracket = new QPushButton(centralWidget);
        lBracket->setObjectName(QStringLiteral("lBracket"));
        sizePolicy1.setHeightForWidth(lBracket->sizePolicy().hasHeightForWidth());
        lBracket->setSizePolicy(sizePolicy1);
        lBracket->setMinimumSize(QSize(45, 45));
        lBracket->setMaximumSize(QSize(45, 45));
        lBracket->setFont(font);
        lBracket->setIconSize(QSize(26, 26));
        lBracket->setFlat(true);

        gridLayout->addWidget(lBracket, 1, 1, 1, 1);

        rBracket = new QPushButton(centralWidget);
        rBracket->setObjectName(QStringLiteral("rBracket"));
        sizePolicy1.setHeightForWidth(rBracket->sizePolicy().hasHeightForWidth());
        rBracket->setSizePolicy(sizePolicy1);
        rBracket->setMinimumSize(QSize(45, 45));
        rBracket->setMaximumSize(QSize(45, 45));
        rBracket->setFont(font);
        rBracket->setIconSize(QSize(26, 26));
        rBracket->setFlat(true);

        gridLayout->addWidget(rBracket, 1, 2, 1, 1);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMinimumSize(QSize(45, 45));
        pushButton_5->setMaximumSize(QSize(45, 45));
        pushButton_5->setFont(font);
        pushButton_5->setIconSize(QSize(26, 26));
        pushButton_5->setFlat(true);

        gridLayout->addWidget(pushButton_5, 1, 3, 1, 1);

        backSpace = new QPushButton(centralWidget);
        backSpace->setObjectName(QStringLiteral("backSpace"));
        sizePolicy1.setHeightForWidth(backSpace->sizePolicy().hasHeightForWidth());
        backSpace->setSizePolicy(sizePolicy1);
        backSpace->setMinimumSize(QSize(45, 45));
        backSpace->setMaximumSize(QSize(45, 45));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Handwriting"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        backSpace->setFont(font1);
        backSpace->setIconSize(QSize(26, 26));
        backSpace->setFlat(true);

        gridLayout->addWidget(backSpace, 1, 4, 1, 1);

        cos = new QPushButton(centralWidget);
        cos->setObjectName(QStringLiteral("cos"));
        sizePolicy1.setHeightForWidth(cos->sizePolicy().hasHeightForWidth());
        cos->setSizePolicy(sizePolicy1);
        cos->setMinimumSize(QSize(45, 45));
        cos->setMaximumSize(QSize(45, 45));
        cos->setFont(font);
        cos->setIconSize(QSize(26, 26));
        cos->setFlat(true);

        gridLayout->addWidget(cos, 2, 0, 1, 1);

        seven = new QPushButton(centralWidget);
        seven->setObjectName(QStringLiteral("seven"));
        sizePolicy1.setHeightForWidth(seven->sizePolicy().hasHeightForWidth());
        seven->setSizePolicy(sizePolicy1);
        seven->setMinimumSize(QSize(45, 45));
        seven->setMaximumSize(QSize(45, 45));
        seven->setFont(font);
        seven->setIconSize(QSize(26, 26));
        seven->setFlat(true);

        gridLayout->addWidget(seven, 2, 1, 1, 1);

        eight = new QPushButton(centralWidget);
        eight->setObjectName(QStringLiteral("eight"));
        sizePolicy1.setHeightForWidth(eight->sizePolicy().hasHeightForWidth());
        eight->setSizePolicy(sizePolicy1);
        eight->setMinimumSize(QSize(45, 45));
        eight->setMaximumSize(QSize(45, 45));
        eight->setFont(font);
        eight->setIconSize(QSize(26, 26));
        eight->setFlat(true);

        gridLayout->addWidget(eight, 2, 2, 1, 1);

        nine = new QPushButton(centralWidget);
        nine->setObjectName(QStringLiteral("nine"));
        sizePolicy1.setHeightForWidth(nine->sizePolicy().hasHeightForWidth());
        nine->setSizePolicy(sizePolicy1);
        nine->setMinimumSize(QSize(45, 45));
        nine->setMaximumSize(QSize(45, 45));
        nine->setFont(font);
        nine->setIconSize(QSize(26, 26));
        nine->setFlat(true);

        gridLayout->addWidget(nine, 2, 3, 1, 1);

        operDivide_pushButton = new QPushButton(centralWidget);
        operDivide_pushButton->setObjectName(QStringLiteral("operDivide_pushButton"));
        sizePolicy1.setHeightForWidth(operDivide_pushButton->sizePolicy().hasHeightForWidth());
        operDivide_pushButton->setSizePolicy(sizePolicy1);
        operDivide_pushButton->setMinimumSize(QSize(45, 45));
        operDivide_pushButton->setMaximumSize(QSize(45, 45));
        operDivide_pushButton->setFont(font);
        operDivide_pushButton->setIconSize(QSize(26, 26));
        operDivide_pushButton->setFlat(true);

        gridLayout->addWidget(operDivide_pushButton, 2, 4, 1, 1);

        tan = new QPushButton(centralWidget);
        tan->setObjectName(QStringLiteral("tan"));
        sizePolicy1.setHeightForWidth(tan->sizePolicy().hasHeightForWidth());
        tan->setSizePolicy(sizePolicy1);
        tan->setMinimumSize(QSize(45, 45));
        tan->setMaximumSize(QSize(45, 45));
        tan->setFont(font1);
        tan->setIconSize(QSize(26, 26));
        tan->setFlat(true);

        gridLayout->addWidget(tan, 3, 0, 1, 1);

        four = new QPushButton(centralWidget);
        four->setObjectName(QStringLiteral("four"));
        sizePolicy1.setHeightForWidth(four->sizePolicy().hasHeightForWidth());
        four->setSizePolicy(sizePolicy1);
        four->setMinimumSize(QSize(45, 45));
        four->setMaximumSize(QSize(45, 45));
        four->setFont(font);
        four->setIconSize(QSize(26, 26));
        four->setFlat(true);

        gridLayout->addWidget(four, 3, 1, 1, 1);

        five = new QPushButton(centralWidget);
        five->setObjectName(QStringLiteral("five"));
        sizePolicy1.setHeightForWidth(five->sizePolicy().hasHeightForWidth());
        five->setSizePolicy(sizePolicy1);
        five->setMinimumSize(QSize(45, 45));
        five->setMaximumSize(QSize(45, 45));
        five->setFont(font);
        five->setIconSize(QSize(26, 26));
        five->setFlat(true);

        gridLayout->addWidget(five, 3, 2, 1, 1);

        six = new QPushButton(centralWidget);
        six->setObjectName(QStringLiteral("six"));
        sizePolicy1.setHeightForWidth(six->sizePolicy().hasHeightForWidth());
        six->setSizePolicy(sizePolicy1);
        six->setMinimumSize(QSize(45, 45));
        six->setMaximumSize(QSize(45, 45));
        six->setFont(font);
        six->setIconSize(QSize(26, 26));
        six->setFlat(true);

        gridLayout->addWidget(six, 3, 3, 1, 1);

        operMultiply_pushButton = new QPushButton(centralWidget);
        operMultiply_pushButton->setObjectName(QStringLiteral("operMultiply_pushButton"));
        sizePolicy1.setHeightForWidth(operMultiply_pushButton->sizePolicy().hasHeightForWidth());
        operMultiply_pushButton->setSizePolicy(sizePolicy1);
        operMultiply_pushButton->setMinimumSize(QSize(45, 45));
        operMultiply_pushButton->setMaximumSize(QSize(45, 45));
        operMultiply_pushButton->setFont(font);
        operMultiply_pushButton->setIconSize(QSize(26, 26));
        operMultiply_pushButton->setFlat(true);

        gridLayout->addWidget(operMultiply_pushButton, 3, 4, 1, 1);

        ln = new QPushButton(centralWidget);
        ln->setObjectName(QStringLiteral("ln"));
        sizePolicy1.setHeightForWidth(ln->sizePolicy().hasHeightForWidth());
        ln->setSizePolicy(sizePolicy1);
        ln->setMinimumSize(QSize(45, 45));
        ln->setMaximumSize(QSize(45, 45));
        ln->setFont(font);
        ln->setIconSize(QSize(26, 26));
        ln->setFlat(true);

        gridLayout->addWidget(ln, 4, 0, 1, 1);

        one = new QPushButton(centralWidget);
        one->setObjectName(QStringLiteral("one"));
        sizePolicy1.setHeightForWidth(one->sizePolicy().hasHeightForWidth());
        one->setSizePolicy(sizePolicy1);
        one->setMinimumSize(QSize(45, 45));
        one->setMaximumSize(QSize(45, 45));
        one->setFont(font);
        one->setIconSize(QSize(26, 26));
        one->setFlat(true);

        gridLayout->addWidget(one, 4, 1, 1, 1);

        two = new QPushButton(centralWidget);
        two->setObjectName(QStringLiteral("two"));
        sizePolicy1.setHeightForWidth(two->sizePolicy().hasHeightForWidth());
        two->setSizePolicy(sizePolicy1);
        two->setMinimumSize(QSize(45, 45));
        two->setMaximumSize(QSize(45, 45));
        two->setFont(font);
        two->setIconSize(QSize(26, 26));
        two->setFlat(true);

        gridLayout->addWidget(two, 4, 2, 1, 1);

        three = new QPushButton(centralWidget);
        three->setObjectName(QStringLiteral("three"));
        sizePolicy1.setHeightForWidth(three->sizePolicy().hasHeightForWidth());
        three->setSizePolicy(sizePolicy1);
        three->setMinimumSize(QSize(45, 45));
        three->setMaximumSize(QSize(45, 45));
        three->setFont(font);
        three->setIconSize(QSize(26, 26));
        three->setFlat(true);

        gridLayout->addWidget(three, 4, 3, 1, 1);

        operSubtract_pushButton = new QPushButton(centralWidget);
        operSubtract_pushButton->setObjectName(QStringLiteral("operSubtract_pushButton"));
        sizePolicy1.setHeightForWidth(operSubtract_pushButton->sizePolicy().hasHeightForWidth());
        operSubtract_pushButton->setSizePolicy(sizePolicy1);
        operSubtract_pushButton->setMinimumSize(QSize(45, 45));
        operSubtract_pushButton->setMaximumSize(QSize(45, 45));
        operSubtract_pushButton->setFont(font);
        operSubtract_pushButton->setIconSize(QSize(26, 26));
        operSubtract_pushButton->setFlat(true);

        gridLayout->addWidget(operSubtract_pushButton, 4, 4, 1, 1);

        log = new QPushButton(centralWidget);
        log->setObjectName(QStringLiteral("log"));
        sizePolicy1.setHeightForWidth(log->sizePolicy().hasHeightForWidth());
        log->setSizePolicy(sizePolicy1);
        log->setMinimumSize(QSize(45, 45));
        log->setMaximumSize(QSize(45, 45));
        log->setFont(font);
        log->setIconSize(QSize(26, 26));
        log->setFlat(true);

        gridLayout->addWidget(log, 5, 0, 1, 1);

        zero = new QPushButton(centralWidget);
        zero->setObjectName(QStringLiteral("zero"));
        sizePolicy1.setHeightForWidth(zero->sizePolicy().hasHeightForWidth());
        zero->setSizePolicy(sizePolicy1);
        zero->setMinimumSize(QSize(45, 45));
        zero->setMaximumSize(QSize(45, 45));
        zero->setFont(font);
        zero->setIconSize(QSize(26, 26));
        zero->setFlat(true);

        gridLayout->addWidget(zero, 5, 1, 1, 1);

        point_pushButton = new QPushButton(centralWidget);
        point_pushButton->setObjectName(QStringLiteral("point_pushButton"));
        sizePolicy1.setHeightForWidth(point_pushButton->sizePolicy().hasHeightForWidth());
        point_pushButton->setSizePolicy(sizePolicy1);
        point_pushButton->setMinimumSize(QSize(45, 45));
        point_pushButton->setMaximumSize(QSize(45, 45));
        point_pushButton->setFont(font);
        point_pushButton->setIconSize(QSize(26, 26));
        point_pushButton->setFlat(true);

        gridLayout->addWidget(point_pushButton, 5, 2, 1, 1);

        result_pushButton = new QPushButton(centralWidget);
        result_pushButton->setObjectName(QStringLiteral("result_pushButton"));
        sizePolicy1.setHeightForWidth(result_pushButton->sizePolicy().hasHeightForWidth());
        result_pushButton->setSizePolicy(sizePolicy1);
        result_pushButton->setMinimumSize(QSize(45, 45));
        result_pushButton->setMaximumSize(QSize(45, 45));
        result_pushButton->setFont(font);
        result_pushButton->setIconSize(QSize(26, 26));
        result_pushButton->setFlat(true);

        gridLayout->addWidget(result_pushButton, 5, 3, 1, 1);

        operAdd_pushButton = new QPushButton(centralWidget);
        operAdd_pushButton->setObjectName(QStringLiteral("operAdd_pushButton"));
        sizePolicy1.setHeightForWidth(operAdd_pushButton->sizePolicy().hasHeightForWidth());
        operAdd_pushButton->setSizePolicy(sizePolicy1);
        operAdd_pushButton->setMinimumSize(QSize(45, 45));
        operAdd_pushButton->setMaximumSize(QSize(45, 45));
        operAdd_pushButton->setFont(font);
        operAdd_pushButton->setIconSize(QSize(26, 26));
        operAdd_pushButton->setFlat(true);

        gridLayout->addWidget(operAdd_pushButton, 5, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        result_lineEdit = new QLineEdit(centralWidget);
        result_lineEdit->setObjectName(QStringLiteral("result_lineEdit"));
        sizePolicy1.setHeightForWidth(result_lineEdit->sizePolicy().hasHeightForWidth());
        result_lineEdit->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        result_lineEdit->setFont(font2);
        result_lineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"font: 16pt \"Arial\";\n"
"}"));
        result_lineEdit->setFrame(false);
        result_lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(result_lineEdit);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMinimumSize(QSize(81, 23));
        pushButton_4->setMaximumSize(QSize(81, 23));
        QFont font3;
        font3.setFamily(QStringLiteral("Lucida Handwriting"));
        font3.setPointSize(10);
        pushButton_4->setFont(font3);
        pushButton_4->setIconSize(QSize(30, 30));
        pushButton_4->setFlat(true);

        horizontalLayout->addWidget(pushButton_4);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        CalculatorClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(CalculatorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CalculatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CalculatorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CalculatorClass->setStatusBar(statusBar);

        retranslateUi(CalculatorClass);

        QMetaObject::connectSlotsByName(CalculatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *CalculatorClass)
    {
        CalculatorClass->setWindowTitle(QApplication::translate("CalculatorClass", "Calculator", Q_NULLPTR));
        rank->setText(QApplication::translate("CalculatorClass", "!", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CalculatorClass", "^", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("CalculatorClass", "\342\210\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("CalculatorClass", "\342\210\217", Q_NULLPTR));
        clear->setText(QApplication::translate("CalculatorClass", "C", Q_NULLPTR));
        sin->setText(QApplication::translate("CalculatorClass", "sin", Q_NULLPTR));
        lBracket->setText(QApplication::translate("CalculatorClass", "(", Q_NULLPTR));
        rBracket->setText(QApplication::translate("CalculatorClass", ")", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("CalculatorClass", "e", Q_NULLPTR));
        backSpace->setText(QApplication::translate("CalculatorClass", "DEL", Q_NULLPTR));
        cos->setText(QApplication::translate("CalculatorClass", "cos", Q_NULLPTR));
        seven->setText(QApplication::translate("CalculatorClass", "7", Q_NULLPTR));
        eight->setText(QApplication::translate("CalculatorClass", "8", Q_NULLPTR));
        nine->setText(QApplication::translate("CalculatorClass", "9", Q_NULLPTR));
        operDivide_pushButton->setText(QApplication::translate("CalculatorClass", "\303\267", Q_NULLPTR));
        tan->setText(QApplication::translate("CalculatorClass", "tan", Q_NULLPTR));
        four->setText(QApplication::translate("CalculatorClass", "4", Q_NULLPTR));
        five->setText(QApplication::translate("CalculatorClass", "5", Q_NULLPTR));
        six->setText(QApplication::translate("CalculatorClass", "6", Q_NULLPTR));
        operMultiply_pushButton->setText(QApplication::translate("CalculatorClass", "*", Q_NULLPTR));
        ln->setText(QApplication::translate("CalculatorClass", "ln", Q_NULLPTR));
        one->setText(QApplication::translate("CalculatorClass", "1", Q_NULLPTR));
        two->setText(QApplication::translate("CalculatorClass", "2", Q_NULLPTR));
        three->setText(QApplication::translate("CalculatorClass", "3", Q_NULLPTR));
        operSubtract_pushButton->setText(QApplication::translate("CalculatorClass", "-", Q_NULLPTR));
        log->setText(QApplication::translate("CalculatorClass", "log", Q_NULLPTR));
        zero->setText(QApplication::translate("CalculatorClass", "0", Q_NULLPTR));
        point_pushButton->setText(QApplication::translate("CalculatorClass", ".", Q_NULLPTR));
        result_pushButton->setText(QApplication::translate("CalculatorClass", "=", Q_NULLPTR));
        operAdd_pushButton->setText(QApplication::translate("CalculatorClass", "+", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("CalculatorClass", "trans", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalculatorClass: public Ui_CalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
