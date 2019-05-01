/*
 * This file is part of HCalc. This file represents the interface and connection between the UI and the calculator class.
 *
 * Copyright (C) 2016 Huw Pritchard
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->oneButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->twoButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->threeButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->fourButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->fiveButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->sixButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->sevenButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->eightButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->nineButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->zeroButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->leftParenthesisButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->rightParenthesisButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->additionButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->subtractionButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->multiplicationButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->divisionButton, SIGNAL(clicked(bool)), this, SLOT(addToInput()));
    connect(ui->equalsbutton, SIGNAL(clicked(bool)), this, SLOT(calculate()));
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(about()));
    connect(ui->actionLicense, SIGNAL(triggered(bool)), this, SLOT(license()));
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(exit()));
    connect(ui->clearButton, SIGNAL(clicked(bool)), this, SLOT(clear()));
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(developer()));
    connect(ui->actionGenerate_Postfix, SIGNAL(triggered(bool)), this, SLOT(generatePostfix()));
    connect(ui->actionGenerate_Tokens, SIGNAL(triggered(bool)),this,SLOT(generateTokens()));
    connect(ui->actionRun_Tests, SIGNAL(triggered(bool)),this,SLOT(runTests()));
    this->developerCount = 0;
}

MainWindow::~MainWindow()
{
    // historyListWidget should automatically clean itself up.
    delete ui;
}

void MainWindow::addToInput()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString inputBoxText = ui->inputLine->text();
    QString buttonText = button->text();
    if (buttonText.at(0) == "&")
    {
        buttonText = buttonText.mid(1, buttonText.length()-1);
    }
    inputBoxText.append(buttonText);
    ui->inputLine->setText(inputBoxText);
}

void MainWindow::clear()
{
    ui->inputLine->clear();
}

void MainWindow::addToOutput(string input)
{
    QString temp = QString::fromStdString(input);
    QListWidgetItem *item = new QListWidgetItem(temp, ui->historyListWidget);
    ui->historyListWidget->addItem(item);
    ui->historyListWidget->scrollToBottom();
}

void MainWindow::addToOutput(QString input)
{
    QListWidgetItem *item = new QListWidgetItem(input, ui->historyListWidget);
    ui->historyListWidget->addItem(item);
    ui->historyListWidget->scrollToBottom();
}

void MainWindow::calculate()
{
    try
    {
        QString answer = QString::number(calculator.calculate(ui->inputLine->text().toStdString()));
        this->addToOutput(answer);
    }
    catch (EmptyCalculation& e)
    {
        std::string ex(e.what());
        this->addToOutput("Error: " + ex);
    }
    catch (MismatchedParenthesis &e)
    {
        std::string ex(e.what());
        this->addToOutput("Error: " + ex);
    }
    catch (InvalidCalculation &e)
    {
        std::string ex(e.what());
        this->addToOutput("Error: " + ex);
    }
    catch (std::exception& e)
    {
        std::string ex(e.what());
        this->addToOutput("Error: " + ex);
    }
}

void MainWindow::about()
{
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle("About");
    msg.setText("This software is built to calculate mathematic expressions."
                " Calculations are calculated using the Reverse Polish Notation method.");
    msg.exec();
}

void MainWindow::license()
{
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle("License");
    msg.setText("This software is licensed under GPL v2.0.");
    msg.exec();
}

void MainWindow::exit()
{
    msg.setWindowTitle("Exit");
    msg.setText("Are you sure you want to close this application?");
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if (msg.exec() == QMessageBox::Yes)
    {
        close();
    }
}

void MainWindow::generateTokens()
{
    Calculator calculator;
    vector<string> tokens = calculator.generateTokens(ui->inputLine->text().toStdString());
    string output;
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        //output.append("[");
        output.append((*it));
        //output.append("]");
    }
    addToOutput(output);
}

void MainWindow::generatePostfix()
{
    string output;
    Calculator calculator;
    vector<string> list = calculator.generateTokens(ui->inputLine->text().toStdString());

    Operators operatorsList;
    InfixToPostfix infixToPostfix(&operatorsList);
    list = infixToPostfix.convert(list);

    for (vector<string>::iterator it = list.begin(); it != list.end(); ++it)
    {
        //output.append("[");
        output.append((*it));
        //output.append("]");
    }
    addToOutput(output);
}

void MainWindow::runTests()
{
    ui->historyListWidget->clear();
    TestHarness testHarness;
    vector<string> tests = testHarness.runAll();
    for (vector<string>::iterator it = tests.begin(); it != tests.end(); ++it)
    {
        addToOutput((*it));
    }
}

void MainWindow::developer()
{
    if (developerCount > 1)
    {
        ui->actionGenerate_Tokens->setVisible(true);
        ui->actionGenerate_Postfix->setVisible(true);
        ui->actionRun_Tests->setVisible(true);
    }
    else
    {
        developerCount++;
    }
}
