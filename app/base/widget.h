#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

/**
 * 无边框窗体
 *
 */

class WidgetTitle : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetTitle(QWidget* parent = nullptr);

};

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

Q_SIGNALS:

};

#endif // WIDGET_H
