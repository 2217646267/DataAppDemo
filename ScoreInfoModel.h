#ifndef SCOREINFOMODEL_H
#define SCOREINFOMODEL_H

#include <QObject>
#include <QStandardItem>
#include "ScoreInfo.h"
#include <QTableView>
#include <QStandardItemModel>

class ScoreInfoModel : public QObject
{
    Q_OBJECT
    QStandardItemModel m_model;
public:
    explicit ScoreInfoModel(QObject *parent = nullptr);
    bool add(ScoreInfo info);
    bool remove(int i);
    ScoreInfo getItem(int i);
    int count();
    void setView(QTableView & view);
signals:

public slots:
};

#endif // SCOREINFOMODEL_H
