/********************************************************************************
** Form generated from reading ui file 'progres_dialog_signals.ui'
**
** Created: Mon Apr 21 22:27:12 2008
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROGRES_DIALOG_SIGNALS_H
#define UI_PROGRES_DIALOG_SIGNALS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

class Ui_Progres_Dialog
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *l_source;
    QLabel *l_dest;
    QProgressBar *pbar_progres;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *pb_Start;
    QPushButton *pb_Stop;
    QPushButton *pb_Cancel;

    void setupUi(QDialog *Progres_Dialog)
    {
    if (Progres_Dialog->objectName().isEmpty())
        Progres_Dialog->setObjectName(QString::fromUtf8("Progres_Dialog"));
    Progres_Dialog->resize(399, 129);
    vboxLayout = new QVBoxLayout(Progres_Dialog);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    l_source = new QLabel(Progres_Dialog);
    l_source->setObjectName(QString::fromUtf8("l_source"));

    vboxLayout->addWidget(l_source);

    l_dest = new QLabel(Progres_Dialog);
    l_dest->setObjectName(QString::fromUtf8("l_dest"));

    vboxLayout->addWidget(l_dest);

    pbar_progres = new QProgressBar(Progres_Dialog);
    pbar_progres->setObjectName(QString::fromUtf8("pbar_progres"));
    pbar_progres->setValue(0);
    pbar_progres->setMinimum(0);
    pbar_progres->setMaximum(100);

    vboxLayout->addWidget(pbar_progres);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    pb_Start = new QPushButton(Progres_Dialog);
    pb_Start->setObjectName(QString::fromUtf8("pb_Start"));
    

    hboxLayout->addWidget(pb_Start);

    pb_Stop = new QPushButton(Progres_Dialog);
    pb_Stop->setObjectName(QString::fromUtf8("pb_Stop"));
    pb_Stop->setEnabled(false);

    hboxLayout->addWidget(pb_Stop);

    pb_Cancel = new QPushButton(Progres_Dialog);
    pb_Cancel->setObjectName(QString::fromUtf8("pb_Cancel"));

    hboxLayout->addWidget(pb_Cancel);


    vboxLayout->addLayout(hboxLayout);


    retranslateUi(Progres_Dialog);

    QMetaObject::connectSlotsByName(Progres_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Progres_Dialog)
    {
    Progres_Dialog->setWindowTitle(QApplication::translate("Progres_Dialog", "Progres Dialog", 0, QApplication::UnicodeUTF8));
    l_source->setText(QApplication::translate("Progres_Dialog", "Source", 0, QApplication::UnicodeUTF8));
    l_dest->setText(QApplication::translate("Progres_Dialog", "Destination", 0, QApplication::UnicodeUTF8));
    pbar_progres->setToolTip(QApplication::translate("Progres_Dialog", "Progres of action", 0, QApplication::UnicodeUTF8));
    pb_Start->setToolTip(QApplication::translate("Progres_Dialog", "Start transfer again", 0, QApplication::UnicodeUTF8));
    pb_Start->setText(QApplication::translate("Progres_Dialog", "Start", 0, QApplication::UnicodeUTF8));
    pb_Stop->setToolTip(QApplication::translate("Progres_Dialog", "stop transfer", 0, QApplication::UnicodeUTF8));
    pb_Stop->setText(QApplication::translate("Progres_Dialog", "Stop", 0, QApplication::UnicodeUTF8));
    pb_Cancel->setToolTip(QApplication::translate("Progres_Dialog", "terminate transfar", 0, QApplication::UnicodeUTF8));
    pb_Cancel->setText(QApplication::translate("Progres_Dialog", "Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Progres_Dialog);
    } // retranslateUi

};

namespace Ui {
    class Progres_Dialog: public Ui_Progres_Dialog {};
} // namespace Ui

#endif // UI_PROGRES_DIALOG_SIGNALS_H
