/********************************************************************************
** Form generated from reading UI file 'studentpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTPAGE_H
#define UI_STUDENTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_studentpage
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *StudentSelect;
    QPushButton *campDB_button;
    QLabel *welcome_label;
    QLabel *campDB_texEdit;
    QLabel *tourType_label;
    QPushButton *UCI_button;
    QPushButton *Saddle_button;
    QPushButton *ASU_button;
    QPushButton *custom_button;
    QPlainTextEdit *UCI_textEdit;
    QPlainTextEdit *Saddle_textEdit;
    QPlainTextEdit *ASU_textEdit;
    QPlainTextEdit *custom_textEdit;
    QPushButton *back_button_select;
    QPlainTextEdit *tour_textEdit;
    QWidget *databaseDisplay;
    QTableView *tableView;
    QComboBox *campus_combo;
    QLabel *campus_label;
    QLabel *database_label;
    QPushButton *other_button;
    QPushButton *souv_button;
    QPushButton *back_button_db;
    QWidget *startCollegeTour;
    QLabel *start_label;
    QPushButton *enter_button_1;
    QPushButton *back_button_custom;
    QLabel *avali_label_1;
    QComboBox *start_combo;
    QListView *start_listView;
    QWidget *collegeTour;
    QLabel *next_label;
    QPushButton *done_button;
    QPushButton *enter_button_2;
    QListView *select_listView;
    QListView *avali_listView;
    QLabel *avali_label_2;
    QLabel *select_label;
    QComboBox *next_combo;
    QPushButton *back_button_general;
    QWidget *souvenirShop;
    QComboBox *selectCampus_comboBox;
    QTableView *souv_tableView;
    QTableView *souvCart_tableView;
    QPushButton *backFromSouv_button;
    QPushButton *addSouvenir_button;
    QComboBox *souv_comboBox;
    QSpinBox *quantity_spinBox;
    QLabel *souv_label;
    QLabel *souvCart_label;
    QLabel *total_label;
    QLabel *dollarSign;
    QPushButton *checkout_button;
    QLabel *totalCart_label;
    QWidget *asuCollegeTour;
    QPushButton *back_button_asu;
    QPushButton *enter_button_asu;
    QLabel *asu_label_title;
    QLabel *asu_label_prompt;
    QComboBox *asu_combo;
    QWidget *SortCollegeTour;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *total_dist_label;
    QLabel *distanceNum_label;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *souvTitleLabel;
    QHBoxLayout *horizontalLayout_7;
    QListView *souvFinal_listView;
    QListView *quantityFinal_listView;
    QGridLayout *gridLayout_2;
    QPushButton *finish_button;
    QHBoxLayout *horizontalLayout_5;
    QLabel *totalCost_label;
    QLabel *totalNum_label;
    QLabel *startCampus_label;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QListWidget *sort_listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *studentpage)
    {
        if (studentpage->objectName().isEmpty())
            studentpage->setObjectName(QString::fromUtf8("studentpage"));
        studentpage->resize(840, 559);
        centralwidget = new QWidget(studentpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 831, 491));
        StudentSelect = new QWidget();
        StudentSelect->setObjectName(QString::fromUtf8("StudentSelect"));
        campDB_button = new QPushButton(StudentSelect);
        campDB_button->setObjectName(QString::fromUtf8("campDB_button"));
        campDB_button->setGeometry(QRect(30, 380, 211, 81));
        QFont font;
        font.setPointSize(10);
        campDB_button->setFont(font);
        welcome_label = new QLabel(StudentSelect);
        welcome_label->setObjectName(QString::fromUtf8("welcome_label"));
        welcome_label->setGeometry(QRect(30, 10, 221, 41));
        QFont font1;
        font1.setPointSize(12);
        welcome_label->setFont(font1);
        welcome_label->setTextFormat(Qt::PlainText);
        welcome_label->setScaledContents(false);
        campDB_texEdit = new QLabel(StudentSelect);
        campDB_texEdit->setObjectName(QString::fromUtf8("campDB_texEdit"));
        campDB_texEdit->setGeometry(QRect(30, 350, 181, 20));
        tourType_label = new QLabel(StudentSelect);
        tourType_label->setObjectName(QString::fromUtf8("tourType_label"));
        tourType_label->setGeometry(QRect(350, 40, 131, 20));
        UCI_button = new QPushButton(StudentSelect);
        UCI_button->setObjectName(QString::fromUtf8("UCI_button"));
        UCI_button->setGeometry(QRect(350, 70, 211, 81));
        UCI_button->setFont(font1);
        Saddle_button = new QPushButton(StudentSelect);
        Saddle_button->setObjectName(QString::fromUtf8("Saddle_button"));
        Saddle_button->setGeometry(QRect(350, 170, 211, 91));
        Saddle_button->setFont(font);
        ASU_button = new QPushButton(StudentSelect);
        ASU_button->setObjectName(QString::fromUtf8("ASU_button"));
        ASU_button->setGeometry(QRect(350, 280, 211, 81));
        ASU_button->setFont(font);
        custom_button = new QPushButton(StudentSelect);
        custom_button->setObjectName(QString::fromUtf8("custom_button"));
        custom_button->setGeometry(QRect(350, 380, 211, 91));
        custom_button->setFont(font);
        UCI_textEdit = new QPlainTextEdit(StudentSelect);
        UCI_textEdit->setObjectName(QString::fromUtf8("UCI_textEdit"));
        UCI_textEdit->setGeometry(QRect(570, 70, 211, 81));
        Saddle_textEdit = new QPlainTextEdit(StudentSelect);
        Saddle_textEdit->setObjectName(QString::fromUtf8("Saddle_textEdit"));
        Saddle_textEdit->setGeometry(QRect(570, 170, 211, 91));
        ASU_textEdit = new QPlainTextEdit(StudentSelect);
        ASU_textEdit->setObjectName(QString::fromUtf8("ASU_textEdit"));
        ASU_textEdit->setGeometry(QRect(570, 280, 211, 81));
        custom_textEdit = new QPlainTextEdit(StudentSelect);
        custom_textEdit->setObjectName(QString::fromUtf8("custom_textEdit"));
        custom_textEdit->setGeometry(QRect(570, 380, 211, 91));
        back_button_select = new QPushButton(StudentSelect);
        back_button_select->setObjectName(QString::fromUtf8("back_button_select"));
        back_button_select->setGeometry(QRect(670, 20, 112, 34));
        tour_textEdit = new QPlainTextEdit(StudentSelect);
        tour_textEdit->setObjectName(QString::fromUtf8("tour_textEdit"));
        tour_textEdit->setGeometry(QRect(30, 70, 291, 271));
        stackedWidget->addWidget(StudentSelect);
        databaseDisplay = new QWidget();
        databaseDisplay->setObjectName(QString::fromUtf8("databaseDisplay"));
        tableView = new QTableView(databaseDisplay);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 50, 781, 371));
        campus_combo = new QComboBox(databaseDisplay);
        campus_combo->setObjectName(QString::fromUtf8("campus_combo"));
        campus_combo->setGeometry(QRect(20, 460, 281, 26));
        campus_label = new QLabel(databaseDisplay);
        campus_label->setObjectName(QString::fromUtf8("campus_label"));
        campus_label->setGeometry(QRect(20, 430, 121, 20));
        database_label = new QLabel(databaseDisplay);
        database_label->setObjectName(QString::fromUtf8("database_label"));
        database_label->setGeometry(QRect(20, 10, 371, 20));
        other_button = new QPushButton(databaseDisplay);
        other_button->setObjectName(QString::fromUtf8("other_button"));
        other_button->setGeometry(QRect(320, 450, 141, 34));
        souv_button = new QPushButton(databaseDisplay);
        souv_button->setObjectName(QString::fromUtf8("souv_button"));
        souv_button->setGeometry(QRect(480, 450, 141, 34));
        back_button_db = new QPushButton(databaseDisplay);
        back_button_db->setObjectName(QString::fromUtf8("back_button_db"));
        back_button_db->setGeometry(QRect(690, 10, 112, 34));
        stackedWidget->addWidget(databaseDisplay);
        startCollegeTour = new QWidget();
        startCollegeTour->setObjectName(QString::fromUtf8("startCollegeTour"));
        start_label = new QLabel(startCollegeTour);
        start_label->setObjectName(QString::fromUtf8("start_label"));
        start_label->setGeometry(QRect(40, 390, 131, 20));
        enter_button_1 = new QPushButton(startCollegeTour);
        enter_button_1->setObjectName(QString::fromUtf8("enter_button_1"));
        enter_button_1->setGeometry(QRect(290, 430, 112, 34));
        back_button_custom = new QPushButton(startCollegeTour);
        back_button_custom->setObjectName(QString::fromUtf8("back_button_custom"));
        back_button_custom->setGeometry(QRect(690, 20, 112, 34));
        avali_label_1 = new QLabel(startCollegeTour);
        avali_label_1->setObjectName(QString::fromUtf8("avali_label_1"));
        avali_label_1->setGeometry(QRect(40, 30, 151, 20));
        start_combo = new QComboBox(startCollegeTour);
        start_combo->setObjectName(QString::fromUtf8("start_combo"));
        start_combo->setGeometry(QRect(170, 390, 231, 26));
        start_listView = new QListView(startCollegeTour);
        start_listView->setObjectName(QString::fromUtf8("start_listView"));
        start_listView->setEnabled(true);
        start_listView->setGeometry(QRect(40, 60, 361, 311));
        stackedWidget->addWidget(startCollegeTour);
        collegeTour = new QWidget();
        collegeTour->setObjectName(QString::fromUtf8("collegeTour"));
        next_label = new QLabel(collegeTour);
        next_label->setObjectName(QString::fromUtf8("next_label"));
        next_label->setGeometry(QRect(40, 380, 101, 31));
        done_button = new QPushButton(collegeTour);
        done_button->setObjectName(QString::fromUtf8("done_button"));
        done_button->setGeometry(QRect(290, 430, 112, 34));
        enter_button_2 = new QPushButton(collegeTour);
        enter_button_2->setObjectName(QString::fromUtf8("enter_button_2"));
        enter_button_2->setGeometry(QRect(150, 430, 112, 34));
        select_listView = new QListView(collegeTour);
        select_listView->setObjectName(QString::fromUtf8("select_listView"));
        select_listView->setGeometry(QRect(430, 60, 361, 311));
        avali_listView = new QListView(collegeTour);
        avali_listView->setObjectName(QString::fromUtf8("avali_listView"));
        avali_listView->setEnabled(true);
        avali_listView->setGeometry(QRect(40, 60, 361, 311));
        avali_label_2 = new QLabel(collegeTour);
        avali_label_2->setObjectName(QString::fromUtf8("avali_label_2"));
        avali_label_2->setGeometry(QRect(40, 30, 151, 20));
        select_label = new QLabel(collegeTour);
        select_label->setObjectName(QString::fromUtf8("select_label"));
        select_label->setGeometry(QRect(430, 30, 151, 20));
        next_combo = new QComboBox(collegeTour);
        next_combo->setObjectName(QString::fromUtf8("next_combo"));
        next_combo->setGeometry(QRect(150, 390, 251, 26));
        back_button_general = new QPushButton(collegeTour);
        back_button_general->setObjectName(QString::fromUtf8("back_button_general"));
        back_button_general->setGeometry(QRect(680, 10, 112, 34));
        stackedWidget->addWidget(collegeTour);
        souvenirShop = new QWidget();
        souvenirShop->setObjectName(QString::fromUtf8("souvenirShop"));
        selectCampus_comboBox = new QComboBox(souvenirShop);
        selectCampus_comboBox->setObjectName(QString::fromUtf8("selectCampus_comboBox"));
        selectCampus_comboBox->setGeometry(QRect(70, 50, 271, 22));
        souv_tableView = new QTableView(souvenirShop);
        souv_tableView->setObjectName(QString::fromUtf8("souv_tableView"));
        souv_tableView->setGeometry(QRect(70, 90, 271, 251));
        souvCart_tableView = new QTableView(souvenirShop);
        souvCart_tableView->setObjectName(QString::fromUtf8("souvCart_tableView"));
        souvCart_tableView->setGeometry(QRect(400, 90, 371, 251));
        backFromSouv_button = new QPushButton(souvenirShop);
        backFromSouv_button->setObjectName(QString::fromUtf8("backFromSouv_button"));
        backFromSouv_button->setGeometry(QRect(700, 10, 121, 28));
        addSouvenir_button = new QPushButton(souvenirShop);
        addSouvenir_button->setObjectName(QString::fromUtf8("addSouvenir_button"));
        addSouvenir_button->setGeometry(QRect(250, 400, 93, 28));
        souv_comboBox = new QComboBox(souvenirShop);
        souv_comboBox->setObjectName(QString::fromUtf8("souv_comboBox"));
        souv_comboBox->setGeometry(QRect(70, 360, 171, 22));
        quantity_spinBox = new QSpinBox(souvenirShop);
        quantity_spinBox->setObjectName(QString::fromUtf8("quantity_spinBox"));
        quantity_spinBox->setGeometry(QRect(290, 360, 42, 22));
        quantity_spinBox->setMinimum(1);
        souv_label = new QLabel(souvenirShop);
        souv_label->setObjectName(QString::fromUtf8("souv_label"));
        souv_label->setGeometry(QRect(70, 20, 91, 16));
        souvCart_label = new QLabel(souvenirShop);
        souvCart_label->setObjectName(QString::fromUtf8("souvCart_label"));
        souvCart_label->setGeometry(QRect(470, 20, 231, 51));
        QFont font2;
        font2.setPointSize(18);
        souvCart_label->setFont(font2);
        total_label = new QLabel(souvenirShop);
        total_label->setObjectName(QString::fromUtf8("total_label"));
        total_label->setGeometry(QRect(410, 370, 56, 41));
        total_label->setFont(font1);
        dollarSign = new QLabel(souvenirShop);
        dollarSign->setObjectName(QString::fromUtf8("dollarSign"));
        dollarSign->setGeometry(QRect(490, 360, 31, 61));
        dollarSign->setFont(font2);
        checkout_button = new QPushButton(souvenirShop);
        checkout_button->setObjectName(QString::fromUtf8("checkout_button"));
        checkout_button->setGeometry(QRect(402, 450, 371, 28));
        totalCart_label = new QLabel(souvenirShop);
        totalCart_label->setObjectName(QString::fromUtf8("totalCart_label"));
        totalCart_label->setGeometry(QRect(540, 370, 231, 41));
        totalCart_label->setFont(font2);
        totalCart_label->setMouseTracking(false);
        totalCart_label->setTextFormat(Qt::AutoText);
        totalCart_label->setScaledContents(false);
        stackedWidget->addWidget(souvenirShop);
        asuCollegeTour = new QWidget();
        asuCollegeTour->setObjectName(QString::fromUtf8("asuCollegeTour"));
        back_button_asu = new QPushButton(asuCollegeTour);
        back_button_asu->setObjectName(QString::fromUtf8("back_button_asu"));
        back_button_asu->setGeometry(QRect(700, 20, 112, 34));
        enter_button_asu = new QPushButton(asuCollegeTour);
        enter_button_asu->setObjectName(QString::fromUtf8("enter_button_asu"));
        enter_button_asu->setGeometry(QRect(30, 150, 112, 34));
        asu_label_title = new QLabel(asuCollegeTour);
        asu_label_title->setObjectName(QString::fromUtf8("asu_label_title"));
        asu_label_title->setGeometry(QRect(30, 20, 421, 51));
        asu_label_title->setFont(font1);
        asu_label_prompt = new QLabel(asuCollegeTour);
        asu_label_prompt->setObjectName(QString::fromUtf8("asu_label_prompt"));
        asu_label_prompt->setGeometry(QRect(30, 80, 501, 20));
        asu_combo = new QComboBox(asuCollegeTour);
        asu_combo->setObjectName(QString::fromUtf8("asu_combo"));
        asu_combo->setGeometry(QRect(30, 110, 111, 26));
        stackedWidget->addWidget(asuCollegeTour);
        SortCollegeTour = new QWidget();
        SortCollegeTour->setObjectName(QString::fromUtf8("SortCollegeTour"));
        horizontalLayoutWidget = new QWidget(SortCollegeTour);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 370, 331, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        total_dist_label = new QLabel(horizontalLayoutWidget);
        total_dist_label->setObjectName(QString::fromUtf8("total_dist_label"));
        total_dist_label->setFont(font);

        horizontalLayout_3->addWidget(total_dist_label);

        distanceNum_label = new QLabel(horizontalLayoutWidget);
        distanceNum_label->setObjectName(QString::fromUtf8("distanceNum_label"));
        distanceNum_label->setFont(font1);
        distanceNum_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(distanceNum_label);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        verticalLayoutWidget = new QWidget(SortCollegeTour);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(449, 80, 321, 371));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        souvTitleLabel = new QLabel(verticalLayoutWidget);
        souvTitleLabel->setObjectName(QString::fromUtf8("souvTitleLabel"));
        QFont font3;
        font3.setPointSize(14);
        souvTitleLabel->setFont(font3);
        souvTitleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(souvTitleLabel);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        souvFinal_listView = new QListView(verticalLayoutWidget);
        souvFinal_listView->setObjectName(QString::fromUtf8("souvFinal_listView"));

        horizontalLayout_7->addWidget(souvFinal_listView);

        quantityFinal_listView = new QListView(verticalLayoutWidget);
        quantityFinal_listView->setObjectName(QString::fromUtf8("quantityFinal_listView"));

        horizontalLayout_7->addWidget(quantityFinal_listView);


        verticalLayout_3->addLayout(horizontalLayout_7);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        finish_button = new QPushButton(verticalLayoutWidget);
        finish_button->setObjectName(QString::fromUtf8("finish_button"));

        gridLayout_2->addWidget(finish_button, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        totalCost_label = new QLabel(verticalLayoutWidget);
        totalCost_label->setObjectName(QString::fromUtf8("totalCost_label"));
        totalCost_label->setFont(font3);

        horizontalLayout_5->addWidget(totalCost_label);

        totalNum_label = new QLabel(verticalLayoutWidget);
        totalNum_label->setObjectName(QString::fromUtf8("totalNum_label"));
        totalNum_label->setFont(font3);

        horizontalLayout_5->addWidget(totalNum_label);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        startCampus_label = new QLabel(SortCollegeTour);
        startCampus_label->setObjectName(QString::fromUtf8("startCampus_label"));
        startCampus_label->setGeometry(QRect(30, 30, 551, 31));
        verticalLayoutWidget_2 = new QWidget(SortCollegeTour);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(30, 82, 331, 271));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        sort_listWidget = new QListWidget(verticalLayoutWidget_2);
        sort_listWidget->setObjectName(QString::fromUtf8("sort_listWidget"));

        gridLayout_4->addWidget(sort_listWidget, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);

        stackedWidget->addWidget(SortCollegeTour);
        studentpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(studentpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 840, 30));
        studentpage->setMenuBar(menubar);
        statusbar = new QStatusBar(studentpage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        studentpage->setStatusBar(statusbar);

        retranslateUi(studentpage);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(studentpage);
    } // setupUi

    void retranslateUi(QMainWindow *studentpage)
    {
        studentpage->setWindowTitle(QCoreApplication::translate("studentpage", "MainWindow", nullptr));
        campDB_button->setText(QCoreApplication::translate("studentpage", "DATABASE DISPLAY", nullptr));
        welcome_label->setText(QCoreApplication::translate("studentpage", "Welcome, Student", nullptr));
        campDB_texEdit->setText(QCoreApplication::translate("studentpage", "See Campus Database:", nullptr));
        tourType_label->setText(QCoreApplication::translate("studentpage", "Select Tour Type:", nullptr));
        UCI_button->setText(QCoreApplication::translate("studentpage", "UCI", nullptr));
        Saddle_button->setText(QCoreApplication::translate("studentpage", "SADDLEBACK", nullptr));
        ASU_button->setText(QCoreApplication::translate("studentpage", "ASU", nullptr));
        custom_button->setText(QCoreApplication::translate("studentpage", "CUSTOM", nullptr));
        UCI_textEdit->setPlainText(QCoreApplication::translate("studentpage", "Start at the University of California, Irvine and tour 11 college campuses.", nullptr));
        Saddle_textEdit->setPlainText(QCoreApplication::translate("studentpage", "Start at Saddleback Community College, tour 13 college campuses (including 2 new campuses).", nullptr));
        ASU_textEdit->setPlainText(QCoreApplication::translate("studentpage", "Start at Arizona State University, choose a # of other other colleges to visit.", nullptr));
        custom_textEdit->setPlainText(QCoreApplication::translate("studentpage", "Choose the colleges that you wish to tour.", nullptr));
        back_button_select->setText(QCoreApplication::translate("studentpage", "Back", nullptr));
        tour_textEdit->setPlainText(QCoreApplication::translate("studentpage", "In this program, You will be able to select one of these 4 tour type in order create your desired college tour plan. After your colleges have been selected, you will be able to purchase souvenirs from the campuses you visit. Lastly, you will get a sorted college tour plan and a souvenir receipt from your trip.", nullptr));
        campus_label->setText(QCoreApplication::translate("studentpage", "Current Campus", nullptr));
        database_label->setText(QCoreApplication::translate("studentpage", "Database", nullptr));
        other_button->setText(QCoreApplication::translate("studentpage", "Other Campuses", nullptr));
        souv_button->setText(QCoreApplication::translate("studentpage", "Souvenirs", nullptr));
        back_button_db->setText(QCoreApplication::translate("studentpage", "Back", nullptr));
        start_label->setText(QCoreApplication::translate("studentpage", "Starting Campus", nullptr));
        enter_button_1->setText(QCoreApplication::translate("studentpage", "Enter", nullptr));
        back_button_custom->setText(QCoreApplication::translate("studentpage", "Back", nullptr));
        avali_label_1->setText(QCoreApplication::translate("studentpage", "Avaliable Campuses", nullptr));
        next_label->setText(QCoreApplication::translate("studentpage", "Next Campus", nullptr));
        done_button->setText(QCoreApplication::translate("studentpage", "Done", nullptr));
        enter_button_2->setText(QCoreApplication::translate("studentpage", "Enter", nullptr));
        avali_label_2->setText(QCoreApplication::translate("studentpage", "Avaliable Campuses", nullptr));
        select_label->setText(QCoreApplication::translate("studentpage", "Selected Campuses", nullptr));
        back_button_general->setText(QCoreApplication::translate("studentpage", "Back", nullptr));
        backFromSouv_button->setText(QCoreApplication::translate("studentpage", "Back ", nullptr));
        addSouvenir_button->setText(QCoreApplication::translate("studentpage", "Add", nullptr));
        souv_label->setText(QCoreApplication::translate("studentpage", "Souvenirs of: ", nullptr));
        souvCart_label->setText(QCoreApplication::translate("studentpage", "Souvenir Cart", nullptr));
        total_label->setText(QCoreApplication::translate("studentpage", "Total:", nullptr));
        dollarSign->setText(QCoreApplication::translate("studentpage", "$", nullptr));
        checkout_button->setText(QCoreApplication::translate("studentpage", "Checkout", nullptr));
        totalCart_label->setText(QCoreApplication::translate("studentpage", "0.00", nullptr));
        back_button_asu->setText(QCoreApplication::translate("studentpage", "Back", nullptr));
        enter_button_asu->setText(QCoreApplication::translate("studentpage", "Enter", nullptr));
        asu_label_title->setText(QCoreApplication::translate("studentpage", "ASU College Tour - Starting at ASU", nullptr));
        asu_label_prompt->setText(QCoreApplication::translate("studentpage", "Enter the number of colleges you would like to visit (including ASU):", nullptr));
        total_dist_label->setText(QCoreApplication::translate("studentpage", "Total Distance", nullptr));
        distanceNum_label->setText(QString());
        label_2->setText(QCoreApplication::translate("studentpage", "miles", nullptr));
        souvTitleLabel->setText(QCoreApplication::translate("studentpage", "Souvenirs", nullptr));
        finish_button->setText(QCoreApplication::translate("studentpage", "Finish", nullptr));
        totalCost_label->setText(QCoreApplication::translate("studentpage", "Total Cost:  $", nullptr));
        totalNum_label->setText(QString());
        startCampus_label->setText(QString());
        label->setText(QCoreApplication::translate("studentpage", "Sorted College Tour Plan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentpage: public Ui_studentpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTPAGE_H
