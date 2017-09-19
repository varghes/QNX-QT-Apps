#ifndef CTHREAD_H
#define CTHREAD_H

#include <QThread>
#include <QString>
#include <QFile>
#include <QWidget>
#include <QFileInfo>
#include <QDir>
#include <QMutex>
#include <QSemaphore>
#include <vector>

struct device{
	QString path;
};
  
class CThread : public QThread
{
public:
    CThread();
    virtual void run();
    void setSource(QString);
    void setDestination(QString);
    void setType(int);
    void copyFile(QString,QString);
    void moveFile(QString,QString);
    void deleteFile(QString);
    int getProgres(void);
    QString actualySource;
    QString actualyDest;
    int progres;
    ~CThread();
     
private:
    QString source;
    QString dest;
    int type;

};

#endif
