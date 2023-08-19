/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSe_Connecter;
    QAction *actionT_l_charger;
    QAction *actionT_l_charger_2;
    QAction *actionQuit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *textClassifierStackedWidget;
    QWidget *displayPage;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitButton;
    QPushButton *resultsButton;
    QPushButton *downloadButton;
    QPushButton *statisticsButton;
    QPushButton *connect1Button;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_15;
    QGridLayout *gridLayout_6;
    QComboBox *searchComboBox;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *before1CheckBox;
    QDateTimeEdit *before1DateTimeEdit;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *after1CheckBox;
    QDateTimeEdit *after1DateTimeEdit;
    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QTableWidget *firstTableWidget;
    QWidget *settingPage;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *applicationTitle;
    QSpacerItem *verticalSpacer;
    QLabel *databaseUserNameLabel;
    QLabel *obligatoryInformationLabel;
    QLabel *databaseConnexionPortLabel;
    QLabel *databaseUserPasswordLabel;
    QLabel *databaseHostNameLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *connectionOkButton;
    QPushButton *connectionCancelButton;
    QLineEdit *databaseUserNameEdit;
    QLabel *optionalInformationLabel;
    QLineEdit *databaseHostNameEdit;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *databaseConnexionPortSpinBox;
    QLineEdit *databaseUserPasswordEdit;
    QLabel *connectionNotWorkLabel;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *homeButton2;
    QPushButton *quit2Button;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *homeButton3;
    QPushButton *addDatButton;
    QPushButton *deleteDataButton;
    QLabel *infoLabel;
    QHBoxLayout *horizontalLayout_8;
    QStackedWidget *adminDataStackedWidget;
    QWidget *page_3;
    QGridLayout *gridLayout_3;
    QLabel *label_14;
    QPushButton *adminCancelButton;
    QGroupBox *groupBox;
    QRadioButton *isThemeRadioButton;
    QRadioButton *isRegexRadioButton;
    QRadioButton *isStructureRadioButton;
    QLineEdit *addDataLineEdit;
    QLabel *addDataEntryLabel;
    QCheckBox *isVerbCheckBox;
    QComboBox *verbGroupComboBox;
    QComboBox *themeForRegexComboBox;
    QLabel *themeForRegexLabel;
    QGroupBox *groupBox_2;
    QCheckBox *pluralCheckBox;
    QCheckBox *prefixCheckBox;
    QCheckBox *suffixCheckBox;
    QLineEdit *pluralLineEdit;
    QLineEdit *prefixLineEdit;
    QLineEdit *suffixLineEdit;
    QLabel *beforeConfirmationLabel;
    QPushButton *adminOKButton;
    QWidget *page_4;
    QLabel *label_2;
    QGroupBox *groupBox_5;
    QRadioButton *isThemeRadioButton_2;
    QRadioButton *isRegexRadioButton_2;
    QRadioButton *isStructureRadioButton_2;
    QLabel *modifyDataEntryLabel;
    QCheckBox *isVerbCheckBox_2;
    QComboBox *verbGroupComboBox_2;
    QComboBox *themeForRegexComboBox_2;
    QLabel *themeForRegexLabel_2;
    QComboBox *modifyComboBox;
    QPushButton *modifyButton;
    QGroupBox *groupBox_6;
    QCheckBox *pluralCheckBox_2;
    QCheckBox *prefixCheckBox_2;
    QCheckBox *suffixCheckBox_2;
    QLineEdit *pluralLineEdit_2;
    QLineEdit *prefixLineEdit_2;
    QLineEdit *suffixLineEdit_2;
    QLabel *beforeConfirmationLabel_2;
    QPushButton *deleteButton;
    QTableWidget *addDelTableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(853, 587);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        actionSe_Connecter = new QAction(MainWindow);
        actionSe_Connecter->setObjectName(QString::fromUtf8("actionSe_Connecter"));
        actionT_l_charger = new QAction(MainWindow);
        actionT_l_charger->setObjectName(QString::fromUtf8("actionT_l_charger"));
        actionT_l_charger_2 = new QAction(MainWindow);
        actionT_l_charger_2->setObjectName(QString::fromUtf8("actionT_l_charger_2"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textClassifierStackedWidget = new QStackedWidget(centralwidget);
        textClassifierStackedWidget->setObjectName(QString::fromUtf8("textClassifierStackedWidget"));
        displayPage = new QWidget();
        displayPage->setObjectName(QString::fromUtf8("displayPage"));
        gridLayout_5 = new QGridLayout(displayPage);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, -1, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        quitButton = new QPushButton(displayPage);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setMaximumSize(QSize(100, 16777215));
        quitButton->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 75, 25);\n"
"font-weight: bold;\n"
"color: white;"));

        horizontalLayout_2->addWidget(quitButton);

        resultsButton = new QPushButton(displayPage);
        resultsButton->setObjectName(QString::fromUtf8("resultsButton"));
        resultsButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(resultsButton);

        downloadButton = new QPushButton(displayPage);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));
        downloadButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(downloadButton);

        statisticsButton = new QPushButton(displayPage);
        statisticsButton->setObjectName(QString::fromUtf8("statisticsButton"));
        statisticsButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(statisticsButton);

        connect1Button = new QPushButton(displayPage);
        connect1Button->setObjectName(QString::fromUtf8("connect1Button"));
        connect1Button->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(connect1Button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_5->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        label_15 = new QLabel(displayPage);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("font: 900 30pt \"Segoe UI\";\n"
"background-color: rgb(2, 75, 25);\n"
"color: white;"));
        label_15->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_5->addWidget(label_15, 0, 0, 1, 4);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(17, 9, 0, 9);
        searchComboBox = new QComboBox(displayPage);
        searchComboBox->setObjectName(QString::fromUtf8("searchComboBox"));
        searchComboBox->setEnabled(true);
        searchComboBox->setMaximumSize(QSize(360, 16777215));
        searchComboBox->setEditable(false);

        gridLayout_6->addWidget(searchComboBox, 1, 0, 1, 2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(1);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        before1CheckBox = new QCheckBox(displayPage);
        before1CheckBox->setObjectName(QString::fromUtf8("before1CheckBox"));
        before1CheckBox->setMaximumSize(QSize(75, 16777215));
        before1CheckBox->setLayoutDirection(Qt::RightToLeft);
        before1CheckBox->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 75, 25);\n"
"font-weight: bold;\n"
"color: white;\n"
"text-align: center;"));

        horizontalLayout_10->addWidget(before1CheckBox);

        before1DateTimeEdit = new QDateTimeEdit(displayPage);
        before1DateTimeEdit->setObjectName(QString::fromUtf8("before1DateTimeEdit"));
        before1DateTimeEdit->setMaximumSize(QSize(115, 16777215));
        before1DateTimeEdit->setCalendarPopup(true);

        horizontalLayout_10->addWidget(before1DateTimeEdit);


        gridLayout_6->addLayout(horizontalLayout_10, 1, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        after1CheckBox = new QCheckBox(displayPage);
        after1CheckBox->setObjectName(QString::fromUtf8("after1CheckBox"));
        after1CheckBox->setMaximumSize(QSize(75, 16777215));
        after1CheckBox->setLayoutDirection(Qt::RightToLeft);
        after1CheckBox->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 75, 25);\n"
"font-weight: bold;\n"
"color: white;\n"
"text-align : center;"));

        horizontalLayout_4->addWidget(after1CheckBox);

        after1DateTimeEdit = new QDateTimeEdit(displayPage);
        after1DateTimeEdit->setObjectName(QString::fromUtf8("after1DateTimeEdit"));
        after1DateTimeEdit->setMaximumSize(QSize(115, 16777215));
        after1DateTimeEdit->setCalendarPopup(true);

        horizontalLayout_4->addWidget(after1DateTimeEdit);


        gridLayout_6->addLayout(horizontalLayout_4, 0, 3, 1, 1);

        searchEdit = new QLineEdit(displayPage);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));
        searchEdit->setMaximumSize(QSize(200, 16777215));

        gridLayout_6->addWidget(searchEdit, 0, 1, 1, 1);

        searchButton = new QPushButton(displayPage);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setMaximumSize(QSize(75, 16777215));
        searchButton->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 75, 25);\n"
"font-weight: bold;\n"
"color: white;"));

        gridLayout_6->addWidget(searchButton, 0, 0, 1, 1);

        firstTableWidget = new QTableWidget(displayPage);
        if (firstTableWidget->columnCount() < 4)
            firstTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        firstTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        firstTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        firstTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        firstTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        firstTableWidget->setObjectName(QString::fromUtf8("firstTableWidget"));
        firstTableWidget->setMinimumSize(QSize(0, 0));
        firstTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        firstTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        firstTableWidget->setShowGrid(false);
        firstTableWidget->setColumnCount(4);

        gridLayout_6->addWidget(firstTableWidget, 3, 0, 1, 4);


        gridLayout_5->addLayout(gridLayout_6, 8, 0, 1, 1);

        textClassifierStackedWidget->addWidget(displayPage);
        settingPage = new QWidget();
        settingPage->setObjectName(QString::fromUtf8("settingPage"));
        gridLayout_4 = new QGridLayout(settingPage);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 5, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 5, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        applicationTitle = new QLabel(settingPage);
        applicationTitle->setObjectName(QString::fromUtf8("applicationTitle"));
        applicationTitle->setMaximumSize(QSize(16777215, 64));
        applicationTitle->setStyleSheet(QString::fromUtf8("font: 900 20pt \"Segoe UI\";\n"
"background-color: rgb(2, 75, 25);"));
        applicationTitle->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_7->addWidget(applicationTitle);


        gridLayout_4->addLayout(horizontalLayout_7, 0, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_4->addItem(verticalSpacer, 11, 2, 1, 1);

        databaseUserNameLabel = new QLabel(settingPage);
        databaseUserNameLabel->setObjectName(QString::fromUtf8("databaseUserNameLabel"));
        databaseUserNameLabel->setMaximumSize(QSize(200, 20));
        databaseUserNameLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_4->addWidget(databaseUserNameLabel, 4, 2, 1, 1);

        obligatoryInformationLabel = new QLabel(settingPage);
        obligatoryInformationLabel->setObjectName(QString::fromUtf8("obligatoryInformationLabel"));
        obligatoryInformationLabel->setMaximumSize(QSize(16777215, 40));
        obligatoryInformationLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_4->addWidget(obligatoryInformationLabel, 2, 1, 1, 1);

        databaseConnexionPortLabel = new QLabel(settingPage);
        databaseConnexionPortLabel->setObjectName(QString::fromUtf8("databaseConnexionPortLabel"));
        databaseConnexionPortLabel->setMaximumSize(QSize(200, 16777215));
        databaseConnexionPortLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_4->addWidget(databaseConnexionPortLabel, 7, 1, 1, 1);

        databaseUserPasswordLabel = new QLabel(settingPage);
        databaseUserPasswordLabel->setObjectName(QString::fromUtf8("databaseUserPasswordLabel"));
        databaseUserPasswordLabel->setMaximumSize(QSize(200, 20));
        databaseUserPasswordLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_4->addWidget(databaseUserPasswordLabel, 7, 2, 1, 1);

        databaseHostNameLabel = new QLabel(settingPage);
        databaseHostNameLabel->setObjectName(QString::fromUtf8("databaseHostNameLabel"));
        databaseHostNameLabel->setMaximumSize(QSize(200, 20));
        databaseHostNameLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_4->addWidget(databaseHostNameLabel, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        connectionOkButton = new QPushButton(settingPage);
        connectionOkButton->setObjectName(QString::fromUtf8("connectionOkButton"));
        connectionOkButton->setMinimumSize(QSize(100, 0));
        connectionOkButton->setMaximumSize(QSize(105, 16777215));
        connectionOkButton->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 75, 25);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(connectionOkButton);

        connectionCancelButton = new QPushButton(settingPage);
        connectionCancelButton->setObjectName(QString::fromUtf8("connectionCancelButton"));
        connectionCancelButton->setMinimumSize(QSize(100, 0));
        connectionCancelButton->setMaximumSize(QSize(105, 16777215));

        horizontalLayout->addWidget(connectionCancelButton);


        gridLayout_4->addLayout(horizontalLayout, 10, 2, 1, 1);

        databaseUserNameEdit = new QLineEdit(settingPage);
        databaseUserNameEdit->setObjectName(QString::fromUtf8("databaseUserNameEdit"));
        databaseUserNameEdit->setMaximumSize(QSize(200, 16777215));

        gridLayout_4->addWidget(databaseUserNameEdit, 5, 2, 1, 1);

        optionalInformationLabel = new QLabel(settingPage);
        optionalInformationLabel->setObjectName(QString::fromUtf8("optionalInformationLabel"));
        optionalInformationLabel->setMaximumSize(QSize(16777215, 20));
        optionalInformationLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_4->addWidget(optionalInformationLabel, 6, 1, 1, 2);

        databaseHostNameEdit = new QLineEdit(settingPage);
        databaseHostNameEdit->setObjectName(QString::fromUtf8("databaseHostNameEdit"));
        databaseHostNameEdit->setMaximumSize(QSize(200, 16777215));

        gridLayout_4->addWidget(databaseHostNameEdit, 5, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        databaseConnexionPortSpinBox = new QSpinBox(settingPage);
        databaseConnexionPortSpinBox->setObjectName(QString::fromUtf8("databaseConnexionPortSpinBox"));
        databaseConnexionPortSpinBox->setMaximumSize(QSize(200, 16777215));
        databaseConnexionPortSpinBox->setMaximum(9999);

        horizontalLayout_3->addWidget(databaseConnexionPortSpinBox);

        databaseUserPasswordEdit = new QLineEdit(settingPage);
        databaseUserPasswordEdit->setObjectName(QString::fromUtf8("databaseUserPasswordEdit"));
        databaseUserPasswordEdit->setMaximumSize(QSize(200, 16777215));
        databaseUserPasswordEdit->setEchoMode(QLineEdit::Password);
        databaseUserPasswordEdit->setClearButtonEnabled(true);

        horizontalLayout_3->addWidget(databaseUserPasswordEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        connectionNotWorkLabel = new QLabel(settingPage);
        connectionNotWorkLabel->setObjectName(QString::fromUtf8("connectionNotWorkLabel"));
        connectionNotWorkLabel->setMaximumSize(QSize(16777215, 20));
        connectionNotWorkLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_2->addWidget(connectionNotWorkLabel);


        gridLayout_4->addLayout(verticalLayout_2, 8, 1, 1, 2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        homeButton2 = new QPushButton(settingPage);
        homeButton2->setObjectName(QString::fromUtf8("homeButton2"));
        homeButton2->setMinimumSize(QSize(100, 0));
        homeButton2->setMaximumSize(QSize(105, 16777215));
        homeButton2->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 75, 25);\n"
"color: rgb(255, 255, 255);\n"
"font-weight: bold;"));

        horizontalLayout_9->addWidget(homeButton2);

        quit2Button = new QPushButton(settingPage);
        quit2Button->setObjectName(QString::fromUtf8("quit2Button"));
        quit2Button->setMinimumSize(QSize(100, 0));
        quit2Button->setMaximumSize(QSize(105, 16777215));

        horizontalLayout_9->addWidget(quit2Button);


        gridLayout_4->addLayout(horizontalLayout_9, 1, 0, 1, 2);

        textClassifierStackedWidget->addWidget(settingPage);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 900 30pt \"Segoe UI\";\n"
"background-color: rgb(2, 75, 25);\n"
"color: white;"));
        label->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout_6->addWidget(label);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        homeButton3 = new QPushButton(page);
        homeButton3->setObjectName(QString::fromUtf8("homeButton3"));
        homeButton3->setStyleSheet(QString::fromUtf8("background-color: rgb(2, 75, 25);\n"
"color: white;\n"
"font-weight: bold;"));

        horizontalLayout_5->addWidget(homeButton3);

        addDatButton = new QPushButton(page);
        addDatButton->setObjectName(QString::fromUtf8("addDatButton"));

        horizontalLayout_5->addWidget(addDatButton);

        deleteDataButton = new QPushButton(page);
        deleteDataButton->setObjectName(QString::fromUtf8("deleteDataButton"));
        deleteDataButton->setMaximumSize(QSize(105, 16777215));

        horizontalLayout_5->addWidget(deleteDataButton);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        infoLabel = new QLabel(page);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(infoLabel, 1, 2, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, -1, 9, 9);
        adminDataStackedWidget = new QStackedWidget(page);
        adminDataStackedWidget->setObjectName(QString::fromUtf8("adminDataStackedWidget"));
        adminDataStackedWidget->setMaximumSize(QSize(375, 16777215));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_3 = new QGridLayout(page_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_14 = new QLabel(page_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(16777215, 40));
        label_14->setStyleSheet(QString::fromUtf8("font: 900 20pt \"Segoe UI\";"));
        label_14->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_3->addWidget(label_14, 1, 1, 1, 4);

        adminCancelButton = new QPushButton(page_3);
        adminCancelButton->setObjectName(QString::fromUtf8("adminCancelButton"));

        gridLayout_3->addWidget(adminCancelButton, 4, 4, 1, 1);

        groupBox = new QGroupBox(page_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        isThemeRadioButton = new QRadioButton(groupBox);
        isThemeRadioButton->setObjectName(QString::fromUtf8("isThemeRadioButton"));
        isThemeRadioButton->setGeometry(QRect(120, 10, 90, 20));
        isRegexRadioButton = new QRadioButton(groupBox);
        isRegexRadioButton->setObjectName(QString::fromUtf8("isRegexRadioButton"));
        isRegexRadioButton->setGeometry(QRect(10, 10, 90, 20));
        isStructureRadioButton = new QRadioButton(groupBox);
        isStructureRadioButton->setObjectName(QString::fromUtf8("isStructureRadioButton"));
        isStructureRadioButton->setGeometry(QRect(220, 10, 91, 20));
        addDataLineEdit = new QLineEdit(groupBox);
        addDataLineEdit->setObjectName(QString::fromUtf8("addDataLineEdit"));
        addDataLineEdit->setGeometry(QRect(140, 60, 201, 22));
        addDataEntryLabel = new QLabel(groupBox);
        addDataEntryLabel->setObjectName(QString::fromUtf8("addDataEntryLabel"));
        addDataEntryLabel->setGeometry(QRect(10, 60, 121, 22));
        isVerbCheckBox = new QCheckBox(groupBox);
        isVerbCheckBox->setObjectName(QString::fromUtf8("isVerbCheckBox"));
        isVerbCheckBox->setGeometry(QRect(10, 140, 121, 20));
        verbGroupComboBox = new QComboBox(groupBox);
        verbGroupComboBox->setObjectName(QString::fromUtf8("verbGroupComboBox"));
        verbGroupComboBox->setGeometry(QRect(140, 140, 81, 20));
        themeForRegexComboBox = new QComboBox(groupBox);
        themeForRegexComboBox->setObjectName(QString::fromUtf8("themeForRegexComboBox"));
        themeForRegexComboBox->setGeometry(QRect(140, 100, 151, 20));
        themeForRegexLabel = new QLabel(groupBox);
        themeForRegexLabel->setObjectName(QString::fromUtf8("themeForRegexLabel"));
        themeForRegexLabel->setGeometry(QRect(10, 100, 121, 20));

        gridLayout_3->addWidget(groupBox, 2, 1, 1, 4);

        groupBox_2 = new QGroupBox(page_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        pluralCheckBox = new QCheckBox(groupBox_2);
        pluralCheckBox->setObjectName(QString::fromUtf8("pluralCheckBox"));
        pluralCheckBox->setGeometry(QRect(10, 10, 121, 20));
        prefixCheckBox = new QCheckBox(groupBox_2);
        prefixCheckBox->setObjectName(QString::fromUtf8("prefixCheckBox"));
        prefixCheckBox->setGeometry(QRect(10, 50, 121, 20));
        prefixCheckBox->setLayoutDirection(Qt::LeftToRight);
        suffixCheckBox = new QCheckBox(groupBox_2);
        suffixCheckBox->setObjectName(QString::fromUtf8("suffixCheckBox"));
        suffixCheckBox->setGeometry(QRect(10, 90, 121, 21));
        suffixCheckBox->setLayoutDirection(Qt::LeftToRight);
        pluralLineEdit = new QLineEdit(groupBox_2);
        pluralLineEdit->setObjectName(QString::fromUtf8("pluralLineEdit"));
        pluralLineEdit->setGeometry(QRect(140, 10, 201, 20));
        prefixLineEdit = new QLineEdit(groupBox_2);
        prefixLineEdit->setObjectName(QString::fromUtf8("prefixLineEdit"));
        prefixLineEdit->setGeometry(QRect(140, 50, 201, 20));
        suffixLineEdit = new QLineEdit(groupBox_2);
        suffixLineEdit->setObjectName(QString::fromUtf8("suffixLineEdit"));
        suffixLineEdit->setGeometry(QRect(140, 90, 201, 20));
        beforeConfirmationLabel = new QLabel(groupBox_2);
        beforeConfirmationLabel->setObjectName(QString::fromUtf8("beforeConfirmationLabel"));
        beforeConfirmationLabel->setGeometry(QRect(10, 123, 331, 51));

        gridLayout_3->addWidget(groupBox_2, 3, 1, 1, 4);

        adminOKButton = new QPushButton(page_3);
        adminOKButton->setObjectName(QString::fromUtf8("adminOKButton"));

        gridLayout_3->addWidget(adminOKButton, 4, 3, 1, 1);

        adminDataStackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 9, 357, 40));
        label_2->setMaximumSize(QSize(16777215, 40));
        groupBox_5 = new QGroupBox(page_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(9, 55, 357, 187));
        isThemeRadioButton_2 = new QRadioButton(groupBox_5);
        isThemeRadioButton_2->setObjectName(QString::fromUtf8("isThemeRadioButton_2"));
        isThemeRadioButton_2->setGeometry(QRect(120, 10, 90, 20));
        isRegexRadioButton_2 = new QRadioButton(groupBox_5);
        isRegexRadioButton_2->setObjectName(QString::fromUtf8("isRegexRadioButton_2"));
        isRegexRadioButton_2->setGeometry(QRect(10, 10, 90, 20));
        isStructureRadioButton_2 = new QRadioButton(groupBox_5);
        isStructureRadioButton_2->setObjectName(QString::fromUtf8("isStructureRadioButton_2"));
        isStructureRadioButton_2->setGeometry(QRect(220, 10, 91, 20));
        modifyDataEntryLabel = new QLabel(groupBox_5);
        modifyDataEntryLabel->setObjectName(QString::fromUtf8("modifyDataEntryLabel"));
        modifyDataEntryLabel->setGeometry(QRect(10, 60, 121, 22));
        isVerbCheckBox_2 = new QCheckBox(groupBox_5);
        isVerbCheckBox_2->setObjectName(QString::fromUtf8("isVerbCheckBox_2"));
        isVerbCheckBox_2->setGeometry(QRect(10, 140, 121, 20));
        verbGroupComboBox_2 = new QComboBox(groupBox_5);
        verbGroupComboBox_2->setObjectName(QString::fromUtf8("verbGroupComboBox_2"));
        verbGroupComboBox_2->setGeometry(QRect(140, 140, 81, 20));
        themeForRegexComboBox_2 = new QComboBox(groupBox_5);
        themeForRegexComboBox_2->setObjectName(QString::fromUtf8("themeForRegexComboBox_2"));
        themeForRegexComboBox_2->setGeometry(QRect(140, 100, 131, 20));
        themeForRegexLabel_2 = new QLabel(groupBox_5);
        themeForRegexLabel_2->setObjectName(QString::fromUtf8("themeForRegexLabel_2"));
        themeForRegexLabel_2->setGeometry(QRect(10, 100, 121, 20));
        modifyComboBox = new QComboBox(groupBox_5);
        modifyComboBox->setObjectName(QString::fromUtf8("modifyComboBox"));
        modifyComboBox->setGeometry(QRect(140, 60, 191, 22));
        modifyComboBox->setEditable(true);
        modifyButton = new QPushButton(page_4);
        modifyButton->setObjectName(QString::fromUtf8("modifyButton"));
        modifyButton->setGeometry(QRect(191, 440, 84, 23));
        groupBox_6 = new QGroupBox(page_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(9, 248, 357, 186));
        pluralCheckBox_2 = new QCheckBox(groupBox_6);
        pluralCheckBox_2->setObjectName(QString::fromUtf8("pluralCheckBox_2"));
        pluralCheckBox_2->setGeometry(QRect(10, 10, 101, 20));
        prefixCheckBox_2 = new QCheckBox(groupBox_6);
        prefixCheckBox_2->setObjectName(QString::fromUtf8("prefixCheckBox_2"));
        prefixCheckBox_2->setGeometry(QRect(10, 50, 101, 20));
        prefixCheckBox_2->setLayoutDirection(Qt::LeftToRight);
        suffixCheckBox_2 = new QCheckBox(groupBox_6);
        suffixCheckBox_2->setObjectName(QString::fromUtf8("suffixCheckBox_2"));
        suffixCheckBox_2->setGeometry(QRect(10, 90, 101, 21));
        suffixCheckBox_2->setLayoutDirection(Qt::LeftToRight);
        pluralLineEdit_2 = new QLineEdit(groupBox_6);
        pluralLineEdit_2->setObjectName(QString::fromUtf8("pluralLineEdit_2"));
        pluralLineEdit_2->setGeometry(QRect(140, 10, 201, 20));
        prefixLineEdit_2 = new QLineEdit(groupBox_6);
        prefixLineEdit_2->setObjectName(QString::fromUtf8("prefixLineEdit_2"));
        prefixLineEdit_2->setGeometry(QRect(140, 50, 201, 20));
        suffixLineEdit_2 = new QLineEdit(groupBox_6);
        suffixLineEdit_2->setObjectName(QString::fromUtf8("suffixLineEdit_2"));
        suffixLineEdit_2->setGeometry(QRect(140, 90, 201, 20));
        beforeConfirmationLabel_2 = new QLabel(groupBox_6);
        beforeConfirmationLabel_2->setObjectName(QString::fromUtf8("beforeConfirmationLabel_2"));
        beforeConfirmationLabel_2->setGeometry(QRect(10, 123, 331, 51));
        deleteButton = new QPushButton(page_4);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(281, 440, 85, 23));
        adminDataStackedWidget->addWidget(page_4);

        horizontalLayout_8->addWidget(adminDataStackedWidget);

        addDelTableWidget = new QTableWidget(page);
        if (addDelTableWidget->columnCount() < 2)
            addDelTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        addDelTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        addDelTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        addDelTableWidget->setObjectName(QString::fromUtf8("addDelTableWidget"));
        addDelTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        addDelTableWidget->setShowGrid(false);

        horizontalLayout_8->addWidget(addDelTableWidget);


        gridLayout_2->addLayout(horizontalLayout_8, 2, 0, 1, 4);

        textClassifierStackedWidget->addWidget(page);

        gridLayout->addWidget(textClassifierStackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        textClassifierStackedWidget->setCurrentIndex(0);
        adminDataStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TextDataClassifier", nullptr));
        actionSe_Connecter->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        actionT_l_charger->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251charger", nullptr));
        actionT_l_charger_2->setText(QCoreApplication::translate("MainWindow", "Download", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        quitButton->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        resultsButton->setText(QCoreApplication::translate("MainWindow", "Results", nullptr));
        downloadButton->setText(QCoreApplication::translate("MainWindow", "Download", nullptr));
        statisticsButton->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        connect1Button->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">TextDataClassifier</span></p></body></html>", nullptr));
        searchComboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Theme Or Structure", nullptr));
        before1CheckBox->setText(QCoreApplication::translate("MainWindow", "Before", nullptr));
        before1DateTimeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy/MM/dd HH:mm", nullptr));
        after1CheckBox->setText(QCoreApplication::translate("MainWindow", "After  ", nullptr));
        after1DateTimeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy/MM/dd HH:mm", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter a Word or Regex", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = firstTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "N\302\272 RANKING", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = firstTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "CONTENTS", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = firstTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "STRUCTURE", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = firstTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "TYPE", nullptr));
        applicationTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; color:#ffffff;\">TextDataClassifier</span></p></body></html>", nullptr));
        databaseUserNameLabel->setText(QCoreApplication::translate("MainWindow", "UserName :", nullptr));
        obligatoryInformationLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Database Connexion Information</p></body></html>", nullptr));
        databaseConnexionPortLabel->setText(QCoreApplication::translate("MainWindow", "Connexion Port", nullptr));
        databaseUserPasswordLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        databaseHostNameLabel->setText(QCoreApplication::translate("MainWindow", "HostName/Ip", nullptr));
        connectionOkButton->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        connectionCancelButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        databaseUserNameEdit->setText(QCoreApplication::translate("MainWindow", "root", nullptr));
        optionalInformationLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Optional</p></body></html>", nullptr));
        databaseHostNameEdit->setText(QCoreApplication::translate("MainWindow", "localhost", nullptr));
        databaseUserPasswordEdit->setText(QString());
        databaseUserPasswordEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Your password here", nullptr));
        homeButton2->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        quit2Button->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:700;\">TextDataClassifier</span></p></body></html>", nullptr));
        homeButton3->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        addDatButton->setText(QCoreApplication::translate("MainWindow", "Add Data", nullptr));
        deleteDataButton->setText(QCoreApplication::translate("MainWindow", "Delete Data", nullptr));
        infoLabel->setText(QCoreApplication::translate("MainWindow", "Informations", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Add Data</p></body></html>", nullptr));
        adminCancelButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        groupBox->setTitle(QString());
        isThemeRadioButton->setText(QCoreApplication::translate("MainWindow", "Theme", nullptr));
        isRegexRadioButton->setText(QCoreApplication::translate("MainWindow", "Regex", nullptr));
        isStructureRadioButton->setText(QCoreApplication::translate("MainWindow", "Structure", nullptr));
        addDataLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex :  theme", nullptr));
        addDataEntryLabel->setText(QCoreApplication::translate("MainWindow", "Your Entry Here ", nullptr));
        isVerbCheckBox->setText(QCoreApplication::translate("MainWindow", "Verb", nullptr));
        themeForRegexComboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Theme of the regex", nullptr));
        themeForRegexLabel->setText(QCoreApplication::translate("MainWindow", "Additional information ", nullptr));
        groupBox_2->setTitle(QString());
        pluralCheckBox->setText(QCoreApplication::translate("MainWindow", "Can be plural", nullptr));
        prefixCheckBox->setText(QCoreApplication::translate("MainWindow", "Can Have Prefix", nullptr));
        suffixCheckBox->setText(QCoreApplication::translate("MainWindow", "Can Have Suffix", nullptr));
        adminOKButton->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:696;\">Modify Data</span></p></body></html>", nullptr));
        groupBox_5->setTitle(QString());
        isThemeRadioButton_2->setText(QCoreApplication::translate("MainWindow", "Theme", nullptr));
        isRegexRadioButton_2->setText(QCoreApplication::translate("MainWindow", "Regex", nullptr));
        isStructureRadioButton_2->setText(QCoreApplication::translate("MainWindow", "Structure", nullptr));
        modifyDataEntryLabel->setText(QCoreApplication::translate("MainWindow", "Your Entry Here ", nullptr));
        isVerbCheckBox_2->setText(QCoreApplication::translate("MainWindow", "Verb", nullptr));
        themeForRegexComboBox_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Theme of the regex", nullptr));
        themeForRegexLabel_2->setText(QCoreApplication::translate("MainWindow", "Additional information ", nullptr));
        modifyButton->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        groupBox_6->setTitle(QString());
        pluralCheckBox_2->setText(QCoreApplication::translate("MainWindow", "Can be plural", nullptr));
        prefixCheckBox_2->setText(QCoreApplication::translate("MainWindow", "Can Have Prefix", nullptr));
        suffixCheckBox_2->setText(QCoreApplication::translate("MainWindow", "Can Have Suffix", nullptr));
        beforeConfirmationLabel_2->setText(QCoreApplication::translate("MainWindow", "    Ex : Final render", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = addDelTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = addDelTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
