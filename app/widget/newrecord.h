#ifndef NEWRECORD_H
#define NEWRECORD_H

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>

class NewRecord : public QWidget
{
    Q_OBJECT
public:
    explicit NewRecord(QWidget *parent = nullptr);
    ~NewRecord();

Q_SIGNALS:

private:
    int                         mYear;                  // 年
    int                         mMouth;                 // 月

    double                      mIncome;                // 当月收入
    double                      mExpanditure;           // 当月支出
    double                      mBalance;               // 当月结余

    QLabel*                     mIncomeLabel;           // 收入
    QLabel*                     mExpanditureLabel;      // 支出
    QLabel*                     mBalanceLabel;          // 当月结余


    QHBoxLayout*                mmNewRecord;            // 新纪录
    QVBoxLayout*                mMainLayout;            // 主要布局

private:
    QLabel*                     mmChargeLabel;          // 新纪录——金额
    QLineEdit*                  mmChargeEdit;           // 新纪录 —— 金额
    QHBoxLayout*                mmNewRecord1;           // 新纪录

};

#endif // NEWRECORD_H
