#include "ScoreInfoModel.h"
#include <QDebug>

ScoreInfoModel::ScoreInfoModel(QObject *parent) : QObject(parent)
{

}

bool ScoreInfoModel::add(ScoreInfo info)
{
    QStandardItem* root = m_model.invisibleRootItem();
    QStandardItem* item0 = new QStandardItem();
    QStandardItem* item1 = new QStandardItem();
    QStandardItem* item2 = new QStandardItem();

    bool ret = true;
int newRow = count();
    if((root != nullptr) && (item0 != nullptr)
     &&(item1 != nullptr) &&(item2 != nullptr))
    {
        item0->setData(info.id(),Qt::DisplayRole);
        item1->setData(info.id(),Qt::DisplayRole);
        item2->setData(info.id(),Qt::DisplayRole);


        qDebug() << count();
        root->setChild(newRow, 0, item0);
        root->setChild(newRow, 1, item1);
        root->setChild(newRow, 2, item2);
    }
    else {
        ret = false;
    }
    qDebug() << count();
    return ret;
}

bool ScoreInfoModel::remove(int i)
{
    bool ret = true;
    if((i < 0) && (i < count()))
    {
        m_model.removeRow(i);
    }
    else {
        return false;
    }
    return ret;
}

ScoreInfo ScoreInfoModel::getItem(int i)
{
    ScoreInfo ret;
    if((i >= 0 ) && (i < count()))
    {
       QModelIndex index0 = m_model.index(i, 0, QModelIndex());
       QModelIndex index1 = m_model.index(i, 1, QModelIndex());
       QModelIndex index2 = m_model.index(i, 2, QModelIndex());
       QVariant v0 = index0.data(Qt::DisplayRole);
       QVariant v1 = index1.data(Qt::DisplayRole);
       QVariant v2 = index2.data(Qt::DisplayRole);

       ret = ScoreInfo(v0.toString(), v1.toString(), v2.toInt());
    }
    return ret;
}

int ScoreInfoModel::count()
{
    return m_model.rowCount();
}

void ScoreInfoModel::setView(QTableView &view)
{
    view.setModel(&m_model);
}
