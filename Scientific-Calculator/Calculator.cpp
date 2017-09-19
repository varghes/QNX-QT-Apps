#include "Calculator.h"
#include "ui_Calculator.h"
#include <QDebug>
#include <math.h>
#include "dialog.h"




Calculator::Calculator(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::CalculatorClass)
{
	ui->setupUi(this);
	b = true;

}

Calculator::~Calculator()
{
	delete ui;
}

void Calculator::on_one_clicked()
{
	ui->express_lineEdit->insert(tr("1"));

}

void Calculator::on_two_clicked()
{
	ui->express_lineEdit->insert(tr("2"));

}


void Calculator::on_three_clicked()
{
	ui->express_lineEdit->insert(tr("3"));

}

void Calculator::on_four_clicked()
{
	ui->express_lineEdit->insert(tr("4"));

}


void Calculator::on_five_clicked()
{
	ui->express_lineEdit->insert(tr("5"));

}


void Calculator::on_six_clicked()
{
	ui->express_lineEdit->insert(tr("6"));

}

void Calculator::on_seven_clicked()
{
	ui->express_lineEdit->insert(tr("7"));

}

void Calculator::on_eight_clicked()
{
	ui->express_lineEdit->insert(tr("8"));

}

void Calculator::on_nine_clicked()
{
	ui->express_lineEdit->insert(tr("9"));
}

void Calculator::on_zero_clicked()
{
	ui->express_lineEdit->insert(tr("0"));

}

void Calculator::on_operAdd_pushButton_clicked()
{
	ui->express_lineEdit->insert(tr("+"));

}

void Calculator::on_operSubtract_pushButton_clicked()
{
	ui->express_lineEdit->insert(tr("-"));

}

void Calculator::on_operMultiply_pushButton_clicked()
{
	ui->express_lineEdit->insert(tr("*"));

}


void Calculator::on_operDivide_pushButton_clicked()
{
	ui->express_lineEdit->insert(tr("/"));

}

void Calculator::on_point_pushButton_clicked()
{
	ui->express_lineEdit->insert(tr("."));

}


void Calculator::on_backSpace_clicked()
{
	ui->express_lineEdit->backspace();
}

void Calculator::on_lBracket_clicked()
{
	ui->express_lineEdit->insert(tr("("));
}


void Calculator::on_rBracket_clicked()
{
	ui->express_lineEdit->insert(tr(")"));
}

void Calculator::on_clear_clicked()
{
	ui->express_lineEdit->clear();
	ui->result_lineEdit->clear();
}
void Calculator::on_sin_clicked()
{
	ui->express_lineEdit->insert(tr("sin()"));

}
void Calculator::on_cos_clicked()
{
	ui->express_lineEdit->insert(tr("cos()"));
}

void Calculator::on_tan_clicked()
{
	ui->express_lineEdit->insert(tr("tan()"));
}
void Calculator::on_rank_clicked()
{
	ui->express_lineEdit->insert(tr("!"));
}
void Calculator::on_pushButton_clicked()
{
	ui->express_lineEdit->insert(tr("^"));
}
void Calculator::on_log_clicked()
{
	ui->express_lineEdit->insert(tr("log()"));
}
void Calculator::on_ln_clicked()
{
	ui->express_lineEdit->insert(tr("ln()"));
}
void Calculator::on_pushButton_3_clicked()
{
	ui->express_lineEdit->insert(tr("sqrt()"));
}

void Calculator::on_result_pushButton_clicked()
{
	QString m = ui->express_lineEdit->text();
	m = count(m);
	if (!b)
	{
		b = true;
		ui->result_lineEdit->setText("wrong ");

	}
	else
	{
		ui->result_lineEdit->setText(m);
	}

}


QString Calculator::count(QString m)
{
	if (m.contains("sin") || m.contains("cos") || m.contains("tan"))
	{
		//qDebug()<<"1213132";
		QString str;

		//m="#"+m+"#";
		int start = 0, end = 0, n = 0;
		for (int i = 0; i < m.length(); i++)
		{
			if (m.at(i) == 'i' || m.at(i) == 'o' || m.at(i) == 'a')
			{
				n++;
				start = i;
			}
			if (n == 1 && m.at(i) == ')')
			{
				end = i;
			}
			if (start != end&&end != 0)
			{
				qDebug() << "jinru";
				QString temp1, temp2, temp;

				temp = m.mid(start + 3, end - start - 3);
				temp1 = count(temp);
				temp2 = m.mid(start - 1, 3);
				m.remove(start - 1, end - start + 2);
				qDebug() << m;
				qDebug() << temp1 << temp2;
				str = count(temp1, temp2);
				qDebug() << str;
				if (end - start + 1 == i)
				{
					m.insert(start - 1, str);
					return count(m);
				}
				else
					//if(end-start+1!=i)
				{
					qDebug() << "dddsdf";
					if (str.at(0) == '-' && (m.at(start - 2) == '+' || m.at(start - 2) == '-'))
					{
						qDebug() << "d" << str;
						str = str.mid(1);
						m.insert(start - 1, str);
						qDebug() << "dd" << m;

						if (m.at(start - 2) == '-')
						{
							m.remove(start - 2, 1);
							if (start - 2 != 0)
							{
								m.insert(start - 2, '+');
							}


						}
					}
					else
					{

						m.insert(start - 1, str);
					}
					return count(m);

				}

			}

		}


	}
	else if (m.contains("log"))
	{
		QString str;

		//m="#"+m+"#";
		int start = 0, end = 0, n = 0;
		for (int i = 0; i < m.length(); i++)
		{
			if (m.at(i) == 'o')
			{
				n++;
				start = i;
			}
			if (n == 1 && m.at(i) == ')')
			{
				end = i;
			}
			if (start != end&&end != 0)
			{
				qDebug() << "jinru";
				QString temp1, temp2, temp;

				temp = m.mid(start + 3, end - start - 3);
				temp1 = count(temp);
				temp2 = m.mid(start - 1, 3);
				m.remove(start - 1, end - start + 2);
				qDebug() << m;
				qDebug() << temp1 << temp2;
				str = count(temp1, temp2);
				qDebug() << str;
				if (end - start + 1 == i)
				{
					return count(str);
				}
				else

				{
					qDebug() << "dddsdf";
					if (str.at(0) == '-' && (m.at(start - 2) == '+' || m.at(start - 2) == '-'))
					{
						qDebug() << "dddsdf";
						qDebug() << "d" << str;
						str = str.mid(1);
						m.insert(start - 1, str);
						qDebug() << "dd" << m;

						if (m.at(start - 2) == '-')
						{
							m.remove(start - 2, 1);
							if (start - 2 != 0)
							{
								m.insert(start - 2, '+');
							}


						}
					}
					else
					{

						m.insert(start - 1, str);
					}
					return count(m);

				}

			}

		}
	}
	else if (m.contains("ln"))
	{
		QString str;
		int start = 0, end = 0, n = 0;
		for (int i = 0; i < m.length(); i++)
		{
			if (m.at(i) == 'l')
			{
				n++;
				start = i;
			}
			if (n == 1 && m.at(i) == ')')
			{
				end = i;
			}
			if (start != end&&end != 0)
			{
				QString temp1, temp2, temp;
				temp = m.mid(start + 3, end - start - 3);
				temp1 = count(temp);
				temp2 = m.mid(start, 2);
				str = count(temp1, temp2);
				m.remove(start, end - start + 3);
				qDebug() << temp1 << temp2;
				qDebug() << str;
				if (start == 0)
				{
					qDebug() << "ok";
					return count(str);
				}
				else
				{
					qDebug() << "dddsdf";
					if (str.at(0) == '-' && (m.at(start - 1) == '+' || m.at(start - 1) == '-'))
					{
						qDebug() << "d" << str;
						str = str.mid(1);
						m.insert(start, str);
						qDebug() << "dd" << m;

						if (m.at(start - 1) == '-')
						{
							m.remove(start - 1, 1);
							if (start - 1 != 0)
							{
								m.insert(start - 1, '+');
							}


						}
					}
					else
					{

						m.insert(start, str);
					}
					return count(m);

				}
			}
		}
	}
	else if (m.contains("sqrt"))
	{
		qDebug() << "jinru";
		QString str;
		int start = 0, n = 0, end = 0;
		for (int i = 0; i < m.length(); i++)
		{
			if (m.at(i) == 's')
			{
				start = i;
				n++;
			}
			if (n != 0 && m.at(i) == ')')
			{
				end = i;
			}
			if (start != end&&end != 0)
			{
				qDebug() << "ok";
				QString temp1, temp2, temp;
				temp = m.mid(start + 5, end - start - 5);
				temp2 = m.mid(start, 4);
				temp1 = count(temp);
				m.remove(start, end - start + 1);
				qDebug() << start << n << end;
				qDebug() << temp << temp1 << temp2;
				str = count(temp1, temp2);
				qDebug() << str;
				m.insert(start, str);
				return count(m);


			}


		}
	}
	else if (m.contains(")"))    //提取括号
	{
		QString str;
		QString temp;
		int lb = 0, rb = 0, start = 0, end = 0;
		for (int i = 0; i < m.length(); i++)
		{
			if (m.at(i) == '(')
			{
				lb++;
				if (lb == 1)
					start = i;
			}
			if (m.at(i) == ')')
				rb++;
			if (lb == rb&&rb != 0)
			{
				end = i;
				temp = m.mid(start + 1, end - start - 1);
				//qDebug()<<temp;
				m.remove(start, end - start + 1);
				str = count(temp);
				//ui->lineEdit->setText(str);
				qDebug() << temp;
				qDebug() << m;
				qDebug() << "str:" << str;
				if (start >= 1)
				{
					if (str.at(0) == '-'&&m.at(start - 1) == '+')
					{
						m.remove(start - 1, 1);
						m.insert(start - 1, str);
						//qDebug()<<m;
					}
					else if (str.at(0) == '-'&&m.at(start - 1) == '-')
					{
						m.remove(start - 1, 1);
						str = "+" + str.mid(1);
						m.insert(start - 1, str);
					}
					else
					{
						m.insert(start, str);
					}

				}
				else
				{
					//qDebug()<<m;

					m.insert(start, str);
				}
				//qDebug()<<m;

				return count(m);


			}
		}
	}



	else if (m.contains("!"))
	{
		QString str;
		int op = 0;
		for (int i = 0; i < m.length(); i++)
		{
			if (m.at(i) == '!')
			{
				op = i;
				QString temp0, temp1;
				temp0 = m.mid(op - 1, 1);
				temp1 = m.mid(op, 1);
				qDebug() << temp0 << temp1;
				m.remove(op - 1, 2);
				qDebug() << str;
				str = count(temp0, temp1);
				m.insert(op - 1, str);
				return count(m);


			}
		}


	}

	else if (m.contains("^"))
	{
		QString str;
		int start = 0, op = 0, end = 0;
		m = "#" + m + "#";
		qDebug() << m;
		for (int i = 0; i < m.length(); i++)
		{

			if (m.at(i) == '^')
			{

				op = i;
			}
			if (op == 0)
			{
				if (m.at(i) == '+' || m.at(i) == '-' || m.at(i) == '*' || m.at(i) == '/' || m.at(i) == '#')
				{
					start = i;
				}
			}
			if (op != 0)
			{
				if (m.at(i) == '+' || m.at(i) == '-' || m.at(i) == '*' || m.at(i) == '/' || m.at(i) == '#')
				{
					if (i != op + 1)
					{
						end = i;
						QString temp0, temp1, temp2;
						temp2 = m.mid(op + 1, end - op - 1);
						temp1 = m.mid(op, 1);
						temp0 = m.mid(start + 1, op - start - 1);
						m.remove(start + 1, end - start - 1);
						str = count(temp0, temp1, temp2);
						//qDebug()<<temp0<<temp1<<temp2;
						//qDebug()<<str;
						m.insert(start + 1, str);

						m.remove('#');
						return count(m);


					}
				}

			}

		}

	}




	else if (m.contains("*") || m.contains("/"))
	{
		QString str;

		int start = 0, end = 0, op = 0;
		m = "#" + m + "#";    //标记  一个一个分
							  // qDebug()<<m;
		for (int i = 0; i < m.length(); i++)
		{
			if (op != 0)
			{
				if (m.at(i) == '*' || m.at(i) == '/' || m.at(i) == '+' || m.at(i) == '-' || m.at(i) == '#')
				{
					if (i != op + 1)
					{
						end = i;
						QString temp0, temp1, temp2;
						temp2 = m.mid(op + 1, end - op - 1);
						temp1 = m.mid(op, 1);
						temp0 = m.mid(start + 1, op - start - 1);
						m.remove(start + 1, end - start - 1);

						qDebug() << "123" << m;
						str = count(temp0, temp1, temp2);
						qDebug() << temp0 << temp1 << temp2;

						//ui->result_lineEdit->setText(str);
						if (str.at(0) == '-' && (m.at(start) == '+' || m.at(start) == '-'))
						{
							qDebug() << "d" << str;
							str = str.mid(1);
							m.insert(start + 1, str);
							qDebug() << "dd" << m;
							if (m.at(start) == '-')
							{
								m.remove(start, 1);
								if (start != 1)
								{
									m.insert(start, '+');
								}


							}
						}
						else
						{
							m.insert(start + 1, str);
						}

						m.remove('#');
						return count(m);
					}
				}
			}
			if (m.at(i) == '*' || m.at(i) == '/')
			{
				op = i;
			}
			if (op == 0)
			{
				if (m.at(i) == '+' || m.at(i) == '-' || m.at(i) == '#')
				{
					start = i;
					qDebug() << "strt=" << start;

				}
			}

		}
	}
	else if (m.mid(1).contains('+') || m.mid(1).contains('-'))
	{

		int op = 0, start = 0, end = 0;
		// qDebug()<<"qwe";
		m = m + "#";
		for (int i = 1; i < m.length(); i++)
		{
			//qDebug()<<"qwe";
			if (m.at(i) == '+' || m.at(i) == '-' || m.at(i) == '#')
			{

				op++;
				if (op == 1)
					start = i;
				qDebug() << start << op;
				if (op == 2)
				{
					qDebug() << "qwe";
					end = i;
					QString temp0, temp1, temp2;
					temp2 = m.mid(start + 1, end - start - 1);
					temp1 = m.mid(start, 1);
					temp0 = m.mid(0, start);
					qDebug() << temp0 << temp1 << temp2;
					m.remove(0, end);
					m.remove('#');
					qDebug() << m;
					m.insert(0, count(temp0, temp1, temp2));
					//qDebug()<<m;
					qDebug() << m;
					return count(m);

				}
			}
		}
	}
	return m;
}
QString Calculator::count(QString op1, QString op, QString op2)
{

	//qDebug()<<"jin 2ru";

	if (op == "+")
	{
		qDebug() << "ok1";
		return(QString::number(op1.toDouble() + op2.toDouble(), 'g', 16));
	}
	else if (op == "-")
	{
		qDebug() << "ok1";
		//qDebug()<<"jin ru ";
		return(QString::number(op1.toDouble() - op2.toDouble(), 'g', 16));

	}
	else if (op == "*")
	{
		qDebug() << "ok1";
		return(QString::number(op1.toDouble()*op2.toDouble(), 'g', 16));
	}
	else if (op == "/")
	{
		qDebug() << "ok1";

		if (op2.toDouble() == 0)
		{
			b = false;
			return "0";
		}
		return(QString::number(op1.toDouble() / op2.toDouble(), 'g', 16));
	}
	else if (op == "^")
	{
		qDebug() << "ok";
		double total = 1;
		qDebug() << total;
		for (int i = 1; i <= op2.toInt(); i++)
		{

			total = total*op1.toDouble();
			qDebug() << "tatal" << i << total;
		}


		return (QString::number(total, 'g', 16));

	}


}
QString Calculator::count(QString op1, QString op2)
{

	qDebug() << "jin 2ru";
	if (op2 == "sin")
		return (QString::number(sin(op1.toDouble()), 'g', 3));
	else if (op2 == "tan")
		return (QString::number(tan(op1.toDouble()), 'g', 3));
	else if (op2 == "cos")
		return (QString::number(cos(op1.toDouble()), 'g', 3));
	else if (op2 == "!")
	{
		int total = 1;
		for (int i = 1; i <= op1.toInt(); i++)
		{
			total = total*i;
		}
		return (QString::number(total, 'g', 16));
	}
	else if (op2 == "log")
	{
		return (QString::number(log10(op1.toDouble()), 'g', 4));
	}
	else if (op2 == "ln")
	{
		return (QString::number(log(op1.toDouble()), 'g', 4));
	}
	else if (op2 == "sqrt")
	{
		return (QString::number(sqrt(op1.toDouble()), 'g', 16));
	}


}
void Calculator::on_pushButton_4_clicked()
{
	Dialog* dialog = new Dialog(this);
	dialog->exec();
}
