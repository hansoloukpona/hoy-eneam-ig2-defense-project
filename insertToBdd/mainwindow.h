#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

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
    void on_suggestionButton_clicked();

    void on_complaintButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase dbd;

};
#endif // MAINWINDOW_H
