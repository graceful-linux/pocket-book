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
    void setRowHeight (const int& height);
    void setSelectColor (const QString& color);
    void setBackgroundColor (const QString& color);

    int& getMinWidth();
    int& getMinHeight();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    Q_SIGNAL void currentItemChanged (const int& index);
    Q_SIGNAL void navSizeChanged (const int& w, const int& h);

private:
    /* 设置成属性更合适一些 */
    int                     mMaxWidth;                  // 导航栏最大宽度
    int                     mMinWidth;                  // 导航栏最小宽度

    int                     mMinHeight;                 // 导航栏最小高度
    int                     mRowHeight;                 // 每个选项高度

    int                     mCurrentIndex;              // 当前选中项目
    QString                 mSelectedColor;             // 选中项目的颜色
    QString                 mBackgroundColor;           // 背景色
    QList<QString>*         mListItem;                  // 选项列表
};

#endif // NAV_H
