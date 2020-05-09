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

private slots:
    void on_pushButton_FileLocation_clicked();

    void on_textEdit_textChanged();

    void on_lineEdit_textChanged(const QString &arg1);

    void calculations();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H