#ifndef NAV_H
#define NAV_H

#include <QWidget>
#include <QMouseEvent>

class Nav : public QWidget
{
    Q_OBJECT
public:
    explicit Nav(QWidget *parent = nullptr);

    void addItem (const QString&);
    void setWidth (const int&);
    void setBackgroundColor (const QString& color);
    void setSelectColor (const QString& color);
    void setRowHeight (const int& height);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    Q_SIGNAL void currentItemChanged (const int& index);

private:
    QList<QString>*         mListItem;
    QString                 mBackgroundColor;
    QString                 mSelectedColor;
    int                     mRowHeight;
    int                     mCurrentIndex;
};

#endif // NAV_H
