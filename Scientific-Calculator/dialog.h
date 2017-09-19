#pragma once
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
	class Dialog;
}

class Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog(QWidget *parent = 0);
	~Dialog();
	QString transition(QString m, QString n);

	private slots:
	void on_onep_clicked();

	void on_twop_clicked();

	void on_threep_clicked();

	void on_fourp_clicked();

	void on_fivep_clicked();

	void on_sixp_clicked();

	void on_sevenp_clicked();

	void on_eightp_clicked();

	void on_ninep_clicked();

	void on_zerop_clicked();

	void on_transition_2_clicked();

	void on_transition_16_clicked();


private:
	Ui::Dialog *ui;
};

#endif // DIALOG_H
