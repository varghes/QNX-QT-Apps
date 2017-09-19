 #ifndef WINDOW_H
 #define WINDOW_H

 #include <QMainWindow>
 #include <QDir>
 #include <QTreeView>
 #include <QListView>


 #include "controler.h"

 class QAction;
 class QLabel;
 class QMenu;
 class QPushButton;
 class QWidget;
 class QHBoxLayout;
 class QListWidget;
 class QLCDNumber;
 class QString;
 class QDir;
 class QComboBox;
 
 

 class Window : public QMainWindow
 {
     Q_OBJECT

 public:
     Window();

 protected:
     //void contextMenuEvent(QContextMenuEvent *event);

 private slots:
     void newFile();
     void copyF();
     void moveF();
     void mkdir();
     void deleteF();
     void renameF();
     void bold();
     void italic();
     void about();
     void aboutQt();
     void switchFocus();
     void setFocusL();
     void setFocusR();
     void setPathL(int a);
     void setPathR(int a);
     void dblClickedOnMyTreeR(QModelIndex index);
     void dblClickedOnMyTreeL(QModelIndex index);
     void refresh(void);

 private:
     void createActions();
     void createMenus();
     void createButtons();
     void initializeDevices();

     QMenu *fileMenu;
     QMenu *editMenu;
     QMenu *formatMenu;
     QMenu *helpMenu;

     QDir dirL;
     QDir dirR;
     
     QComboBox *comboL;
     QComboBox *comboR;
     
     QWidget *bottomButton;
     QHBoxLayout *buttons;
     
     QTreeView *treeL;
     QTreeView *treeR;
     
     Controler *kontroler;
     
     QAction *newFileAct;
     QAction *newDirectoryAct;
     QAction *exitAct;
     QAction *cutAct;
     QAction *copyAct;
     QAction *pasteAct;
     QAction *boldAct;
     QAction *italicAct;
     QAction *aboutAct;
     QAction *aboutQtAct;
     QAction *tabAct;
     
     QLabel *infoLabel;
     
     QPushButton *bbRefresh;
     QPushButton *bbCopy;
     QPushButton *bbMove;
     QPushButton *bbMkdir;
     QPushButton *bbDelete;
     QPushButton *bbRename;
     QPushButton *bbQuit;
     QPushButton *tabB;
     
     QLCDNumber *lcd; 

     QStringList devices;
 };

 #endif
