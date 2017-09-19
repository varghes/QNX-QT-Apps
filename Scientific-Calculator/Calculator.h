#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QString>
#include <math.h>
#include "dialog.h"


namespace Ui {
	class CalculatorClass;
}

class Calculator : public QMainWindow
{
	Q_OBJECT

public:
	explicit Calculator(QWidget *parent = 0);
	QString count(QString m);
	QString count(QString op1, QString op, QString op2);
	QString count(QString op1, QString op2);

	~Calculator();

	private slots:
	void on_one_clicked();

	void on_two_clicked();

	void on_three_clicked();

	void on_four_clicked();

	void on_five_clicked();

	void on_six_clicked();

	void on_seven_clicked();

	void on_eight_clicked();

	void on_nine_clicked();

	void on_zero_clicked();

	void on_operAdd_pushButton_clicked();

	void on_operSubtract_pushButton_clicked();

	void on_operMultiply_pushButton_clicked();

	void on_operDivide_pushButton_clicked();

	void on_point_pushButton_clicked();

	void on_backSpace_clicked();

	void on_result_pushButton_clicked();

	void on_lBracket_clicked();

	void on_rBracket_clicked();

	void on_clear_clicked();

	void on_sin_clicked();

	void on_cos_clicked();

	void on_tan_clicked();

	void on_rank_clicked();

	void on_pushButton_clicked();

	void on_log_clicked();

	void on_ln_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

private:
	Ui::CalculatorClass *ui;
	bool b;
};

#endif // CALCULATOR_H
