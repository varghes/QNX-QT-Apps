#ifndef CPROGRESDIALOG_H
#define CPROGRESDIALOG_H
#include <QDialog>
#include <QString>
#include <QFile>
#include "cthread.h"
#include "ui_progres_dialog.h"


class CProgresDialog : public QDialog, public Ui::Progres_Dialog
{
	Q_OBJECT
	public:
		CProgresDialog(QWidget *parent = 0);
		~CProgresDialog();
		CThread *worker;
		QTimer *t;
		QFile toFile;
		QFile fromFile;
                qint64 written;
		int type;
		
		
	public slots:
		void pb_Start_clicked( void );
		void pb_Stop_clicked( void );
		void pd_close( void );
		void setSource ( QString );
		void setDestination ( QString );
		void setProgresValue( qint64 );
		void perform(void);

		
	
};
#endif
