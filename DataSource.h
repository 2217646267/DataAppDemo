#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include <QList>
#include "ScoreInfo.h"

class DataSource : public QObject
{
    Q_OBJECT

public:
    explicit DataSource(QObject *parent = nullptr);
    bool setdataPath(QString path);
    QList<ScoreInfo> fechData();
    int count();
private:
    QList<ScoreInfo> m_data;
    bool parse(QString line,ScoreInfo& info);
signals:


public slots:
};

#endif // DATASOURCE_H
