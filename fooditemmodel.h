#ifndef FOODITEMMODEL_H
#define FOODITEMMODEL_H

#include <QAbstractListModel>
#include <vector>
#include "foodItems.h"

class FoodItemModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit FoodItemModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setFoodItems(const std::vector<FoodItem> &items);
    void addFoodItem(const FoodItem &item);

    void removeItemAt(int row);

private:
    std::vector<FoodItem> m_foodItems;
};

#endif // FOODITEMMODEL_H
