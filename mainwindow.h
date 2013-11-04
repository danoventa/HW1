/**
* @file
* @author Luc Renambot
* @version 1.0
* @section LICENSE
*  blah blah ?
* @section DESCRIPTION
*  FOR THE EMPEROR!!!!!!!!!!
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> /*!< \include QmainWindow */

namespace Ui {
    class MainWindow;
}

/*! \brief Main class
 *  \class MainWindow class.h "inc/class.h"
 *         of my application for project CS340.
 *
 *  Inherits for QMainWindow from Qt
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     /**
      * Constructor for MainWindow
      *
      * @param parent a parent widget, can be null
      */
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_3_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

    void on_checkBox_clicked(bool checked);

    int check_sum();

    void on_VolumeControl_valueChanged(int value);

    void volume_changed(int value);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int count;
    int checked1, checked2, checked3;
};

#endif // MAINWINDOW_H
