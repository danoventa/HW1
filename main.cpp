///  Main class of the program
///
/**  This is where the main window class is called
  *  and then outputted. It will execute the QT
  *  application
  */

#include "mainwindow.h" /*!< \include the mainwindow class */
#include <QApplication> /*!< \include the QT app library */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); /*!< create a QT app */
    MainWindow w;               /*!< an instance of MainWIndow class */
    w.show();                   /*!< show the window class w */
    
    return a.exec();            /*!< execute the QT app */
}
