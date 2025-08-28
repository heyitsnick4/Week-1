#ifndef DAILYCALORIEMODEL_H
#define DAILYCALORIEMODEL_H

#include <QAbstractListModel>
#include <vector>
#include "foodItems.h"

class DailyCalorieModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit DailyCalorieModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setDailyCalories(const std::vector<DailyTracker> &entries);
    void addDailyEntry(const DailyTracker &entry);
    void removeItemAt(int row);

private:
    std::vector<DailyTracker> m_dailyCalories;
};

#endif // DAILYCALORIEMODEL_H
