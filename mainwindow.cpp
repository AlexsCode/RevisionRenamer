#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <QString>
#include <QFileDialog>
#include <QStringListIterator>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_FileLocation_clicked()
{   file_names = QFileDialog::getOpenFileNames(this,"directory","");


   // QFileDialog::filesSelected();
    QString file_list = file_names.join(",");
    //QFileInfo fileinfo(file_list.fileName());
    //ui->textEdit->setText(file_list);
    //filter removed ||C://Users/","RVTs,IFCs,NWCs,TXT(*rvt,*ifc,*nwc,*txt)


}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString currenttext = ui->lineEdit->text();
}
void MainWindow::calculations()
{


}
void MainWindow::on_textEdit_textChanged()
{
   //creates input list 2
   QString Secondcurrenttext = ui->textEdit->toPlainText();
   splitbyline = Secondcurrenttext.split("\n");
}

void MainWindow::on_pushButton_Rename_clicked()
{
    //stepper to compare values
    for (int j=0;j<file_names.size();j++)
         for (int i=0;i<splitbyline.size();i++)
             {  QFile file(file_names[j]); //THIS IS IT
                QFileInfo fileinfo(file.fileName());
                QString singlefilename(fileinfo.fileName());
                QString Filetype = (singlefilename.right(4));
                QString Filename_notype = singlefilename.remove(Filetype);

                if(splitbyline[i].contains(Filename_notype))
                 {
                     QString specificline = splitbyline[i];
                     QString Revision = specificline.right(3);
                     QString Copyvalue= (Filename_notype+"_"+Revision+Filetype);
                     ui->textEdit_output->setText(Copyvalue);
                     ui->comboBox_output->addItem(Revision);
                     ui->comboBox_output->addItem(file_names[j]);
                     QFile file2(file_names[j]);
                     file2.fileName();
                     file2.copy(Copyvalue);

                     //QFile copy is broken

                   }
              }
}
