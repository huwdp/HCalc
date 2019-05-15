/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionLicense;
    QAction *actionGenerate_Tokens;
    QAction *actionGenerate_Infix;
    QAction *actionGenerate_Postfix;
    QAction *actionRun_Tests;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *historyListWidget;
    QLineEdit *inputLine;
    QGridLayout *gridLayout_2;
    QPushButton *nineButton;
    QPushButton *sevenButton;
    QPushButton *subtractionButton;
    QPushButton *eightButton;
    QPushButton *zeroButton;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *sixButton;
    QPushButton *threeButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QPushButton *additionButton;
    QPushButton *multiplicationButton;
    QPushButton *leftParenthesisButton;
    QPushButton *rightParenthesisButton;
    QPushButton *divisionButton;
    QPushButton *equalsbutton;
    QPushButton *clearButton;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(486, 506);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionLicense = new QAction(MainWindow);
        actionLicense->setObjectName(QString::fromUtf8("actionLicense"));
        actionGenerate_Tokens = new QAction(MainWindow);
        actionGenerate_Tokens->setObjectName(QString::fromUtf8("actionGenerate_Tokens"));
        actionGenerate_Tokens->setVisible(false);
        actionGenerate_Infix = new QAction(MainWindow);
        actionGenerate_Infix->setObjectName(QString::fromUtf8("actionGenerate_Infix"));
        actionGenerate_Infix->setVisible(false);
        actionGenerate_Postfix = new QAction(MainWindow);
        actionGenerate_Postfix->setObjectName(QString::fromUtf8("actionGenerate_Postfix"));
        actionGenerate_Postfix->setVisible(false);
        actionRun_Tests = new QAction(MainWindow);
        actionRun_Tests->setObjectName(QString::fromUtf8("actionRun_Tests"));
        actionRun_Tests->setVisible(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        historyListWidget = new QListWidget(centralWidget);
        historyListWidget->setObjectName(QString::fromUtf8("historyListWidget"));

        verticalLayout_2->addWidget(historyListWidget);

        inputLine = new QLineEdit(centralWidget);
        inputLine->setObjectName(QString::fromUtf8("inputLine"));

        verticalLayout_2->addWidget(inputLine);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        nineButton = new QPushButton(centralWidget);
        nineButton->setObjectName(QString::fromUtf8("nineButton"));

        gridLayout_2->addWidget(nineButton, 2, 2, 1, 1);

        sevenButton = new QPushButton(centralWidget);
        sevenButton->setObjectName(QString::fromUtf8("sevenButton"));

        gridLayout_2->addWidget(sevenButton, 2, 0, 1, 1);

        subtractionButton = new QPushButton(centralWidget);
        subtractionButton->setObjectName(QString::fromUtf8("subtractionButton"));

        gridLayout_2->addWidget(subtractionButton, 1, 3, 1, 1);

        eightButton = new QPushButton(centralWidget);
        eightButton->setObjectName(QString::fromUtf8("eightButton"));

        gridLayout_2->addWidget(eightButton, 2, 1, 1, 1);

        zeroButton = new QPushButton(centralWidget);
        zeroButton->setObjectName(QString::fromUtf8("zeroButton"));

        gridLayout_2->addWidget(zeroButton, 3, 1, 1, 1);

        oneButton = new QPushButton(centralWidget);
        oneButton->setObjectName(QString::fromUtf8("oneButton"));

        gridLayout_2->addWidget(oneButton, 0, 0, 1, 1);

        twoButton = new QPushButton(centralWidget);
        twoButton->setObjectName(QString::fromUtf8("twoButton"));

        gridLayout_2->addWidget(twoButton, 0, 1, 1, 1);

        sixButton = new QPushButton(centralWidget);
        sixButton->setObjectName(QString::fromUtf8("sixButton"));

        gridLayout_2->addWidget(sixButton, 1, 2, 1, 1);

        threeButton = new QPushButton(centralWidget);
        threeButton->setObjectName(QString::fromUtf8("threeButton"));

        gridLayout_2->addWidget(threeButton, 0, 2, 1, 1);

        fourButton = new QPushButton(centralWidget);
        fourButton->setObjectName(QString::fromUtf8("fourButton"));

        gridLayout_2->addWidget(fourButton, 1, 0, 1, 1);

        fiveButton = new QPushButton(centralWidget);
        fiveButton->setObjectName(QString::fromUtf8("fiveButton"));

        gridLayout_2->addWidget(fiveButton, 1, 1, 1, 1);

        additionButton = new QPushButton(centralWidget);
        additionButton->setObjectName(QString::fromUtf8("additionButton"));

        gridLayout_2->addWidget(additionButton, 0, 3, 1, 1);

        multiplicationButton = new QPushButton(centralWidget);
        multiplicationButton->setObjectName(QString::fromUtf8("multiplicationButton"));

        gridLayout_2->addWidget(multiplicationButton, 2, 3, 1, 1);

        leftParenthesisButton = new QPushButton(centralWidget);
        leftParenthesisButton->setObjectName(QString::fromUtf8("leftParenthesisButton"));

        gridLayout_2->addWidget(leftParenthesisButton, 3, 0, 1, 1);

        rightParenthesisButton = new QPushButton(centralWidget);
        rightParenthesisButton->setObjectName(QString::fromUtf8("rightParenthesisButton"));

        gridLayout_2->addWidget(rightParenthesisButton, 3, 2, 1, 1);

        divisionButton = new QPushButton(centralWidget);
        divisionButton->setObjectName(QString::fromUtf8("divisionButton"));

        gridLayout_2->addWidget(divisionButton, 3, 3, 1, 1);

        equalsbutton = new QPushButton(centralWidget);
        equalsbutton->setObjectName(QString::fromUtf8("equalsbutton"));

        gridLayout_2->addWidget(equalsbutton, 4, 3, 1, 1);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout_2->addWidget(clearButton, 4, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 486, 30));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionLicense);
        menuHelp->addAction(actionGenerate_Tokens);
        menuHelp->addAction(actionGenerate_Postfix);
        menuHelp->addAction(actionRun_Tests);

        retranslateUi(MainWindow);
        QObject::connect(inputLine, SIGNAL(returnPressed()), equalsbutton, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "HCalc", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", nullptr));
        actionLicense->setText(QApplication::translate("MainWindow", "&License", nullptr));
        actionGenerate_Tokens->setText(QApplication::translate("MainWindow", "&Generate Tokens", nullptr));
        actionGenerate_Infix->setText(QApplication::translate("MainWindow", "Generate Infix", nullptr));
        actionGenerate_Postfix->setText(QApplication::translate("MainWindow", "Generate &Postfix", nullptr));
        actionRun_Tests->setText(QApplication::translate("MainWindow", "&Run Tests", nullptr));
        inputLine->setText(QString());
        inputLine->setPlaceholderText(QApplication::translate("MainWindow", "Input here...", nullptr));
        nineButton->setText(QApplication::translate("MainWindow", "9", nullptr));
        sevenButton->setText(QApplication::translate("MainWindow", "7", nullptr));
        subtractionButton->setText(QApplication::translate("MainWindow", "-", nullptr));
        eightButton->setText(QApplication::translate("MainWindow", "8", nullptr));
        zeroButton->setText(QApplication::translate("MainWindow", "0", nullptr));
        oneButton->setText(QApplication::translate("MainWindow", "1", nullptr));
        twoButton->setText(QApplication::translate("MainWindow", "2", nullptr));
        sixButton->setText(QApplication::translate("MainWindow", "6", nullptr));
        threeButton->setText(QApplication::translate("MainWindow", "3", nullptr));
        fourButton->setText(QApplication::translate("MainWindow", "4", nullptr));
        fiveButton->setText(QApplication::translate("MainWindow", "5", nullptr));
        additionButton->setText(QApplication::translate("MainWindow", "+", nullptr));
        multiplicationButton->setText(QApplication::translate("MainWindow", "*", nullptr));
        leftParenthesisButton->setText(QApplication::translate("MainWindow", "(", nullptr));
        rightParenthesisButton->setText(QApplication::translate("MainWindow", ")", nullptr));
        divisionButton->setText(QApplication::translate("MainWindow", "/", nullptr));
        equalsbutton->setText(QApplication::translate("MainWindow", "=", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
