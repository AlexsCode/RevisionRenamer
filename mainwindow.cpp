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
    QString file_list = file_names.join(",");

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
                QFileInfo targetfileinfo(file.fileName());
                QFileInfo sourcepath(targetfileinfo.path());
                QString singlefilename(targetfileinfo.fileName());
                QString FileType(targetfileinfo.completeSuffix());//Allows for many filetypes.
                QString Filename_notype (targetfileinfo.baseName()) ;
                //QString Filename_notype = singlefilename.remove(FileType);


                if(splitbyline[i].contains(Filename_notype))
                 {   QString Revision = (splitbyline[i].right(3));
                     //QString FileType(targetfileinfo.completeSuffix());
                     QString Copyvalue= (Filename_notype+"_"+Revision+"."+FileType);//name of the copy

                     //test outputs

                     ui->comboBox_output->addItem(Revision);
                     ui->comboBox_output->addItem(file_names[j]);

                     QString Path (sourcepath.filePath());
                     QString targetPath = (Path+"/"+Copyvalue);
                     ui->textEdit_output->setText(targetPath);

                     file.copy(targetPath);

                     //QFile copy is broken

                   }
              }
}
