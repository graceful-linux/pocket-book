#include "nav.h"

#include <QPainter>

Nav::Nav(QWidget *parent) : QWidget(parent)
{
    mMaxWidth = 120;
    mMinWidth = 100;
    mRowHeight = 40;
    mMinHeight = 120;

    mCurrentIndex = 0;

    mSelectedColor = "#2CA7F8";
    mBackgroundColor = "#E4E4E4";

    setMaximumWidth(mMaxWidth);

    setMinimumWidth(mMinWidth);
    setMinimumHeight(mMinHeight);

    setMouseTracking(true);
    mListItem = new QList<QString>();
}

void Nav::addItem(const QString& title)
{
    mListItem->push_back(title);
    mMinHeight = mListItem->size() * mRowHeight;

    setMinimumHeight(mMinHeight);
    Q_EMIT navSizeChanged(width(), height());

    update();
}

void Nav::setBackgroundColor(const QString &color)
{
    mBackgroundColor = color;
}

int &Nav::getMinWidth()
{
    return mMinWidth;
}

int &Nav::getMinHeight()
{
    return mMinHeight;
}

void Nav::setSelectColor(const QString &color)
{
    mSelectedColor = color;
}

void Nav::setRowHeight(const int &height)
{
    if (height > 0) {
        mRowHeight = height;
    }
}

void Nav::paintEvent(QPaintEvent*)
{
    int count = 0;
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(mBackgroundColor));
    painter.drawRect(0, 0, width(), height());

    for (const QString& str : *mListItem) {
        QPainterPath itemPath;
        itemPath.addRect(QRect(0, count * mRowHeight, width(), mRowHeight));
        if (count == mCurrentIndex) {
            painter.setPen("#FFFFFF");                                              // 字体颜色
            painter.fillPath(itemPath, QColor(mSelectedColor));                     // 背景色
        } else {
            painter.setPen("#202020");                                              // 未选中前景色
            painter.fillPath(itemPath, QColor(mBackgroundColor));
        }
        painter.drawText(QRect(0, count * mRowHeight, width(), mRowHeight), Qt::AlignVCenter | Qt::AlignHCenter, str);
        ++count;
    }
}

void Nav::resizeEvent(QResizeEvent*)
{
    Q_EMIT navSizeChanged(width(), height());
}

void Nav::mouseMoveEvent(QMouseEvent* event)
{
    if (event->y() / mRowHeight < mListItem->count()) {
        mCurrentIndex = event->y() / mRowHeight;
        update();
    }
}

void Nav::mousePressEvent(QMouseEvent *event)
{
    if (event->y() / mRowHeight < mListItem->count()) {
        mCurrentIndex = event->y() / mRowHeight;
        Q_EMIT currentItemChanged(mCurrentIndex);
        update();
    }
}

void Nav::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
}
