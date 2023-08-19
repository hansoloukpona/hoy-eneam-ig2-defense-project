#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbd = QSqlDatabase::addDatabase("QMYSQL");
    dbd.setHostName("localhost");
    dbd.setDatabaseName("mefsuggest");
    dbd.setUserName("root");
    dbd.setPassword("");
    //db.setPort();
    if(dbd.open())
    {

    }else{
        QMessageBox emptySearchMessage(QMessageBox::Information, tr("Connexion to Database Error"), tr("The database hasn't been open.\n Close the application and relaunch it. If the problem persists, contact the database administrator"), QMessageBox::Ok, this);
        emptySearchMessage.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_suggestionButton_clicked()
{
    QMessageBox quitConfirmaton(QMessageBox::Question, tr("Confirm Enter"), tr("Do you really want to Enter this in the DataBasze ?"), QMessageBox::Yes | QMessageBox::Abort, this);
    int qCVar = quitConfirmaton.exec();

    if (qCVar == QMessageBox::Yes)
    {
        if(dbd.isOpen() == false)
        {
            if(dbd.open())
            {

            }else
            {
                QMessageBox emptySearchMessage(QMessageBox::Information, tr("Connexion to Database Error"), tr("The database hasn't been open.\n Close the application and relaunch it. If the problem persists, contact the database administrator"), QMessageBox::Ok, this);
                emptySearchMessage.exec();
                return;
            }
        }
        QDateTime x;
        QSqlQuery query;
        query.prepare("INSERT INTO suggestions VALUES(NULL, :contenu, :date, :email)");
        query.bindValue(":contenu", ui->suggestionTextEdit->toPlainText());
        query.bindValue(":date", x.currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        query.bindValue(":email", "oloukponah@gmail.com");
        query.exec();
        ui->suggestionTextEdit->clear();
    } else if (qCVar == QMessageBox::Abort)
    {
        // abort
    }
}


void MainWindow::on_complaintButton_clicked()
{
    QMessageBox quitConfirmaton(QMessageBox::Question, tr("Confirm Enter"), tr("Do you really want to Enter this in the DataBasze ?"), QMessageBox::Yes | QMessageBox::Abort, this);
    int qCVar = quitConfirmaton.exec();

    if (qCVar == QMessageBox::Yes)
    {
        if(dbd.isOpen() == false)
        {
            if(dbd.open())
            {

            }else
            {
                QMessageBox emptySearchMessage(QMessageBox::Information, tr("Connexion to Database Error"), tr("The database hasn't been open.\n Close the application and relaunch it. If the problem persists, contact the database administrator"), QMessageBox::Ok, this);
                emptySearchMessage.exec();
                return;
            }
        }
        QDateTime x;
        QSqlQuery query;
        query.prepare("INSERT INTO plaintes VALUES(NULL, :contenu, :date)");
        query.bindValue(":contenu", ui->complaintTextEdit->toPlainText());
        query.bindValue(":date", x.currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        query.exec();
        ui->complaintTextEdit->clear();
    } else if (qCVar == QMessageBox::Abort)
    {
        // abort
    }
}

