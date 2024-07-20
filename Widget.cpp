#include "Widget.h"
#include "DataSource.h"
#include "ScoreInfo.h"
#include <QList>
#include <QDebug>
#include "ScoreInfoModel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    DataSource da;
    ScoreInfoModel sim;
    if(da.setdataPath("E:/test.txt"))
    {
        QList<ScoreInfo> list = da.fechData();

        for(auto val : list)
        {
//            qDebug() << val.id();
//            qDebug() << val.name();
//            qDebug() << val.score();
            sim.add(val);
        }
    }
    else {

    }
}

Widget::~Widget()
{

}
