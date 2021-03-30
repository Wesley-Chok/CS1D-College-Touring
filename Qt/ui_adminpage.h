/********************************************************************************
** Form generated from reading UI file 'adminpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminpage
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *adminHomePage;
    QLabel *label_2;
    QTableView *tableView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addCampusThroughInputFile;
    QPushButton *addSouvenirThroughInputFile;
    QPushButton *addSouvenirBtn;
    QPushButton *deleteSouvenirBtn;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *viewDistancesBtn;
    QPushButton *viewSouvenirBtn;
    QPushButton *changeSouvenirPriceBtn;
    QWidget *deleteSouvenirPage;
    QLabel *label_3;
    QPushButton *deleteSouvenirConfirmBtn;
    QPushButton *deletePageBackBtn;
    QLabel *label_13;
    QSplitter *splitter;
    QLabel *label_4;
    QComboBox *deletePageComboBox;
    QSplitter *splitter_2;
    QLabel *label_6;
    QLineEdit *deletePageSouvenirName_line;
    QWidget *changeSouvenirPricePage;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *changeSouvPriceBackBtn;
    QPushButton *updateSouvenirPriceBtn;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_12;
    QLabel *nameCampuslbl_4;
    QLabel *nameCampuslbl_5;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_6;
    QComboBox *changeSouvenirPageCampusNameComboBox;
    QLineEdit *souvPriceChangeName_line;
    QLineEdit *souvChangePrice_line;
    QWidget *addSouvenirPage;
    QPushButton *addSouvenirPageBackBtn;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QComboBox *addSouvenirPageCampusNameComboBox;
    QLineEdit *souvName_line;
    QLineEdit *souvPrice_line;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QLabel *nameCampuslbl_2;
    QLabel *nameCampuslbl_3;
    QPushButton *createSouvenirBtn;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_2;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *adminpage)
    {
        if (adminpage->objectName().isEmpty())
            adminpage->setObjectName(QString::fromUtf8("adminpage"));
        adminpage->resize(800, 600);
        centralwidget = new QWidget(adminpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 0, 791, 581));
        adminHomePage = new QWidget();
        adminHomePage->setObjectName(QString::fromUtf8("adminHomePage"));
        label_2 = new QLabel(adminHomePage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 70, 151, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        tableView = new QTableView(adminHomePage);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(220, 110, 551, 341));
        layoutWidget = new QWidget(adminHomePage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 110, 191, 351));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addCampusThroughInputFile = new QPushButton(layoutWidget);
        addCampusThroughInputFile->setObjectName(QString::fromUtf8("addCampusThroughInputFile"));

        verticalLayout->addWidget(addCampusThroughInputFile);

        addSouvenirThroughInputFile = new QPushButton(layoutWidget);
        addSouvenirThroughInputFile->setObjectName(QString::fromUtf8("addSouvenirThroughInputFile"));

        verticalLayout->addWidget(addSouvenirThroughInputFile);

        addSouvenirBtn = new QPushButton(layoutWidget);
        addSouvenirBtn->setObjectName(QString::fromUtf8("addSouvenirBtn"));

        verticalLayout->addWidget(addSouvenirBtn);

        deleteSouvenirBtn = new QPushButton(layoutWidget);
        deleteSouvenirBtn->setObjectName(QString::fromUtf8("deleteSouvenirBtn"));

        verticalLayout->addWidget(deleteSouvenirBtn);

        layoutWidget_2 = new QWidget(adminHomePage);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(220, 460, 421, 36));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        viewDistancesBtn = new QPushButton(layoutWidget_2);
        viewDistancesBtn->setObjectName(QString::fromUtf8("viewDistancesBtn"));

        horizontalLayout_11->addWidget(viewDistancesBtn);

        viewSouvenirBtn = new QPushButton(layoutWidget_2);
        viewSouvenirBtn->setObjectName(QString::fromUtf8("viewSouvenirBtn"));

        horizontalLayout_11->addWidget(viewSouvenirBtn);

        changeSouvenirPriceBtn = new QPushButton(layoutWidget_2);
        changeSouvenirPriceBtn->setObjectName(QString::fromUtf8("changeSouvenirPriceBtn"));

        horizontalLayout_11->addWidget(changeSouvenirPriceBtn);

        stackedWidget->addWidget(adminHomePage);
        deleteSouvenirPage = new QWidget();
        deleteSouvenirPage->setObjectName(QString::fromUtf8("deleteSouvenirPage"));
        label_3 = new QLabel(deleteSouvenirPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 70, 151, 41));
        label_3->setFont(font);
        deleteSouvenirConfirmBtn = new QPushButton(deleteSouvenirPage);
        deleteSouvenirConfirmBtn->setObjectName(QString::fromUtf8("deleteSouvenirConfirmBtn"));
        deleteSouvenirConfirmBtn->setGeometry(QRect(210, 390, 321, 23));
        deletePageBackBtn = new QPushButton(deleteSouvenirPage);
        deletePageBackBtn->setObjectName(QString::fromUtf8("deletePageBackBtn"));
        deletePageBackBtn->setGeometry(QRect(20, 20, 75, 23));
        label_13 = new QLabel(deleteSouvenirPage);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(250, 110, 271, 31));
        splitter = new QSplitter(deleteSouvenirPage);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(220, 200, 291, 20));
        splitter->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setLineWidth(3);
        label_4->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        splitter->addWidget(label_4);
        deletePageComboBox = new QComboBox(splitter);
        deletePageComboBox->setObjectName(QString::fromUtf8("deletePageComboBox"));
        splitter->addWidget(deletePageComboBox);
        splitter_2 = new QSplitter(deleteSouvenirPage);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(220, 270, 291, 20));
        splitter_2->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(splitter_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setLineWidth(3);
        label_6->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        splitter_2->addWidget(label_6);
        deletePageSouvenirName_line = new QLineEdit(splitter_2);
        deletePageSouvenirName_line->setObjectName(QString::fromUtf8("deletePageSouvenirName_line"));
        splitter_2->addWidget(deletePageSouvenirName_line);
        stackedWidget->addWidget(deleteSouvenirPage);
        changeSouvenirPricePage = new QWidget();
        changeSouvenirPricePage->setObjectName(QString::fromUtf8("changeSouvenirPricePage"));
        label_5 = new QLabel(changeSouvenirPricePage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(270, 90, 201, 18));
        label_5->setFont(font);
        label_9 = new QLabel(changeSouvenirPricePage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(240, 90, 261, 71));
        label_10 = new QLabel(changeSouvenirPricePage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(240, 110, 261, 71));
        changeSouvPriceBackBtn = new QPushButton(changeSouvenirPricePage);
        changeSouvPriceBackBtn->setObjectName(QString::fromUtf8("changeSouvPriceBackBtn"));
        changeSouvPriceBackBtn->setGeometry(QRect(20, 30, 75, 23));
        updateSouvenirPriceBtn = new QPushButton(changeSouvenirPricePage);
        updateSouvenirPriceBtn->setObjectName(QString::fromUtf8("updateSouvenirPriceBtn"));
        updateSouvenirPriceBtn->setGeometry(QRect(230, 500, 311, 23));
        layoutWidget1 = new QWidget(changeSouvenirPricePage);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(210, 210, 115, 181));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_5->addWidget(label_12);

        nameCampuslbl_4 = new QLabel(layoutWidget1);
        nameCampuslbl_4->setObjectName(QString::fromUtf8("nameCampuslbl_4"));

        verticalLayout_5->addWidget(nameCampuslbl_4);

        nameCampuslbl_5 = new QLabel(layoutWidget1);
        nameCampuslbl_5->setObjectName(QString::fromUtf8("nameCampuslbl_5"));

        verticalLayout_5->addWidget(nameCampuslbl_5);

        layoutWidget2 = new QWidget(changeSouvenirPricePage);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(320, 210, 291, 181));
        verticalLayout_6 = new QVBoxLayout(layoutWidget2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        changeSouvenirPageCampusNameComboBox = new QComboBox(layoutWidget2);
        changeSouvenirPageCampusNameComboBox->setObjectName(QString::fromUtf8("changeSouvenirPageCampusNameComboBox"));

        verticalLayout_6->addWidget(changeSouvenirPageCampusNameComboBox);

        souvPriceChangeName_line = new QLineEdit(layoutWidget2);
        souvPriceChangeName_line->setObjectName(QString::fromUtf8("souvPriceChangeName_line"));

        verticalLayout_6->addWidget(souvPriceChangeName_line);

        souvChangePrice_line = new QLineEdit(layoutWidget2);
        souvChangePrice_line->setObjectName(QString::fromUtf8("souvChangePrice_line"));

        verticalLayout_6->addWidget(souvChangePrice_line);

        stackedWidget->addWidget(changeSouvenirPricePage);
        addSouvenirPage = new QWidget();
        addSouvenirPage->setObjectName(QString::fromUtf8("addSouvenirPage"));
        addSouvenirPageBackBtn = new QPushButton(addSouvenirPage);
        addSouvenirPageBackBtn->setObjectName(QString::fromUtf8("addSouvenirPageBackBtn"));
        addSouvenirPageBackBtn->setGeometry(QRect(20, 30, 75, 23));
        layoutWidget3 = new QWidget(addSouvenirPage);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(280, 200, 281, 161));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        addSouvenirPageCampusNameComboBox = new QComboBox(layoutWidget3);
        addSouvenirPageCampusNameComboBox->setObjectName(QString::fromUtf8("addSouvenirPageCampusNameComboBox"));

        verticalLayout_3->addWidget(addSouvenirPageCampusNameComboBox);

        souvName_line = new QLineEdit(layoutWidget3);
        souvName_line->setObjectName(QString::fromUtf8("souvName_line"));

        verticalLayout_3->addWidget(souvName_line);

        souvPrice_line = new QLineEdit(layoutWidget3);
        souvPrice_line->setObjectName(QString::fromUtf8("souvPrice_line"));

        verticalLayout_3->addWidget(souvPrice_line);

        layoutWidget4 = new QWidget(addSouvenirPage);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(176, 200, 115, 161));
        verticalLayout_2 = new QVBoxLayout(layoutWidget4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        nameCampuslbl_2 = new QLabel(layoutWidget4);
        nameCampuslbl_2->setObjectName(QString::fromUtf8("nameCampuslbl_2"));

        verticalLayout_2->addWidget(nameCampuslbl_2);

        nameCampuslbl_3 = new QLabel(layoutWidget4);
        nameCampuslbl_3->setObjectName(QString::fromUtf8("nameCampuslbl_3"));

        verticalLayout_2->addWidget(nameCampuslbl_3);

        createSouvenirBtn = new QPushButton(addSouvenirPage);
        createSouvenirBtn->setObjectName(QString::fromUtf8("createSouvenirBtn"));
        createSouvenirBtn->setGeometry(QRect(210, 460, 331, 23));
        layoutWidget5 = new QWidget(addSouvenirPage);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(250, 120, 374, 55));
        verticalLayout_4 = new QVBoxLayout(layoutWidget5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_4->addWidget(label_7);

        label_8 = new QLabel(layoutWidget5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        stackedWidget->addWidget(addSouvenirPage);
        layoutWidget_9 = new QWidget(centralwidget);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(160, 80, 2, 2));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutWidget_10 = new QWidget(centralwidget);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(160, 80, 2, 2));
        horizontalLayout = new QHBoxLayout(layoutWidget_10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        adminpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(adminpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 30));
        adminpage->setMenuBar(menubar);
        statusbar = new QStatusBar(adminpage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        adminpage->setStatusBar(statusbar);

        retranslateUi(adminpage);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(adminpage);
    } // setupUi

    void retranslateUi(QMainWindow *adminpage)
    {
        adminpage->setWindowTitle(QCoreApplication::translate("adminpage", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("adminpage", "ADMIN PAGE", nullptr));
        addCampusThroughInputFile->setText(QCoreApplication::translate("adminpage", "Add Campus (Input File)", nullptr));
        addSouvenirThroughInputFile->setText(QCoreApplication::translate("adminpage", "Add Souvenir (Input File)", nullptr));
        addSouvenirBtn->setText(QCoreApplication::translate("adminpage", "Add Souvenir", nullptr));
        deleteSouvenirBtn->setText(QCoreApplication::translate("adminpage", "Delete Souvenir", nullptr));
        viewDistancesBtn->setText(QCoreApplication::translate("adminpage", "View Distances", nullptr));
        viewSouvenirBtn->setText(QCoreApplication::translate("adminpage", "View Souvenir", nullptr));
        changeSouvenirPriceBtn->setText(QCoreApplication::translate("adminpage", "Change Price", nullptr));
        label_3->setText(QCoreApplication::translate("adminpage", "Delete Souvenir", nullptr));
        deleteSouvenirConfirmBtn->setText(QCoreApplication::translate("adminpage", "Delete Souvenir", nullptr));
        deletePageBackBtn->setText(QCoreApplication::translate("adminpage", "Back", nullptr));
        label_13->setText(QCoreApplication::translate("adminpage", "Please choose a Campus and Souvenir in order to delete", nullptr));
        label_4->setText(QCoreApplication::translate("adminpage", "Campus Name:", nullptr));
        label_6->setText(QCoreApplication::translate("adminpage", "Souvenir Name:", nullptr));
        label_5->setText(QCoreApplication::translate("adminpage", "Change Souvenir Price", nullptr));
        label_9->setText(QCoreApplication::translate("adminpage", "Please enter the Souvenir item in the Souvenir Name", nullptr));
        label_10->setText(QCoreApplication::translate("adminpage", "box and update the price in the Souvenir Price box", nullptr));
        changeSouvPriceBackBtn->setText(QCoreApplication::translate("adminpage", "Back", nullptr));
        updateSouvenirPriceBtn->setText(QCoreApplication::translate("adminpage", "Change Souvenir", nullptr));
        label_12->setText(QCoreApplication::translate("adminpage", "Campus Name:", nullptr));
        nameCampuslbl_4->setText(QCoreApplication::translate("adminpage", "Souvenir Name:", nullptr));
        nameCampuslbl_5->setText(QCoreApplication::translate("adminpage", "Souvenir Price:", nullptr));
        addSouvenirPageBackBtn->setText(QCoreApplication::translate("adminpage", "Back", nullptr));
        label_11->setText(QCoreApplication::translate("adminpage", "Campus Name:", nullptr));
        nameCampuslbl_2->setText(QCoreApplication::translate("adminpage", "Souvenir Name:", nullptr));
        nameCampuslbl_3->setText(QCoreApplication::translate("adminpage", "Souvenir Price:", nullptr));
        createSouvenirBtn->setText(QCoreApplication::translate("adminpage", "Create Souvenir", nullptr));
        label_7->setText(QCoreApplication::translate("adminpage", "Add Traditional Souvenir", nullptr));
        label_8->setText(QCoreApplication::translate("adminpage", "Please add a Souvenir name and as well as the price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminpage: public Ui_adminpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
