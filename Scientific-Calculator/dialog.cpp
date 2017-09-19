#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);
}

Dialog::~Dialog()
{
	delete ui;
}

void Dialog::on_onep_clicked()
{
	ui->lineEdit->insert(tr("1"));
}

void Dialog::on_twop_clicked()
{
	ui->lineEdit->insert(tr("2"));
}

void Dialog::on_threep_clicked()
{
	ui->lineEdit->insert(tr("3"));
}

void Dialog::on_fourp_clicked()
{
	ui->lineEdit->insert(tr("4"));
}

void Dialog::on_fivep_clicked()
{
	ui->lineEdit->insert(tr("5"));
}

void Dialog::on_sixp_clicked()
{
	ui->lineEdit->insert(tr("6"));
}

void Dialog::on_sevenp_clicked()
{
	ui->lineEdit->insert(tr("7"));
}

void Dialog::on_eightp_clicked()
{
	ui->lineEdit->insert(tr("8"));
}

void Dialog::on_ninep_clicked()
{
	ui->lineEdit->insert(tr("9"));
}

void Dialog::on_zerop_clicked()
{
	ui->lineEdit->insert(tr("0"));
}

void Dialog::on_transition_2_clicked()
{
	QString str;
	QString temp = "2";
	str = ui->lineEdit->text();
	str = transition(str, temp);
	ui->result->setText(str);

}
void Dialog::on_transition_16_clicked()
{
	QString str;
	QString temp = "16";
	str = ui->lineEdit->text();
	str = transition(str, temp);
	ui->result->setText(str);
}

QString Dialog::transition(QString m, QString n)
{
	if (n == "2")
	{
		return (QString::number(m.trimmed().toInt(), 2));
	}

	else if (n == "16")
	{
		return (QString::number(m.trimmed().toInt(), 16));
	}
}

