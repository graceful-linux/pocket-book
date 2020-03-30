#include "newrecord.h"

#include <QDateTime>

NewRecord::NewRecord(QWidget *parent) : QWidget(parent)
{
    QDateTime currentTime = QDateTime::currentDateTime();

    mYear = currentTime.toString("yyyy").toInt();
    mMouth = currentTime.toString("MM").toInt();

    mIncome = 9999999;
    mExpanditure = 10000;
    mBalance = 10000;

    mmNewRecord = new QHBoxLayout();
    mmNewRecord1 = new QHBoxLayout();

    mMainLayout = new QVBoxLayout();

    mIncomeLabel = new QLabel(QString("本月收入: %1  本月支出: %2  目前结余: %3").arg(mIncome).arg(mExpanditure).arg(mBalance));
    mmNewRecord1->addWidget(mIncomeLabel);

    mmNewRecord1->addWidget();


    mmNewRecord->addLayout(mmNewRecord1);
    mMainLayout->addLayout(mmNewRecord);

    setLayout(mMainLayout);
}

NewRecord::~NewRecord()
{

}
