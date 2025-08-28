#include "fooditemmodel.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QListWidget>
#include <fstream>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    retrieveFileFood();
    retrieveFileDate();
    retrieveCurrentCalorie();

    foodModel = new FoodItemModel(this);
    foodModel->setFoodItems(foodItems);

    dailyModel = new DailyCalorieModel(this);
    dailyModel->setDailyCalories(dailyItems);

    ui->editMenuList->setModel(foodModel);
    ui->calcMenuList->setModel(foodModel);
    ui->dailyTrackerList->setModel(dailyModel);
    ui->caloriesTotalText->setText("Current Count: " + QString::number(currentCalorieCount));

    connect(ui->pushButtonSave, &QPushButton::clicked, this, &MainWindow::saveFoodItem);
    connect(ui->pushButtonRemove, &QPushButton::clicked, this, &MainWindow::removeFoodItem);
    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &MainWindow::addCalorieCount);
    connect(ui->pushButtonSubtract, &QPushButton::clicked, this, &MainWindow::subtractCalorieCount);
    connect(ui->pushButtonAddDate, &QPushButton::clicked, this, &MainWindow::saveFoodDate);
    connect(ui->pushButtonRemvoeDate, &QPushButton::clicked, this, &MainWindow::removeDate);
}

void MainWindow::retrieveFileDate()
{
    ifstream inDFile;

    inDFile.open("calorieDayTracker.txt");

    if(inDFile.fail())
    {
        cout << "Failed to open file for reading." << endl;
        return;
    }

    DailyTracker day;
    while (inDFile >> day.date >> day.calorieCount) {
        cout << "Read daily entry: " << day.date << " " << day.calorieCount << endl; // ← DEBUG
        dailyItems.push_back(day);
    }

    inDFile.close();
}

void MainWindow::retrieveFileFood()
{
    ifstream inFile;

    inFile.open("FoodItems.txt");

    if(inFile.fail())
    {
        cout << "Failed to open file for reading." << endl;
        return;
    }

    FoodItem item;
    while(inFile >> item.name >> item.calories)
    {
        foodItems.push_back(item);
    }

    inFile.close();
}

void MainWindow::updateFileFood()
{
    ofstream outFile;

    outFile.open("FoodItems.txt");

    if(outFile.fail())
    {
        cout << "Failed to open file for writing." << endl;
        return;
    }

    for (auto &item : foodItems)
    {
        outFile << item.name << " " << item.calories << endl;
    }

    outFile.close();
}

void MainWindow::updateFileDate()
{
    ofstream outFile;

    outFile.open("calorieDayTracker.txt");

    if(outFile.fail())
    {
        cout << "Failed to open file for writing." << endl;
        return;
    }

    for (auto &item : dailyItems)
    {
        outFile << item.date << " " << item.calorieCount << endl;
    }

    outFile.close();
}

void MainWindow::saveFoodItem() {
    QString name = ui->lineEditName->text();
    QString caloriesStr = ui->lineEditCalories->text();

    if (name.isEmpty() || caloriesStr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in both fields.");
        return;
    }

    bool ok;
    int calories = caloriesStr.toInt(&ok);
    if (!ok || calories < 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid number for calories.");
        return;
    }

    FoodItem item;
    item.name = name.toStdString();
    item.calories = calories;

    foodItems.push_back(item);
    foodModel->addFoodItem(item);

    updateFileFood();

    ui->lineEditName->clear();
    ui->lineEditCalories->clear();
}

void MainWindow::removeFoodItem()
{
    QModelIndex selectedIndex = ui->editMenuList->currentIndex();

    if(!selectedIndex.isValid())
    {
        QMessageBox::warning(this, "Removal Error", "Please select a valid input");
        return;
    }

    int row = selectedIndex.row();

    if (row >= 0 && row < static_cast<int>(foodItems.size()))
    {
        foodItems.erase(foodItems.begin() + row);
    }

    foodModel->removeItemAt(row);

    updateFileFood();
}

void FoodItemModel::removeItemAt(int row) {
    if (row < 0 || row >= static_cast<int>(m_foodItems.size()))
    {
        return;
    }

    beginRemoveRows(QModelIndex(), row, row);
    m_foodItems.erase(m_foodItems.begin() + row);
    endRemoveRows();
}

void MainWindow::addCalorieCount()
{
    QModelIndex selectedIndex = ui->calcMenuList->currentIndex();

    if(!selectedIndex.isValid())
    {
        QMessageBox::warning(this, "Removal Error", "Please select a valid input");
        return;
    }

    int row = selectedIndex.row();

    currentCalorieCount += foodItems[row].calories;

    ui->caloriesTotalText->setText("Current Count: " + QString::number(currentCalorieCount));

    updateCurrentCalorie();
}

void MainWindow::subtractCalorieCount()
{
    QModelIndex selectedIndex = ui->calcMenuList->currentIndex();

    if(!selectedIndex.isValid())
    {
        QMessageBox::warning(this, "Removal Error", "Please select a valid input");
        return;
    }

    int row = selectedIndex.row();

    if(currentCalorieCount - foodItems[row].calories <= 0)
    {
        currentCalorieCount = 0;
    }
    else
    {
        currentCalorieCount -= foodItems[row].calories;
    }

    ui->caloriesTotalText->setText("Current Count: " + QString::number(currentCalorieCount));

    updateCurrentCalorie();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_calculate_clicked()
{
    ui ->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_B_edit_clicked()
{
    ui ->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_B_days_clicked()
{
    ui ->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_B_exit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_B_home_clicked()
{
    ui ->stackedWidget->setCurrentIndex(0);
}

//New Stuff

void MainWindow::saveFoodDate() {
    QDate date = ui->dateEdit->date();
    QString caloriesStr = ui->lineEditDailyCalories->text();

    if (caloriesStr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in daily calorie amount.");
        return;
    }

    bool ok;
    int calories = caloriesStr.toInt(&ok);
    if (!ok || calories < 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid number for calories.");
        return;
    }

    DailyTracker item;
    item.date = date.toString("dd-MM-yyyy").toStdString();
    item.calorieCount = calories;

    dailyItems.push_back(item);
    dailyModel->addDailyEntry(item);

    updateFileDate();

    ui->lineEditDailyCalories->clear();
}

void MainWindow::removeDate()
{
    QModelIndex selectedIndex = ui->dailyTrackerList->currentIndex();

    if(!selectedIndex.isValid())
    {
        QMessageBox::warning(this, "Removal Error", "Please select a valid input");
        return;
    }

    int row = selectedIndex.row();

    if (row >= 0 && row < static_cast<int>(dailyItems.size()))
    {
        dailyItems.erase(dailyItems.begin() + row);
    }

    dailyModel->removeItemAt(row);

    updateFileDate();
}

void DailyCalorieModel::removeItemAt(int row) {
    if (row < 0 || row >= static_cast<int>(m_dailyCalories.size()))
    {
        return;
    }

    beginRemoveRows(QModelIndex(), row, row);
    m_dailyCalories.erase(m_dailyCalories.begin() + row);
    endRemoveRows();
}

void MainWindow::retrieveCurrentCalorie()
{
    ifstream inFile;

    inFile.open("currentCalorieSave.txt");

    if(inFile.fail())
    {
        cout << "Failed to open file for reading." << endl;
        return;
    }

    inFile >> currentCalorieCount;

    inFile.close();
}

void MainWindow::updateCurrentCalorie()
{
    ofstream outFile;

    outFile.open("currentCalorieSave.txt");

    if(outFile.fail())
    {
        cout << "Failed to open file for writing." << endl;
        return;
    }

    outFile << currentCalorieCount;

    outFile.close();
}
