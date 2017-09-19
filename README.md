# QNX-QT-APPS
 
 Collection of QT applications compiled for QNX 
 
1. Text Editor 
   tea
2. File Manager/ Explorer
   qtFileManager
3. Calculators 
   calc ,scicalc
4. Games 
   chess-qt ,Freecell ,soft336PacmanGame ,BlackJack ,QtLianliankan
   QtMineSweep, multiSnake, QtTetris, snake, solitaire

"exe" folder contains the executable file (Compiled against QNX 6.5 ARMV7)
"image" folder  contains the app final image 

QT QNX Installation , refer my other repository 
https://github.com/varghes/BeagleboneBlack-QNX-QT

Compilation : (on Windows )

1. open command line  "Cmd"
2. "cd" Change directory to the application directory (.pro )
3. qmake -spec unsupported/qws/qnx-armv7-g++
4. make 



Debugging 

1.Create Debug version of application 
 .pro file  add this on Top

 CONFIG += qt warn_on debug
    debug {
        TARGET = myappdebug
    }
    release {
        TARGET = myapp
    }
	
2. qmake -spec unsupported/qws/qnx-armv7-g++ CONFIG+=debug
3. make CONFIG+=debug


QNX IDE Changes For Debugging 

1.debug configuration-> Environment variable
add this environment variable   
 TMPDIR=/ramdisk
 XDG_CONFIG_HOME=/ramdisk
 
2.compile using commandline , Debug using IDE
 
 
 .build File Changes 
 
 1. Copy the executable file to  
    prebuilt\armle-v7\sbin
 2. make the script file changes
 
[+raw perms=+x]calc
[+raw perms=+x]chess-qt
[+raw perms=+x]Freecell
[+raw perms=+x]soft336PacmanGame
[+raw perms=+x]BlackJack
[+raw perms=+x]qtFileManager
[+raw perms=+x]QtLianliankan
[+raw perms=+x]QtMineSweep
[+raw perms=+x]multiSnake
[+raw perms=+x]QtTetris
[+raw perms=+x]scicalc
[+raw perms=+x]snake
[+raw perms=+x]solitaire
[+raw perms=+x]tea

/usr/bin/calc=calc
/usr/bin/chess-qt=chess-qt
/usr/bin/Freecell=Freecell
/usr/bin/soft336PacmanGame=soft336PacmanGame
/usr/bin/BlackJack=BlackJack
/usr/bin/qtFileManager=qtFileManager
/usr/bin/QtLianliankan=QtLianliankan
/usr/bin/QtMineSweep=QtMineSweep
/usr/bin/multiSnake=multiSnake
/usr/bin/QtTetris=QtTetris
/usr/bin/scicalc=scicalc
/usr/bin/snake=snake
/usr/bin/solitaire=solitaire
/usr/bin/tea=tea
 
 photos are uploaded here
 
 http://ihaack.blogspot.in/2017/09/qt-qnx-apps.html
 
License :
 
Please refer the individual project License Terms 


 


