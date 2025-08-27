#include "fooditemmodel.h"

FoodItemModel::FoodItemModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int FoodItemModel::rowCount(const QModelIndex & /*parent*/) const
{
    return static_cast<int>(m_foodItems.size());
}

QVariant FoodItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_foodItems.size())
        return QVariant();

    const FoodItem &item = m_foodItems[index.row()];

    if (role == Qt::DisplayRole) {
        return QString::fromStdString(item.name) + " - " + QString::number(item.calories) + " calories";
    }

    return QVariant();
}

void FoodItemModel::setFoodItems(const std::vector<FoodItem> &items)
{
    beginResetModel();
    m_foodItems = items;
    endResetModel();
}

void FoodItemModel::addFoodItem(const FoodItem &item) {
    beginInsertRows(QModelIndex(), m_foodItems.size(), m_foodItems.size());
    m_foodItems.push_back(item);
    endInsertRows();
}
