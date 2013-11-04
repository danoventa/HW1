//! \brief MainWindow Class
///
/** This is where the underlying code to the user
  * interface is. Any changes to the ui class are
  * performed in this class. It also stores some
  * of the information required for the window to
  * display.
  */

#include <iostream>             /*!< \include the iostream library */
#include "mainwindow.h"         /*!< \include the mainwindow header file */
#include "ui_mainwindow.h"      /*!< \include the user interface header. */


//! MainWindow class constructor
///
/** This is where an instance of the ui class is created
  * and any paramaters for the mainwindow class are
  * initialized.
  * @param parent a parent widget, can be null
  */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count = 0;    /*!< int used in the window */
    checked1 = 0; /*!< int used in the window */
    checked2 = 0; /*!< int used in the window */
    checked3 = 0; /*!< int used in the window */
}

//! MainWindow class destructor
///
/** Deletes the instance of ui created in the
  * constructor.
  */
MainWindow::~MainWindow()
{
    delete ui;      /*!< delete ui instance */
}

//! A sumple sum function
///
/** This will add up the values of the checked boxes
  * and return an int to be used on_pushButton_clicked()
  * \return an int sum of checked value.
  * \fn int MainWindow::check_sum()
  */
int MainWindow::check_sum(){
    return (checked1 + checked2 + checked3);    /*!< sum of the checked boxes*/
}

//! Sumbit button actions
///
/** This will change specific values displayed
  * on the ui based on the submit button actions
  * and will limit the size to 99 to match the
  * progress bar value.
  * \fn void MainWindow::un_pushButton_clicked()
  *
  */
void MainWindow::on_pushButton_clicked()
{
    count = count + check_sum();            /*!< Add the checked to the counter */
    if (count >= 99){                       /*!< this is to match the volume bar */
        count = count - 99;
    }
    /*! Unconditionally shown documentation.
     *  \if count >= 99
     *    Subtract 99 from count.
     *  \endif
     */

    this->ui->lcdNumber->display(count);    /*!< change value displayed by LCD widget */

    volume_changed(count);                  /*!< call to change volume, sends counter */

    std::cout << "for the emporer! " << std::endl;
}

//! Change a checked value
///
/** The following 3 give an int defined in the main
  * window class a value determined by whether the box
  * is checked or not. This is then used in the push
  * button function.
  * @param  checked a boolean variable.
  * \fn void MainWindow::on_checkBox_2_clicked(bool checked)
  */
void MainWindow::on_checkBox_3_clicked(bool checked)
{
    if (checked == true){   /*!< return 1 if true otherwise 0 */
        checked1 = 1;
    }
    else
        checked1 = 0;
}
/*! \fn void MainWindow::on_checkBox_2_clicked(bool checked)
 *  \param checked a boolean variable
 *
 **/
void MainWindow::on_checkBox_2_clicked(bool checked)
{
    if (checked == true){   /*!< return 1 if true otherwise 0 */
        checked2 = 1;
    }
    else
        checked2 = 0;
}
/*! \fn void MainWindow::on_checkBox_clicked(bool checked)
 *  \param checked a boolean variable
 *
 **/
void MainWindow::on_checkBox_clicked(bool checked)
{
    if (checked == true){   /*!< return 1 if true otherwise 0 */
        checked3 = 1;
    }
    else
        checked3 = 0;
}

//! Changes value of Volume and Counter
///
/** This is connected to the Volume progress bar and
  * the counter. If this is changed the volume of the
  * progress bar and the LED counter will change
  * accordingly. Connected through signal to bar.
  * @param  value   int variable attained from Volume control
  * \fn void MainWindow::on_VolumeControl_valueChanged(int value)
  */
void MainWindow::on_VolumeControl_valueChanged(int value)
{
    this->ui->lcdNumber->display(value);    /*!< Change the value displayed by the coutner */
    count = value;                          /*!< Change the counter value. */
}

//! Change the Volume Bar value
///
/** This will change the value of the volume progress
  * bar. Also print out the value of the progress bar
  * \param  value   int used to modify volume.
  * \fn void MainWindow::volume_changed(int value)
  * \sa on_pushButton_clicked()
  */
void MainWindow::volume_changed(int value)
{
    std::cout << "Value is " << value << std::endl;
    this->ui->Volume->setValue(value);      /*!< Changes the value assciated to the Volume bar */
}

//! Exit
///
/** Calls on the destructor and exits the program
 *  \sa ~MainWindow()
 *  \fn void MainWindow::on_pushButton_2_clicked()
  */
void MainWindow::on_pushButton_2_clicked()
{
    std::cout << std::endl << "All your pizza are belong to us!" << std::endl;
    ui->~MainWindow();      /*!< call to destructor */
    exit(0);                /*!< exit prgram successfully */
}
