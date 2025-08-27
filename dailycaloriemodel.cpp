#include "dailycaloriemodel.h"

DailyCalorieModel::DailyCalorieModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int DailyCalorieModel::rowCount(const QModelIndex & /*parent*/) const
{
    return static_cast<int>(m_dailyCalories.size());
}

QVariant DailyCalorieModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= static_cast<int>(m_dailyCalories.size()))
        return QVariant();

    const DailyTracker &entry = m_dailyCalories[index.row()];

    if (role == Qt::DisplayRole) {
        return QString::fromStdString(entry.date) + " - " + QString::number(entry.calorieCount) + " calories";
    }

    return QVariant();
}

void DailyCalorieModel::setDailyCalories(const std::vector<DailyTracker> &entries)
{
    beginResetModel();
    m_dailyCalories = entries;
    endResetModel();
}

void DailyCalorieModel::addDailyEntry(const DailyTracker &entry)
{
    beginInsertRows(QModelIndex(), m_dailyCalories.size(), m_dailyCalories.size());
    m_dailyCalories.push_back(entry);
    endInsertRows();
}
