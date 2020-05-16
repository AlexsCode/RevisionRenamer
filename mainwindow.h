#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringList file_names; //Set the file names/paths as global
    QStringList splitbyline; //Sets Text input as global


private slots:
    void on_pushButton_FileLocation_clicked(); //Button to start file search.

    void on_textEdit_textChanged(); //Function when main text input recieves text.

    void on_pushButton_Rename_clicked(); //Button to add the Revision.

    void on_pushButton_RemoveRevisions_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
