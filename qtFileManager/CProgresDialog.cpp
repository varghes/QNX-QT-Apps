#include <QtGui>
#include <QFileInfo>
#include <iostream>
#include "CProgresDialog.h"

CProgresDialog::CProgresDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	worker = new CThread();
	t = new QTimer();
	written = 0;
	QObject::connect(pb_Cancel, SIGNAL(clicked()), this, SLOT(pd_close()));
	connect(pb_Stop, SIGNAL(clicked()), this, SLOT(pb_Stop_clicked()));
	connect(pb_Start, SIGNAL(clicked()), this, SLOT(pb_Start_clicked()));
	connect(worker,SIGNAL(finished ()),this,SLOT(pd_close()));
	connect(pb_Cancel,SIGNAL(clicked()),worker,SLOT( terminate()));
	connect(worker,SIGNAL(actualySource(QString)),this,SLOT(setSource()));
 	connect( t, SIGNAL(timeout()), this, SLOT(perform()) );
	connect(&toFile, SIGNAL(readyRead()),this, SLOT(perform()));
	
}

CProgresDialog::~CProgresDialog(){
  delete worker;
}

void CProgresDialog::pb_Stop_clicked(){
	pb_Stop->setEnabled(false);
	pb_Start->setEnabled(true);
}

void CProgresDialog::pb_Start_clicked(){
        worker->setSource(l_source->text());
        worker->setDestination(l_dest->text());
        worker->setType(type);
        worker->start();
        t->start();
	pb_Stop->setEnabled(true);
	pb_Start->setEnabled(false);	
}

void CProgresDialog::pd_close(){
	t->stop();
	this->close();
}

void CProgresDialog::setSource(QString source){
	l_source->setText(source);
	fromFile.setFileName(source);
}


void CProgresDialog::setDestination(QString dest){
	l_dest->setText(dest);
	toFile.setFileName (dest);
}
void CProgresDialog::setProgresValue(qint64 w){
	std::cout << "Slot prijal" << std::endl;
 	written += w;
 	pbar_progres->setValue(written / 1024);
}

void CProgresDialog::perform(){
	pbar_progres->setValue(worker->progres);
	l_source->setText(worker->actualySource);
	l_dest->setText(worker->actualyDest);
}


