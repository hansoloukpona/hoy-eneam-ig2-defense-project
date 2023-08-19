#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "server.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTableWidget>
#include <QSqlRelationalDelegate>
#include <QVariant>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->after1DateTimeEdit->setEnabled(0);
    ui->before1DateTimeEdit->setEnabled(0);
    ui->textClassifierStackedWidget->setCurrentIndex(0);
    connect(this, SIGNAL(autoConsultSignal()), this, SLOT(autoConsultFonction()));
    viewerInit();
    if(db.open())
    {
        QSqlQuery autoStruct("SELECT structure.Identifiant, structure.Nom FROM structure", db);
        while (autoStruct.next()) {
            structString.insert(autoStruct.value(0).toInt(), autoStruct.value(1).toString());
        }

        allString = "";
        whatIsSelect1 = "";
        fromWhere2 = "";
        onOrder = "";
        conditions3 = "";
        inThemeCBox = "%";
        inThemeCBox2 = "%";
        and1 = "";
        and2 = "";
        and3 = "";
        searchString = "";
        searchString2 = "";
        afterDTimeFirst = "";
        beforeDTimeSecond = "";
        afterDTimeFirst2 = "";
        beforeDTimeSecond2 = "";
        conditions7 = "";
        allString = "SELECT %1 FROM %2 %3 %4 %5 %6"; // SELECT %5 FROM %6 %7 ";
        allString5 ="SELECT %1 FROM %2 %3";
        union4 = " UNION ";

        conditions3 = " WHERE result.Type = '" +tr("Suggestion") + "' AND (theme.Libelle LIKE ('%1') "
                    "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";

        conditions7 = " WHERE result.Type = '" +tr("Complaint") + "' AND (theme.Libelle LIKE ('%1') "
                    "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";

        whatIsSelect1 = " result.id, suggestions.contenu, structure.Nom, result.Type ";

        whatIsSelect5 = " result.id, plaintes.contenu, structure.Nom, result.Type ";

        fromWhere2 = " result INNER JOIN suggestions ON result.Number = suggestions.id "
                    "LEFT JOIN theme ON result.Theme = theme.Identifiant "
                    "LEFT JOIN structure ON result.Structure = structure.Identifiant ";

        fromWhere6 = " result INNER JOIN plaintes ON result.Number = plaintes.id "
                    "LEFT JOIN theme ON result.Theme = theme.Identifiant "
                    "LEFT JOIN structure ON result.Structure = structure.Identifiant ";

        onOrder = " ORDER BY id DESC ";
        conditions3 = conditions3.arg(inThemeCBox).arg(inThemeCBox).arg(and1).arg(searchString).arg(and2).arg(afterDTimeFirst).arg(and3).arg(beforeDTimeSecond);

        conditions7 = conditions7.arg(inThemeCBox2).arg(inThemeCBox2).arg(and1).arg(searchString2).arg(and2).arg(afterDTimeFirst2).arg(and3).arg(beforeDTimeSecond2);

        allString5 = allString5.arg(whatIsSelect5).arg(fromWhere6).arg(conditions7);

        autoConsultString = allString.arg(whatIsSelect1).arg(fromWhere2).arg(conditions3).arg(union4).arg(allString5).arg(onOrder);

        emit autoConsultSignal();
        QSqlQuery autoThemeStructure("SELECT theme.Libelle FROM theme UNION SELECT structure.Nom FROM structure", db);

        while (autoThemeStructure.next()) {
            themeAndStruct << autoThemeStructure.value(0).toString();
        }
        ui->searchComboBox->addItem("");
        ui->searchComboBox->addItems(themeAndStruct);

    }else
    {
        QMessageBox emptySearchMessage(QMessageBox::Information, tr("Connexion to Database Error"), tr("The database hasn't been open.\n Close the application and relaunch it. If the problem persists, contact the database administrator"), QMessageBox::Ok, this);
        emptySearchMessage.exec();
    }
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::viewerInit()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mefsuggest");
    db.setUserName("root");
    db.setPassword("");
    //db.setPort();
}

void MainWindow::downloadWrite(QString num, QString lib, QString typ, QString str, QByteArray *in)
{
    if ( (num.size() > 11 ) ||  (lib.size() > 100) || (typ.size() > 12) || (str.size() > 10))
    {
        num = downloadStrAjust(num, 11, in );
        lib = downloadStrAjust(lib, 100, in );
        typ = downloadStrAjust(typ, 12, in );
        str = downloadStrAjust(str, 10, in );
        in->append("\n");
        downloadWrite(num, lib, typ, str, in);
    }else
    {
        num = downloadStrAjust(num, 11, in );
        lib = downloadStrAjust(lib, 100, in );
        typ = downloadStrAjust(typ, 12, in );
        str = downloadStrAjust(str, 10, in );
        in->append("\n");
    }
}

QString MainWindow::downloadStrAjust(QString chaine, int ent, QByteArray *inn)
{
    if (chaine.size() > ent)
    {
        inn->append("|");
        std::string chFirst = chaine.first(ent).toStdString();
        QByteArray bitFirst = QByteArray::fromStdString(chFirst);
        inn->append(bitFirst);
        inn->append("|");
        chaine = chaine.last(chaine.size() - ent);
    }else
    {
        inn->append("|");
        std::string chFirst = chaine.toStdString();
        QByteArray bitFirst = QByteArray::fromStdString(chFirst);
        inn->append(bitFirst);
        for (int i(0); i < (ent-chaine.size()); i++)
        {
            inn->append(" ");
        }
        inn->append("|");
        chaine = "";
    }
    return chaine;
}

void MainWindow::positionCenter(QString str, int larg, QByteArray *in)
{
    if (((larg/2)-(str.size()/2)) > 0)
    {
        for(int i(0); i < ((larg/2)-(str.size()/2)); i++)
        {
            in->append(" ");
        }
        std::string inter = str.toStdString();
        QByteArray bitInter = QByteArray::fromStdString(inter);
        in->append(bitInter);
        in->append("\n");
    }else
    {
        std::string inter = str.first(larg).toStdString();
        QByteArray bitInter = QByteArray::fromStdString(inter);
        in->append(bitInter);
        in->append("\n");
        positionCenter(str.last(str.size()-larg), larg, in);
    }
}

bool MainWindow::adMinWork(const QString &alpha)
{
    int iAlpha(0);
    bool itWork;
    QComboBox *combo = qobject_cast<QComboBox *>(sender());
    if (combo == 0)     // Si par hasard on n'a pas trouvé le comboboc à l'origine du signal, on arrête la méthode
    {
        return false;
    }else
    {
        QMapIterator<int, QString> j(structString);
        while (j.hasNext()) {
            j.next();
            if (j.value() == alpha)
            {
                iAlpha = j.key();
            }
        }
        if( iAlpha == 0)
        {
            return false;
        }
    }

    QMapIterator<int, QComboBox*> i(comboList);
    while (i.hasNext()) {
        i.next();
        if (i.value() == combo)
        {
            QSqlQuery  updateRequest;
            updateRequest.prepare("UPDATE result SET Structure=:struct WHERE id=:id");
            updateRequest.bindValue(":struct", iAlpha);
            updateRequest.bindValue(":id", i.key());
            itWork = updateRequest.exec();
        }
    }
    return itWork;
}

bool MainWindow::autoConsultFonction()
{
    inSearch = false;
    if(db.isOpen() == false)
    {
        if(db.open())
        {

        }else
        {
            QMessageBox emptySearchMessage(QMessageBox::Information, tr("Connexion to Database Error"), tr("The database hasn't been open.\n Close the application and relaunch it. If the problem persists, contact the database administrator"), QMessageBox::Ok, this);
            emptySearchMessage.exec();
            return false;
        }
    }

    QSqlQuery autoConsultQuery(autoConsultString, db);
    //On peut faire un count sur le nombre de ligne que renvoie la requète
    ui->firstTableWidget->setRowCount(autoConsultQuery.size());
    if(admin == false)
    {
        ui->firstTableWidget->setColumnCount(4);
        int row = 0;
        while (autoConsultQuery.next()) {
            for (int column = 0; column < ui->firstTableWidget->columnCount(); ++column)
            {
                if( column == 0 || column == 1 || column == 2 || column == 3)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(autoConsultQuery.value(column).toString() );
                    ui->firstTableWidget->setItem(row, column, item);
                }
            }
            ++row;
        }
        ui->firstTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->firstTableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
        //ui->firstTableWidget->sortByColumn(0, Qt::DescendingOrder);
        ui->firstTableWidget->show();
        return true;
    }else
    {
        ui->firstTableWidget->setColumnCount(5);
        ui->firstTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("ADMIN VALIDATION")));
        int row = 0;
        while (autoConsultQuery.next()) {
            for (int column = 0; column < ui->firstTableWidget->columnCount(); ++column) {
                if( column == 0 || column == 1 || column == 2 || column == 3)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(autoConsultQuery.value(column).toString() );
                    ui->firstTableWidget->setItem(row, column, item);

                }else if( column == 4 )
                {
                    QComboBox *o = new QComboBox(this);
                    QMapIterator<int, QString> j(structString);
                    while (j.hasNext()) {
                        j.next();
                        o->addItem(j.value());
                    }
                    ui->firstTableWidget->setCellWidget(row, column, o);
                    o->setCurrentText(autoConsultQuery.value(2).toString());
                    comboList.insert(autoConsultQuery.value(0).toInt(), o);

                    connect(o, SIGNAL(currentTextChanged(QString)), this, SLOT(adMinWork(QString)));
                }
            }
            ++row;
        }
        ui->firstTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->firstTableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
        ui->firstTableWidget->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
        ui->firstTableWidget->show();
        return true;
    }
}


void MainWindow::on_quitButton_clicked()
{
    QMessageBox quitConfirmaton(QMessageBox::Question, tr("Confirm Exit"), tr("Do you really want to quit the Classifier ?"), QMessageBox::Yes | QMessageBox::Abort, this);
    int qCVar = quitConfirmaton.exec();

    if (qCVar == QMessageBox::Yes)
    {
        // quit the Application
        QApplication::quit();
    } else if (qCVar == QMessageBox::Abort)
    {
        // abort
    }
}


void MainWindow::on_quit2Button_clicked()
{
    QMessageBox quitConfirmaton(QMessageBox::Question, tr("Confirm Exit"), tr("Do you really want to quit the Classifier ?"), QMessageBox::Yes | QMessageBox::Abort, this);
    int qCVar = quitConfirmaton.exec();

    if (qCVar == QMessageBox::Yes)
    {
        // quit the Application
        QApplication::quit();
    } else if (qCVar == QMessageBox::Abort)
    {
        // abort
    }
}

void MainWindow::on_connect1Button_clicked()
{
    ui->textClassifierStackedWidget->setCurrentIndex(1);
}


void MainWindow::on_after1CheckBox_stateChanged(int arg1)
{
    if(arg1 == 0)
    {
        and2 = "";
        afterDTimeFirst = "";
        afterDTimeFirst2 = "";
        ui->after1DateTimeEdit->setEnabled(0);
        if(inSearch == true)
        {
            on_searchButton_clicked();
        }else
        {
            allString = "SELECT %1 FROM %2 %3 %4 %5 %6"; // SELECT %5 FROM %6 %7 ";
            allString5 ="SELECT %1 FROM %2 %3";

            conditions3 = " WHERE result.Type = '" +tr("Suggestion") + "' AND (theme.Libelle LIKE ('%1') "
                        "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
            conditions7 = " WHERE result.Type = '" +tr("Complaint") + "' AND (theme.Libelle LIKE ('%1') "
                        "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
            conditions3 = conditions3.arg(inThemeCBox).arg(inThemeCBox).arg(and1).arg(searchString).arg(and2).arg(afterDTimeFirst).arg(and3).arg(beforeDTimeSecond);
            conditions7 = conditions7.arg(inThemeCBox2).arg(inThemeCBox2).arg(and1).arg(searchString2).arg(and2).arg(afterDTimeFirst2).arg(and3).arg(beforeDTimeSecond2);
            allString5 = allString5.arg(whatIsSelect5).arg(fromWhere6).arg(conditions7);
            autoConsultString = allString.arg(whatIsSelect1).arg(fromWhere2).arg(conditions3).arg(union4).arg(allString5).arg(onOrder);
            emit autoConsultSignal();
        }
    }else if(arg1 == 2)
    {
        ui->after1DateTimeEdit->setEnabled(1);
        and2 = " AND ";
        afterDTimeFirst = " suggestions.created_at > '" + ui->after1DateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")+ "' ";
        allString = "SELECT %1 FROM %2 %3 %4 %5 %6"; // SELECT %5 FROM %6 %7 ";
        allString5 ="SELECT %1 FROM %2 %3";
        conditions3 = " WHERE result.Type = '" +tr("Suggestion") + "' AND (theme.Libelle LIKE ('%1') "
                    "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
        conditions7 = " WHERE result.Type = '" +tr("Complaint") + "' AND (theme.Libelle LIKE ('%1') "
                    "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
        conditions3 = conditions3.arg(inThemeCBox).arg(inThemeCBox).arg(and1).arg(searchString).arg(and2).arg(afterDTimeFirst).arg(and3).arg(beforeDTimeSecond);

        afterDTimeFirst2 = " plaintes.created_at > '" + ui->after1DateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")+ "' ";
        conditions7 = conditions7.arg(inThemeCBox2).arg(inThemeCBox2).arg(and1).arg(searchString2).arg(and2).arg(afterDTimeFirst2).arg(and3).arg(beforeDTimeSecond2);

        allString5 = allString5.arg(whatIsSelect5).arg(fromWhere6).arg(conditions7);
        autoConsultString = allString.arg(whatIsSelect1).arg(fromWhere2).arg(conditions3).arg(union4).arg(allString5).arg(onOrder);
    }
}


void MainWindow::on_before1CheckBox_stateChanged(int arg1)
{
    if(arg1 == 0)
    {
        and3 = "";
        beforeDTimeSecond = "";
        beforeDTimeSecond2 = "";
        ui->before1DateTimeEdit->setEnabled(0);
        if(inSearch == true)
        {
            on_searchButton_clicked();
        }else
        {
            allString = "SELECT %1 FROM %2 %3 %4 %5 %6"; // SELECT %5 FROM %6 %7 ";
            allString5 ="SELECT %1 FROM %2 %3";

            conditions3 = " WHERE result.Type = '" +tr("Suggestion") + "' AND (theme.Libelle LIKE ('%1') "
                        "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
            conditions7 = " WHERE result.Type = '" +tr("Complaint") + "' AND (theme.Libelle LIKE ('%1') "
                        "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
            conditions3 = conditions3.arg(inThemeCBox).arg(inThemeCBox).arg(and1).arg(searchString).arg(and2).arg(afterDTimeFirst).arg(and3).arg(beforeDTimeSecond);
            conditions7 = conditions7.arg(inThemeCBox2).arg(inThemeCBox2).arg(and1).arg(searchString2).arg(and2).arg(afterDTimeFirst2).arg(and3).arg(beforeDTimeSecond2);
            allString5 = allString5.arg(whatIsSelect5).arg(fromWhere6).arg(conditions7);
            autoConsultString = allString.arg(whatIsSelect1).arg(fromWhere2).arg(conditions3).arg(union4).arg(allString5).arg(onOrder);
            emit autoConsultSignal();

        }
    }else if(arg1 == 2)
    {
        ui->before1DateTimeEdit->setEnabled(1);
        and3 = " AND ";
        beforeDTimeSecond = " suggestions.created_at < '" + ui->before1DateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")+ "' ";
        beforeDTimeSecond2 = " plaintes.created_at < '" + ui->before1DateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")+ "' ";
        allString = "SELECT %1 FROM %2 %3 %4 %5 %6"; // SELECT %5 FROM %6 %7 ";
        allString5 ="SELECT %1 FROM %2 %3";

        conditions3 = " WHERE result.Type = '" +tr("Suggestion") + "' AND (theme.Libelle LIKE ('%1') "
                    "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
        conditions7 = " WHERE result.Type = '" +tr("Complaint") + "' AND (theme.Libelle LIKE ('%1') "
                    "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
        conditions3 = conditions3.arg(inThemeCBox).arg(inThemeCBox).arg(and1).arg(searchString).arg(and2).arg(afterDTimeFirst).arg(and3).arg(beforeDTimeSecond);
        conditions7 = conditions7.arg(inThemeCBox2).arg(inThemeCBox2).arg(and1).arg(searchString2).arg(and2).arg(afterDTimeFirst2).arg(and3).arg(beforeDTimeSecond2);
        allString5 = allString5.arg(whatIsSelect5).arg(fromWhere6).arg(conditions7);
        autoConsultString = allString.arg(whatIsSelect1).arg(fromWhere2).arg(conditions3).arg(union4).arg(allString5).arg(onOrder);
    }
}


void MainWindow::on_homeButton2_clicked()
{
    ui->textClassifierStackedWidget->setCurrentIndex(0);
}


void MainWindow::on_resultsButton_clicked()
{
    inSearch = false;
    //inStatics = false;
    and1 = "";
    searchString = "";
    searchString2 = "";
    allString = "SELECT %1 FROM %2 %3 %4 %5 %6"; // SELECT %5 FROM %6 %7 ";
    allString5 ="SELECT %1 FROM %2 %3";

    conditions3 = " WHERE result.Type = '" +tr("Suggestion") + "' AND (theme.Libelle LIKE ('%1') "
                "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
    conditions7 = " WHERE result.Type = '" +tr("Complaint") + "' AND (theme.Libelle LIKE ('%1') "
                "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
    conditions3 = conditions3.arg(inThemeCBox).arg(inThemeCBox).arg(and1).arg(searchString).arg(and2).arg(afterDTimeFirst).arg(and3).arg(beforeDTimeSecond);
    conditions7 = conditions7.arg(inThemeCBox2).arg(inThemeCBox2).arg(and1).arg(searchString2).arg(and2).arg(afterDTimeFirst2).arg(and3).arg(beforeDTimeSecond2);
    allString5 = allString5.arg(whatIsSelect5).arg(fromWhere6).arg(conditions7);
    autoConsultString = allString.arg(whatIsSelect1).arg(fromWhere2).arg(conditions3).arg(union4).arg(allString5).arg(onOrder);
    emit autoConsultSignal();
    ui->searchEdit->clear();
}


bool MainWindow::on_searchButton_clicked()
{
    if(ui->searchEdit->text().isEmpty())
    {
        and1 = "";
        searchString = "";
        QMessageBox emptySearchMessage(QMessageBox::Information, tr("Empty Search"), tr("You have enterred no data to search now.\n Do it to get pertinents results."), QMessageBox::Ok, this);
        emptySearchMessage.exec();
        inSearch = false;
        return true;
    }else
    {
        if(ui->after1CheckBox->isChecked() && ui->before1CheckBox->isChecked() && ( ui->before1DateTimeEdit->dateTime() < ui->after1DateTimeEdit->dateTime() ))
        {
            QMessageBox befAndAfter(QMessageBox::Information, tr("Error On the Dates"), tr("Check the date and time you enterred.\n The before datetime is superior to the after datetime."), QMessageBox::Ok, this);
            befAndAfter.exec();
            return false;
        }
        //inStat = false;
        inSearch = true;
        and1 = " AND ";
        searchString = " suggestions.contenu LIKE('%" + ui->searchEdit->text() +"%') ";
        searchString2 = " plaintes.contenu LIKE('%" + ui->searchEdit->text() +"%') ";
        allString = "SELECT %1 FROM %2 %3 %4 %5 %6"; // SELECT %5 FROM %6 %7 ";
        allString5 ="SELECT %1 FROM %2 %3";

        conditions3 = " WHERE result.Type = '" +tr("Suggestion") + "' AND (theme.Libelle LIKE ('%1') "
                    "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
        conditions7 = " WHERE result.Type = '" +tr("Complaint") + "' AND (theme.Libelle LIKE ('%1') "
                    "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
        conditions3 = conditions3.arg(inThemeCBox).arg(inThemeCBox).arg(and1).arg(searchString).arg(and2).arg(afterDTimeFirst).arg(and3).arg(beforeDTimeSecond);
        conditions7 = conditions7.arg(inThemeCBox2).arg(inThemeCBox2).arg(and1).arg(searchString2).arg(and2).arg(afterDTimeFirst2).arg(and3).arg(beforeDTimeSecond2);
        allString5 = allString5.arg(whatIsSelect5).arg(fromWhere6).arg(conditions7);
        autoConsultString = allString.arg(whatIsSelect1).arg(fromWhere2).arg(conditions3).arg(union4).arg(allString5).arg(onOrder);

    }
    if(db.isOpen() == false)
    {
        if(db.open())
        {

        }else
        {
            QMessageBox emptySearchMessage(QMessageBox::Information, tr("Connexion to Database Error"), tr("The database hasn't been open.\n Close the application and relaunch it. If the problem persists, contact the database administrator"), QMessageBox::Ok, this);
            emptySearchMessage.exec();
            return false;
        }
    }
    if(admin == false)
    {
        //QSqlQuery searchConsultQuery(searchConsultString, db);
        QSqlQuery searchConsultQuery(autoConsultString, db);
        int row = 0;
        ui->firstTableWidget->clearContents();
        ui->firstTableWidget->setRowCount(searchConsultQuery.size());
        while (searchConsultQuery.next()) {
            for (int column = 0; column < ui->firstTableWidget->columnCount(); ++column) {
                if( column == 0 || column == 1 || column == 2 || column == 3)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(searchConsultQuery.value(column).toString() );
                    ui->firstTableWidget->setItem(row, column, item);
                }
            }
            ++row;
        }
        return true;
    }else if(admin == true)
    {
        //QSqlQuery searchConsultQuery(searchConsultString, db);
        QSqlQuery searchConsultQuery(autoConsultString, db);
        int row = 0;
        ui->firstTableWidget->clearContents();
        ui->firstTableWidget->setRowCount(searchConsultQuery.size());
        ui->firstTableWidget->setColumnCount(5);
        ui->firstTableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("ADMIN VALIDATION")));
        while (searchConsultQuery.next()) {
            for (int column = 0; column < ui->firstTableWidget->columnCount(); ++column) {
                if( column == 0 || column == 1 || column == 2 || column == 3)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(searchConsultQuery.value(column).toString() );
                    ui->firstTableWidget->setItem(row, column, item);
                }else if( column == 4 )
                {
                    QComboBox *o = new QComboBox();
                    QMapIterator<int, QString> j(structString);
                    while (j.hasNext()) {
                        j.next();
                        o->addItem(j.value());
                    }
                    ui->firstTableWidget->setCellWidget(row, column, o);
                    o->setCurrentText(searchConsultQuery.value(2).toString());
                    comboList.insert(searchConsultQuery.value(0).toInt(), o);
                    connect(o, SIGNAL(currentTextChanged(QString)), this, SLOT(adMinWork(QString)));
                }
            }
            ++row;
        }
        return true;
    }
}

void MainWindow::on_connectionOkButton_clicked()
{
    db.close();
    if(ui->databaseConnexionPortSpinBox->value() == 0)
    {
        db.setHostName( ui->databaseHostNameEdit->text());
        db.setUserName( ui->databaseUserNameEdit->text());
        db.setPassword(ui->databaseUserPasswordEdit->text());
        //db.setPort();
        if(db.open())
        {
            admin = true;
            ui->textClassifierStackedWidget->setCurrentIndex(2);
            if(inSearch == true)
            {
                on_searchButton_clicked();
            }else{
                emit autoConsultSignal();
            }
            QSqlQuery forThemeChoice("SELECT theme.Identifiant, theme.Libelle FROM theme", db);
            while (forThemeChoice.next()) {
                themeString.insert(forThemeChoice.value(0).toInt(), forThemeChoice.value(1).toString());
            }
            QMapIterator<int, QString> j(themeString);
            while (j.hasNext()) {
                j.next();
                ui->themeForRegexComboBox->addItem(j.value());
                ui->themeForRegexComboBox_2->addItem(j.value());
            }
            QStringList longerList = (QStringList() << "1" << "2" << "3");
            ui->verbGroupComboBox->addItems(longerList);
        }else
        {
            ui->connectionNotWorkLabel->setText(tr("Some information aren't correct. Please Retry or Contact te Database Admin"));
            viewerInit();
            db.open();
        }
    }else
    {
        db.setHostName( ui->databaseHostNameEdit->text());
        db.setUserName( ui->databaseUserNameEdit->text());
        db.setPassword(ui->databaseUserPasswordEdit->text());
        db.setPort(ui->databaseConnexionPortSpinBox->value());
        if(db.open())
        {
            admin = true;
            ui->textClassifierStackedWidget->setCurrentIndex(2);
            if(inSearch == true)
            {
                on_searchButton_clicked();
            }else{
                emit autoConsultSignal();
            }
            QSqlQuery forThemeChoice("SELECT theme.Identifiant, theme.Libelle FROM theme", db);
            while (forThemeChoice.next()) {
                themeString.insert(forThemeChoice.value(0).toInt(), forThemeChoice.value(1).toString());
            }
            QMapIterator<int, QString> j(themeString);
            while (j.hasNext()) {
                j.next();
                ui->themeForRegexComboBox->addItem(j.value());
                ui->themeForRegexComboBox_2->addItem(j.value());
            }
            QStringList longerList = (QStringList() << "1" << "2" << "3");
            ui->verbGroupComboBox->addItems(longerList);
        }else
        {
            ui->connectionNotWorkLabel->setText(tr("Some information aren't correct. Please Retry or Contact te Database Admin"));
            viewerInit();
            db.open();
        }
    }
}


void MainWindow::on_homeButton3_clicked()
{
    ui->textClassifierStackedWidget->setCurrentIndex(0);
}


void MainWindow::on_connectionCancelButton_clicked()
{
    QMessageBox cancelConfirmaton(QMessageBox::Question, tr("Confirm Cancel"), tr("Do you really want to cancel connect process ?\n This will erase all information you have enterred."), QMessageBox::Yes | QMessageBox::Abort, this);
    int cCVar = cancelConfirmaton.exec();

    if (cCVar == QMessageBox::Yes)
    {
        ui->databaseHostNameEdit->clear();
        ui->databaseUserNameEdit->clear();
        ui->databaseUserPasswordEdit->clear();
        ui->databaseConnexionPortSpinBox->clear();
    } else if (cCVar == QMessageBox::Abort)
    {
        // abort
    }
}


bool MainWindow::on_after1DateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    if(ui->after1CheckBox->isChecked() && ui->before1CheckBox->isChecked() && ( ui->before1DateTimeEdit->dateTime() < ui->after1DateTimeEdit->dateTime() ))
    {
        QMessageBox befAndAfter(QMessageBox::Information, tr("Error On the Dates"), tr("Check the date and time you enterred.\n The before datetime is superior to the after datetime."), QMessageBox::Ok, this);
        befAndAfter.exec();
        return false;
    }
    and2 = " AND ";
    afterDTimeFirst = " suggestions.created_at > '" + dateTime.toString("yyyy-MM-dd hh:mm:ss")+ "' ";
    afterDTimeFirst2 = " plaintes.created_at > '" + dateTime.toString("yyyy-MM-dd hh:mm:ss")+ "' ";
    allString = "SELECT %1 FROM %2 %3 %4 %5 %6"; // SELECT %5 FROM %6 %7 ";
    allString5 ="SELECT %1 FROM %2 %3";

    conditions3 = " WHERE result.Type = '" +tr("Suggestion") + "' AND (theme.Libelle LIKE ('%1') "
                "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
    conditions7 = " WHERE result.Type = '" +tr("Complaint") + "' AND (theme.Libelle LIKE ('%1') "
                "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
    conditions3 = conditions3.arg(inThemeCBox).arg(inThemeCBox).arg(and1).arg(searchString).arg(and2).arg(afterDTimeFirst).arg(and3).arg(beforeDTimeSecond);
    conditions7 = conditions7.arg(inThemeCBox2).arg(inThemeCBox2).arg(and1).arg(searchString2).arg(and2).arg(afterDTimeFirst2).arg(and3).arg(beforeDTimeSecond2);
    allString5 = allString5.arg(whatIsSelect5).arg(fromWhere6).arg(conditions7);
    autoConsultString = allString.arg(whatIsSelect1).arg(fromWhere2).arg(conditions3).arg(union4).arg(allString5).arg(onOrder);
    emit autoConsultSignal();
    return true;
}


bool MainWindow::on_before1DateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    if(ui->after1CheckBox->isChecked() && ui->before1CheckBox->isChecked() && ( ui->before1DateTimeEdit->dateTime() < ui->after1DateTimeEdit->dateTime() ))
    {
        QMessageBox befAndAfter(QMessageBox::Information, tr("Error On the Dates"), tr("Check the date and time you enterred.\n The before datetime is superior to the after datetime."), QMessageBox::Ok, this);
        befAndAfter.exec();
        return false;
    }
    and3 = " AND ";
    beforeDTimeSecond = " suggestions.created_at < '" + dateTime.toString("yyyy-MM-dd hh:mm:ss")+ "' ";
    beforeDTimeSecond2 = " plaintes.created_at < '" + dateTime.toString("yyyy-MM-dd hh:mm:ss")+ "' ";
    allString = "SELECT %1 FROM %2 %3 %4 %5 %6"; // SELECT %5 FROM %6 %7 ";
    allString5 ="SELECT %1 FROM %2 %3";

    conditions3 = " WHERE result.Type = '" +tr("Suggestion") + "' AND (theme.Libelle LIKE ('%1') "
                "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
    conditions7 = " WHERE result.Type = '" +tr("Complaint") + "' AND (theme.Libelle LIKE ('%1') "
                "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
    conditions3 = conditions3.arg(inThemeCBox).arg(inThemeCBox).arg(and1).arg(searchString).arg(and2).arg(afterDTimeFirst).arg(and3).arg(beforeDTimeSecond);
    conditions7 = conditions7.arg(inThemeCBox2).arg(inThemeCBox2).arg(and1).arg(searchString2).arg(and2).arg(afterDTimeFirst2).arg(and3).arg(beforeDTimeSecond2);
    allString5 = allString5.arg(whatIsSelect5).arg(fromWhere6).arg(conditions7);
    autoConsultString = allString.arg(whatIsSelect1).arg(fromWhere2).arg(conditions3).arg(union4).arg(allString5).arg(onOrder);
    if(inSearch == false)
    {
        emit autoConsultSignal();
    }
    return true;

}


void MainWindow::on_searchComboBox_currentTextChanged(const QString &arg1)
{
    inThemeCBox = arg1;
    inThemeCBox2 = arg1;
    if (arg1 == "")
    {
        inThemeCBox = "%";
        inThemeCBox2 = "%";
    }
    allString = "SELECT %1 FROM %2 %3 %4 %5 %6"; // SELECT %5 FROM %6 %7 ";
    allString5 ="SELECT %1 FROM %2 %3";

    conditions3 = " WHERE result.Type = '" +tr("Suggestion") + "' AND (theme.Libelle LIKE ('%1') "
                "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
    conditions7 = " WHERE result.Type = '" +tr("Complaint") + "' AND (theme.Libelle LIKE ('%1') "
                "OR (structure.Nom LIKE ('%2') OR result.Structure = 0)) %3 %4 %5 %6 %7 %8";
    conditions3 = conditions3.arg(inThemeCBox).arg(inThemeCBox).arg(and1).arg(searchString).arg(and2).arg(afterDTimeFirst).arg(and3).arg(beforeDTimeSecond);
    conditions7 = conditions7.arg(inThemeCBox2).arg(inThemeCBox2).arg(and1).arg(searchString2).arg(and2).arg(afterDTimeFirst2).arg(and3).arg(beforeDTimeSecond2);
    allString5 = allString5.arg(whatIsSelect5).arg(fromWhere6).arg(conditions7);
    autoConsultString = allString.arg(whatIsSelect1).arg(fromWhere2).arg(conditions3).arg(union4).arg(allString5).arg(onOrder);
    emit autoConsultSignal();
}

void MainWindow::on_downloadButton_clicked()
{
    QByteArray file;
    QByteArray *inPtr = &file;
    positionCenter("MINISTÈRE DE L'ÉCONOMIE ET DES FINANCES", 133, inPtr);
    QDateTime downloadDT = QDateTime::currentDateTime();
    positionCenter(downloadDT.toString("'Date' : dd/MMMM/yyyy "+ tr("'At'") + " hh:mm"), 133, inPtr);
    //tr("Results, Searchs, Statistics

    for (int row(0); row < ui->firstTableWidget->rowCount(); row++)
    {
        downloadWrite(ui->firstTableWidget->item(row, 0)->text(), ui->firstTableWidget->item(row, 1)->text(), ui->firstTableWidget->item(row, 2)->text(), ui->firstTableWidget->item(row, 3)->text(), inPtr);
    }

    QFileDialog::saveFileContent(file, "download.txt");


}


void MainWindow::on_isRegexRadioButton_clicked(bool checked)
{
    if (checked == true)
    {
        adminString = "SELECT dictionnaire.Regex, theme.Libelle as Theme FROM dictionnaire INNER JOIN theme ON dictionnaire.Theme = theme.Identifiant ";
        adminAutoConsult();
        ui->isVerbCheckBox->setEnabled(true);
        ui->verbGroupComboBox->setEnabled(true);
        ui->themeForRegexComboBox->setEnabled(true);
        ui->themeForRegexLabel->setEnabled(true);
        ui->pluralCheckBox->setEnabled(true);
        ui->pluralLineEdit->setEnabled(true);
        ui->prefixCheckBox->setEnabled(true);
        ui->prefixLineEdit->setEnabled(true);
        ui->suffixCheckBox->setEnabled(true);
        ui->suffixLineEdit->setEnabled(true);
        insertInto = "dictionnaire";

    }
}

bool MainWindow::adminAutoConsult()
{
    inSearch = false;
    //inStat = false;
    if(db.isOpen() == false)
    {
        if(db.open())
        {

        }else
        {
            QMessageBox emptySearchMessage(QMessageBox::Information, tr("Connexion to Database Error"), tr("The database hasn't been open.\n Close the application and relaunch it. If the problem persists, contact the database administrator"), QMessageBox::Ok, this);
            emptySearchMessage.exec();
            return false;
        }
    }
    QSqlQuery adminShow(adminString, db);
    ui->addDelTableWidget->setRowCount(adminShow.size());
    if(admin == true)
    {
        ui->addDelTableWidget->setColumnCount(2);
        int row = 0;
        while (adminShow.next()) {
            for (int column = 0; column < ui->addDelTableWidget->columnCount(); column++)
            {
                QTableWidgetItem *item = new QTableWidgetItem(adminShow.value(column).toString() );
                ui->addDelTableWidget->setItem(row, column, item);
            }
            ++row;
        }
        ui->addDelTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->addDelTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        //ui->addDelTableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
        //ui->firstTableWidget->sortByColumn(0, Qt::DescendingOrder);
        ui->addDelTableWidget->show();
        return true;
    }
}

void MainWindow::on_isThemeRadioButton_clicked(bool checked)
{
    if (checked == true)
    {
        adminString = "SELECT theme.Identifiant, theme.Libelle, structure.Nom FROM theme INNER JOIN structure ON theme.Structure = structure.Identifiant";
        adminAutoConsult();
        ui->isVerbCheckBox->setEnabled(false);
        ui->verbGroupComboBox->setEnabled(false);
        ui->themeForRegexComboBox->setEnabled(false);
        ui->themeForRegexLabel->setEnabled(false);
        ui->pluralCheckBox->setEnabled(false);
        ui->pluralLineEdit->setEnabled(false);
        ui->prefixCheckBox->setEnabled(false);
        ui->prefixLineEdit->setEnabled(false);
        ui->suffixCheckBox->setEnabled(false);
        ui->suffixLineEdit->setEnabled(false);
        insertInto = "theme";

    }
}


void MainWindow::on_isStructureRadioButton_clicked(bool checked)
{
    if (checked == true)
    {
        adminString = "SELECT structure.Identifiant, structure.Nom FROM structure";
        adminAutoConsult();
        ui->isVerbCheckBox->setEnabled(false);
        ui->verbGroupComboBox->setEnabled(false);
        ui->themeForRegexComboBox->setEnabled(false);
        ui->themeForRegexLabel->setEnabled(false);
        ui->pluralCheckBox->setEnabled(false);
        ui->pluralLineEdit->setEnabled(false);
        ui->prefixCheckBox->setEnabled(false);
        ui->prefixLineEdit->setEnabled(false);
        ui->suffixCheckBox->setEnabled(false);
        ui->suffixLineEdit->setEnabled(false);
        insertInto = "structure";
    }
}


void MainWindow::on_adminOKButton_clicked()
{
    if (ui->beforeConfirmationLabel->text().isEmpty())
    {
        QMessageBox dataAlreadyExist(QMessageBox::Information, tr("Data not exist"), tr("No data have been generated.\n"), QMessageBox::Ok, this);
        dataAlreadyExist.exec();
        return;
    }
    QString adminInsert = ui->beforeConfirmationLabel->text();
    if (insertInto == "structure" ||  insertInto == "theme")
    {
        for (int row(0); row < ui->addDelTableWidget->rowCount(); row++) {
            for (int column = 1; column < ui->addDelTableWidget->columnCount(); column++)
            {
                if (adminInsert == ui->addDelTableWidget->item(row, column)->text())
                {
                    QMessageBox dataAlreadyExist(QMessageBox::Information, tr("Data already exist"), tr("The data you want to insert already exist.\n"), QMessageBox::Ok, this);
                    dataAlreadyExist.exec();
                    return;
                }
            }
        }
        QString requestString = "INSERT INTO " + insertInto + " VALUES (NULL, " + adminInsert + " )";
        QSqlQuery requestQuery(requestString, db);
    }else if (insertInto == "dictionnaire")
    {
        for (int row(0); row < ui->addDelTableWidget->rowCount(); row++) {
            for (int column = 0; column < (ui->addDelTableWidget->columnCount()-1); column++)
            {
                if (adminInsert == ui->addDelTableWidget->item(row, column)->text())
                {
                    QMessageBox dataAlreadyExist(QMessageBox::Information, tr("Data already exist"), tr("The data you want to insert already exist.\n"), QMessageBox::Ok, this);
                    dataAlreadyExist.exec();
                    return;
                }
            }
        }
        QString requestString = "";
        QMapIterator<int, QString> j(themeString);
        while (j.hasNext()) {
            j.next();
            if (j.value() == ui->themeForRegexComboBox->currentText())
            {
                requestString = "INSERT INTO %1 VALUES ( %2, %3 )";
                requestString = requestString.arg(insertInto).arg(adminInsert).arg(j.key());
            }
        }
        QSqlQuery requestQuery(requestString, db);
    }
}


void MainWindow::on_adminCancelButton_clicked()
{
    ui->isVerbCheckBox->setChecked(false);
    ui->verbGroupComboBox->setCurrentIndex(-1);
    ui->pluralCheckBox->setChecked(false);
    ui->pluralLineEdit->clear();
    ui->prefixCheckBox->setChecked(false);
    ui->prefixLineEdit->clear();
    ui->suffixCheckBox->setChecked(false);
    ui->suffixLineEdit->clear();
}


void MainWindow::on_addDatButton_clicked()
{
    ui->adminDataStackedWidget->setCurrentIndex(0);
}


void MainWindow::on_deleteDataButton_clicked()
{
    ui->adminDataStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_isRegexRadioButton_2_clicked(bool checked)
{
    if (checked == true)
    {
        adminString = "SELECT dictionnaire.Regex, theme.Libelle as Theme FROM dictionnaire INNER JOIN theme ON dictionnaire.Theme = theme.Identifiant ";
        adminAutoConsult();
        ui->isVerbCheckBox_2->setEnabled(true);
        ui->verbGroupComboBox_2->setEnabled(true);
        ui->pluralCheckBox_2->setEnabled(true);
        ui->pluralLineEdit_2->setEnabled(true);
        ui->prefixCheckBox_2->setEnabled(true);
        ui->prefixLineEdit_2->setEnabled(true);
        ui->suffixCheckBox_2->setEnabled(true);
        ui->suffixLineEdit_2->setEnabled(true);
        insertInto = "dictionnaire";

    }
}


void MainWindow::on_isThemeRadioButton_2_clicked(bool checked)
{
    if (checked == true)
    {
        adminString = "SELECT theme.Identifiant, theme.Libelle, structure.Nom FROM theme INNER JOIN structure ON theme.Structure = structure.Identifiant";
        adminAutoConsult();
        ui->isVerbCheckBox_2->setEnabled(false);
        ui->verbGroupComboBox_2->setEnabled(false);
        ui->themeForRegexComboBox_2->setEnabled(false);
        ui->themeForRegexLabel_2->setEnabled(false);
        ui->pluralCheckBox_2->setEnabled(false);
        ui->pluralLineEdit_2->setEnabled(false);
        ui->prefixCheckBox_2->setEnabled(false);
        ui->prefixLineEdit_2->setEnabled(false);
        ui->suffixCheckBox_2->setEnabled(false);
        ui->suffixLineEdit_2->setEnabled(false);
        insertInto = "theme";

    }
}


void MainWindow::on_isStructureRadioButton_2_clicked(bool checked)
{
    if (checked == true)
    {
        adminString = "SELECT structure.Identifiant, structure.Nom FROM structure";
        adminAutoConsult();
        ui->isVerbCheckBox_2->setEnabled(false);
        ui->verbGroupComboBox_2->setEnabled(false);
        ui->themeForRegexComboBox_2->setEnabled(false);
        ui->themeForRegexLabel_2->setEnabled(false);
        ui->pluralCheckBox_2->setEnabled(false);
        ui->pluralLineEdit_2->setEnabled(false);
        ui->prefixCheckBox_2->setEnabled(false);
        ui->prefixLineEdit_2->setEnabled(false);
        ui->suffixCheckBox_2->setEnabled(false);
        ui->suffixLineEdit_2->setEnabled(false);
        insertInto = "structure";
    }
}

