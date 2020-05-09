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
    QStringList file_names;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_FileLocation_clicked()
{   QStringList file_names = QFileDialog::getOpenFileNames(this,"directory","");
    QString file_list = file_names.join(",");

    //ui->textEdit->setText(file_list); Test
    //filter removed ||C://Users/","RVTs,IFCs,NWCs,TXT(*rvt,*ifc,*nwc,*txt)


}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString currenttext = ui->lineEdit->text();
    //ui->textEdit->setText(currenttext);
    //QString rightmost= currenttext.right(4);
   // ui->textEdit_output->setText(rightmost);
}
void MainWindow::calculations()
{

}

void MainWindow::on_textEdit_textChanged()
{
    QStringList file_names = QFileDialog::getOpenFileNames(this,"directory","");
    QString file_list = file_names.join(",");


    //creates input list 1
    QStringList testfilenames;
    testfilenames << "D:/Alex/Code/RevisionRenamer/text.txt";
    testfilenames << "D:/Alex/Code/RevisionRenamer/text2.txt";

   //creates input list 2
   QString Secondcurrenttext = ui->textEdit->toPlainText();
   QStringList splitbyline = Secondcurrenttext.split("\n");


   //stepper to compare values
   for (int j=0;j<file_names.size();j++)
        for (int i=0;i<splitbyline.size();i++)
        {
//            QString rightmost= splitbyline[i].right(3);
//             ui->textEdit_output->setText(rightmost);


           //test codes
           // int numb = QRandomGenerator::global()->generate();
           // QString Texttest = QString::number(numb);
           // ui->textEdit_output->setText(Texttest);
           // ui->comboBox_output->addItem(Texttest);


//   if(testfilenames[j].contains(splitbyline[i]))
//   {
//       QString specificline = splitbyline[i];
//       QString Revision = specificline.right(5);
//       //QString Revision = "P20";

//       QFile singlefile(testfilenames[j]);

//      // ui->comboBox_output->addItem(Revision);
//      // ui->comboBox_output->addItem(specificline);
//      // QString Copyvalue= "D:/Alex/Code/RevisionRenamer/newtext"+Revision+".txt";
//       QString Filetype = ".txt" ;//testfilenames[j].right(4);
//       QString File_notype = testfilenames[j].remove(Filetype);

//       QString Copyvalue= (testfilenames[j]+"_"+Revision+Filetype);//+Revision+Filetype;
//       //QString Copyvalue= testfilenames[i];
//       ui->textEdit_output->setText(File_notype);
//       ui->comboBox_output->addItem(Revision);
//       singlefile.copy(Copyvalue);

//   }


   if(file_names[j].contains(splitbyline[i]))
   {
       QString specificline = splitbyline[i]; //QString Revision = "P20";
       QString Revision = specificline.right(6);
       QFile singlefile(file_names[j]);
       QString Filetype = ".txt" ;
       QString File_notype = file_names[j].remove(Filetype);

       QString Copyvalue= (file_names[j]+"_"+Revision+Filetype);
       ui->textEdit_output->setText(specificline);
       ui->comboBox_output->addItem(Revision);
       singlefile.copy(Copyvalue);}
        }


}

//

