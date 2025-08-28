#ifndef FOODITEMS_H
#define FOODITEMS_H
#include <string>

using namespace std;

struct FoodItem {
    string name;
    int calories;
};

struct DailyTracker{
    string date;
    int calorieCount;
};

#endif // FOODITEMS_H
