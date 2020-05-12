#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <QString>
#include <QFileDialog>
#include <QStringListIterator>


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

    //filter removed, Can be used to allow only specific filetypes|C://Users/","RVTs,IFCs,NWCs,TXT(*rvt,*ifc,*nwc,*txt)
}


void MainWindow::on_textEdit_textChanged()
{
   //Records text input -> splits into several substrings line by line.
   QString Secondcurrenttext = ui->textEdit->toPlainText();
   splitbyline = Secondcurrenttext.split("\n");
}

void MainWindow::on_pushButton_Rename_clicked()
{
    //Main loops to check for viable files to rename
    for (int j=0;j<file_names.size();j++)
         for (int i=0;i<splitbyline.size();i++)
             {  QFile file(file_names[j]); //Creates and assigns file from filepath
                QFileInfo targetfileinfo(file.fileName()); //finds the file name
                QFileInfo sourcepath(targetfileinfo.path()); //finds the file path
                QString singlefilename(targetfileinfo.fileName()); // unsure if still required|
                QString FileType(targetfileinfo.completeSuffix());//Saves filetype |Allows for many filetypes.
                QString Filename_notype (targetfileinfo.baseName()); //Saves filename without the filetype


                if(splitbyline[i].contains(Filename_notype)) // searches if finalname is in the text input
                 {   QString Revision = (splitbyline[i].right(3)); //splits the revision from the end of the substring splitbyline
                     QString Copyvalue= (Filename_notype+"_"+Revision+"."+FileType);//sets what the copy should be named

                     //test outputs - Used for debugging
                     //ui->comboBox_output->addItem(Revision); //Allows for correctly displaying Revision|can be removed
                     //ui->comboBox_output->addItem(file_names[j]);//Allows for correctly displaying file paths |can be removed

                     QString Path (sourcepath.filePath()); //finds the full path
                     QString targetPath = (Path+"/"+Copyvalue); //adds the path to the prefered name
                     //ui->textEdit_output->setText(targetPath); // Show the exact new path+name.|can be removed

                     file.copy(targetPath); //Actual copy Operation assuming if is true.

                   }
              }
}
