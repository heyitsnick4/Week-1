#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <string>
#include <QMainWindow>
#include <QModelIndex>
#include <QListWidget>
#include "fooditemmodel.h"
#include "dailycaloriemodel.h"
#include "foodItems.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

int main();
void askUser();
void addFoodItem();
void removeFoodItem();
void removeCalories();
void calculateCalories();
void retrieveFile();
void updateFile();

extern int currentCaloriesCount;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void retrieveFile();
    void updateFile();
    void saveFoodItem();
    void removeFoodItem();

    void addCalorieCount();
    void subtractCalorieCount();
    void updateDate();

private slots:

    void on_B_calculate_clicked();

    void on_B_edit_clicked();

    void on_B_days_clicked();

    void on_B_exit_clicked();

    void on_B_home_clicked();

private:
    Ui::MainWindow *ui;
    FoodItemModel *foodModel;
    DailyCalorieModel *dailyModel;
    vector<FoodItem> foodItems;
    vector<DailyTracker> dailyItems;

    int currentCalorieCount = 0;
};
#endif // MAINWINDOW_H
