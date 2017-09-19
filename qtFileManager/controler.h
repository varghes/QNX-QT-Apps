 #ifndef CONTROLER_H
 #define CONTROLER_H

 #include <QString>
 #include <QStringList>
 #include <QDir>
 #include <vector>
 #include <QMutex>
 #include <QDirModel>



 //#include "cthread.h"
/*
struct device{
	QString path;
	int use;
};
*/
 class Controler{
 public:
     Controler();
     static int vetsi(QString  a, QString  b);
     
     QStringList  cGetFiles(QDir path);
     QString  cShowDiskUsage(void);	

     void  cCopy(QString source, QString destination);
     void  cMove  (QString source, QString destination);
     int  cRename(QString source, QString destination);
     int  cMkDir (QString path,QString name);
     void  cDelete(QString file);

     QDirModel *leftModel;
     QDirModel *rightModel;
 protected:
     
 private:
	
 };
 #endif
