#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QSqlDatabase>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QFile>
#include <QFileDialog>
#include <QSaveFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void viewerInit();
    void downloadWrite(QString num, QString lib, QString typ, QString str, QByteArray *in);
    QString downloadStrAjust( QString chaine , int ent , QByteArray *inn);
    void positionCenter(QString str, int larg, QByteArray *in);

signals:
    void autoConsultSignal();

private slots:


    void on_quitButton_clicked();

    void on_quit2Button_clicked();

    void on_connect1Button_clicked();

    void on_after1CheckBox_stateChanged(int arg1);

    void on_before1CheckBox_stateChanged(int arg1);

    void on_homeButton2_clicked();

    bool autoConsultFonction();

    void on_resultsButton_clicked();

    bool on_searchButton_clicked();

    void on_connectionOkButton_clicked();

    void on_homeButton3_clicked();

    void on_connectionCancelButton_clicked();

    bool on_after1DateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    bool on_before1DateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_searchComboBox_currentTextChanged(const QString &arg1);

    bool adMinWork(const QString &alpha);

    void on_downloadButton_clicked();

    void on_isRegexRadioButton_clicked(bool checked);

    bool adminAutoConsult();

    void on_isThemeRadioButton_clicked(bool checked);

    void on_isStructureRadioButton_clicked(bool checked);

    void on_adminOKButton_clicked();

    void on_adminCancelButton_clicked();

    void on_addDatButton_clicked();

    void on_deleteDataButton_clicked();

    void on_isRegexRadioButton_2_clicked(bool checked);

    void on_isThemeRadioButton_2_clicked(bool checked);

    void on_isStructureRadioButton_2_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString databaseType ;
    QString hostName ;
    QString databaseName ;
    QString userName ;
    QString password ;
    qint16 port ;
    QStringList themeAndStruct;
    QString searchConsultString;
    QMap <int, QString> structString;
    QMap <int, QString> themeString;
    QString autoConsultString;
    bool admin = false;
    bool inSearch = false;
    QString allString;
    QString whatIsSelect1;
    QString whatIsSelect5;
    QString fromWhere2;
    QString onOrder ;
    QString conditions3;
    QString inThemeCBox ;
    QString inThemeCBox2 ;
    QString and1 ;
    QString and2 ;
    QString and3 ;
    QString searchString ;
    QString searchString2 ;
    QString afterDTimeFirst ;
    QString beforeDTimeSecond ;
    QString afterDTimeFirst2 ;
    QString beforeDTimeSecond2 ;
    QString conditions7;
    QString fromWhere6;
    QString union4;
    QString allString5;
    QString adminString;
    QString themeAShowString;
    QString structAShowString;
    QString insertInto;
    QMap <int, QComboBox*> comboList;
};
#endif // MAINWINDOW_H
