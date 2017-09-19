/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *result;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *zerop;
    QPushButton *onep;
    QPushButton *twop;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *threep;
    QPushButton *fourp;
    QPushButton *fivep;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *sixp;
    QPushButton *sevenp;
    QPushButton *eightp;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *ninep;
    QPushButton *sevenp_2;
    QPushButton *eightp_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *transition_2;
    QPushButton *transition_16;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(399, 490);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(399, 397));
        QFont font;
        font.setPointSize(6);
        Dialog->setFont(font);
        verticalLayout_3 = new QVBoxLayout(Dialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(8);
        label->setFont(font1);

        horizontalLayout->addWidget(label, 0, Qt::AlignHCenter);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMinimumSize(QSize(251, 40));
        lineEdit->setMaximumSize(QSize(250, 20));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"setStyleSheet(\"font-size : 9px\"); \n"
"}"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2, 0, Qt::AlignHCenter);

        result = new QLineEdit(Dialog);
        result->setObjectName(QStringLiteral("result"));
        sizePolicy2.setHeightForWidth(result->sizePolicy().hasHeightForWidth());
        result->setSizePolicy(sizePolicy2);
        result->setMinimumSize(QSize(250, 40));
        result->setMaximumSize(QSize(250, 20));
        result->setStyleSheet(QLatin1String("QLineEdit{\n"
"setStyleSheet(\"font-size : 9px\"); \n"
"}"));

        horizontalLayout_2->addWidget(result);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        zerop = new QPushButton(Dialog);
        zerop->setObjectName(QStringLiteral("zerop"));
        sizePolicy1.setHeightForWidth(zerop->sizePolicy().hasHeightForWidth());
        zerop->setSizePolicy(sizePolicy1);
        zerop->setMinimumSize(QSize(80, 80));
        zerop->setMaximumSize(QSize(45, 45));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Handwriting"));
        font2.setPointSize(13);
        zerop->setFont(font2);
        zerop->setShortcut(QStringLiteral(""));
        zerop->setFlat(true);

        horizontalLayout_3->addWidget(zerop);

        onep = new QPushButton(Dialog);
        onep->setObjectName(QStringLiteral("onep"));
        sizePolicy1.setHeightForWidth(onep->sizePolicy().hasHeightForWidth());
        onep->setSizePolicy(sizePolicy1);
        onep->setMinimumSize(QSize(80, 80));
        onep->setMaximumSize(QSize(45, 45));
        onep->setFont(font2);
        onep->setFlat(true);

        horizontalLayout_3->addWidget(onep);

        twop = new QPushButton(Dialog);
        twop->setObjectName(QStringLiteral("twop"));
        sizePolicy1.setHeightForWidth(twop->sizePolicy().hasHeightForWidth());
        twop->setSizePolicy(sizePolicy1);
        twop->setMinimumSize(QSize(80, 80));
        twop->setMaximumSize(QSize(45, 45));
        twop->setFont(font2);
        twop->setFlat(true);

        horizontalLayout_3->addWidget(twop);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        threep = new QPushButton(Dialog);
        threep->setObjectName(QStringLiteral("threep"));
        sizePolicy1.setHeightForWidth(threep->sizePolicy().hasHeightForWidth());
        threep->setSizePolicy(sizePolicy1);
        threep->setMinimumSize(QSize(80, 80));
        threep->setMaximumSize(QSize(45, 45));
        threep->setFont(font2);
        threep->setFlat(true);

        horizontalLayout_4->addWidget(threep);

        fourp = new QPushButton(Dialog);
        fourp->setObjectName(QStringLiteral("fourp"));
        sizePolicy1.setHeightForWidth(fourp->sizePolicy().hasHeightForWidth());
        fourp->setSizePolicy(sizePolicy1);
        fourp->setMinimumSize(QSize(80, 80));
        fourp->setMaximumSize(QSize(45, 45));
        fourp->setFont(font2);
        fourp->setFlat(true);

        horizontalLayout_4->addWidget(fourp);

        fivep = new QPushButton(Dialog);
        fivep->setObjectName(QStringLiteral("fivep"));
        sizePolicy1.setHeightForWidth(fivep->sizePolicy().hasHeightForWidth());
        fivep->setSizePolicy(sizePolicy1);
        fivep->setMinimumSize(QSize(80, 80));
        fivep->setMaximumSize(QSize(45, 45));
        fivep->setFont(font2);
        fivep->setFlat(true);

        horizontalLayout_4->addWidget(fivep);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        sixp = new QPushButton(Dialog);
        sixp->setObjectName(QStringLiteral("sixp"));
        sizePolicy1.setHeightForWidth(sixp->sizePolicy().hasHeightForWidth());
        sixp->setSizePolicy(sizePolicy1);
        sixp->setMinimumSize(QSize(80, 80));
        sixp->setMaximumSize(QSize(45, 45));
        sixp->setFont(font2);
        sixp->setFlat(true);

        horizontalLayout_5->addWidget(sixp);

        sevenp = new QPushButton(Dialog);
        sevenp->setObjectName(QStringLiteral("sevenp"));
        sizePolicy1.setHeightForWidth(sevenp->sizePolicy().hasHeightForWidth());
        sevenp->setSizePolicy(sizePolicy1);
        sevenp->setMinimumSize(QSize(80, 80));
        sevenp->setMaximumSize(QSize(45, 45));
        sevenp->setFont(font2);
        sevenp->setFlat(true);

        horizontalLayout_5->addWidget(sevenp);

        eightp = new QPushButton(Dialog);
        eightp->setObjectName(QStringLiteral("eightp"));
        sizePolicy1.setHeightForWidth(eightp->sizePolicy().hasHeightForWidth());
        eightp->setSizePolicy(sizePolicy1);
        eightp->setMinimumSize(QSize(80, 80));
        eightp->setMaximumSize(QSize(45, 45));
        eightp->setFont(font2);
        eightp->setFlat(true);

        horizontalLayout_5->addWidget(eightp);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        ninep = new QPushButton(Dialog);
        ninep->setObjectName(QStringLiteral("ninep"));
        sizePolicy1.setHeightForWidth(ninep->sizePolicy().hasHeightForWidth());
        ninep->setSizePolicy(sizePolicy1);
        ninep->setMinimumSize(QSize(80, 80));
        ninep->setMaximumSize(QSize(45, 45));
        ninep->setFont(font2);
        ninep->setFlat(true);

        horizontalLayout_7->addWidget(ninep);

        sevenp_2 = new QPushButton(Dialog);
        sevenp_2->setObjectName(QStringLiteral("sevenp_2"));
        sevenp_2->setEnabled(false);
        sizePolicy1.setHeightForWidth(sevenp_2->sizePolicy().hasHeightForWidth());
        sevenp_2->setSizePolicy(sizePolicy1);
        sevenp_2->setMinimumSize(QSize(80, 80));
        sevenp_2->setMaximumSize(QSize(45, 45));
        sevenp_2->setFont(font2);
        sevenp_2->setFlat(true);

        horizontalLayout_7->addWidget(sevenp_2);

        eightp_2 = new QPushButton(Dialog);
        eightp_2->setObjectName(QStringLiteral("eightp_2"));
        eightp_2->setEnabled(false);
        sizePolicy1.setHeightForWidth(eightp_2->sizePolicy().hasHeightForWidth());
        eightp_2->setSizePolicy(sizePolicy1);
        eightp_2->setMinimumSize(QSize(80, 80));
        eightp_2->setMaximumSize(QSize(45, 45));
        eightp_2->setFont(font2);
        eightp_2->setAutoDefault(false);
        eightp_2->setFlat(true);

        horizontalLayout_7->addWidget(eightp_2);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        transition_2 = new QPushButton(Dialog);
        transition_2->setObjectName(QStringLiteral("transition_2"));
        sizePolicy1.setHeightForWidth(transition_2->sizePolicy().hasHeightForWidth());
        transition_2->setSizePolicy(sizePolicy1);
        transition_2->setMinimumSize(QSize(100, 45));
        transition_2->setMaximumSize(QSize(45, 45));
        QFont font3;
        font3.setFamily(QStringLiteral("Bookman Old Style"));
        font3.setPointSize(9);
        transition_2->setFont(font3);
        transition_2->setFlat(true);

        horizontalLayout_6->addWidget(transition_2);

        transition_16 = new QPushButton(Dialog);
        transition_16->setObjectName(QStringLiteral("transition_16"));
        sizePolicy1.setHeightForWidth(transition_16->sizePolicy().hasHeightForWidth());
        transition_16->setSizePolicy(sizePolicy1);
        transition_16->setMinimumSize(QSize(100, 45));
        transition_16->setMaximumSize(QSize(45, 45));
        transition_16->setFont(font3);
        transition_16->setFlat(true);

        horizontalLayout_6->addWidget(transition_16);


        verticalLayout_3->addLayout(horizontalLayout_6);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "\350\276\223\345\205\245\346\225\260\345\255\227", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "\347\273\223\346\236\234", Q_NULLPTR));
        zerop->setText(QApplication::translate("Dialog", "0", Q_NULLPTR));
        onep->setText(QApplication::translate("Dialog", "1", Q_NULLPTR));
        twop->setText(QApplication::translate("Dialog", "2", Q_NULLPTR));
        threep->setText(QApplication::translate("Dialog", "3", Q_NULLPTR));
        fourp->setText(QApplication::translate("Dialog", "4", Q_NULLPTR));
        fivep->setText(QApplication::translate("Dialog", "5", Q_NULLPTR));
        sixp->setText(QApplication::translate("Dialog", "6", Q_NULLPTR));
        sevenp->setText(QApplication::translate("Dialog", "7", Q_NULLPTR));
        eightp->setText(QApplication::translate("Dialog", "8", Q_NULLPTR));
        ninep->setText(QApplication::translate("Dialog", "9", Q_NULLPTR));
        sevenp_2->setText(QString());
        eightp_2->setText(QString());
        transition_2->setText(QApplication::translate("Dialog", "\350\275\254\344\270\272\344\272\214\350\277\233\350\207\263", Q_NULLPTR));
        transition_16->setText(QApplication::translate("Dialog", "\350\275\254\344\270\272\345\215\201\345\205\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
