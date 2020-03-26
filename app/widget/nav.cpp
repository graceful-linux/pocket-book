#include "nav.h"

#include <QPainter>

Nav::Nav(QWidget *parent) : QWidget(parent)
{
    mBackgroundColor = "#E4E4E4";
    mSelectedColor = "#2CA7F8";
    mRowHeight = 40;
    mCurrentIndex = 0;

    setMouseTracking(true);
    setFixedWidth(150);

    mListItem = new QList<QString>();
}

void Nav::addItem(const QString& title)
{
    mListItem->push_back(title);
    update();
}

void Nav::setWidth(const int& width)
{
    setFixedWidth(width);
}

void Nav::setBackgroundColor(const QString &color)
{

}

void Nav::setSelectColor(const QString &color)
{

}

void Nav::setRowHeight(const int &height)
{

}

void Nav::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(mBackgroundColor));
    painter.drawRect(rect());

    int count = 0;
    for (const QString& str : *mListItem) {
        QPainterPath itemPath;
        itemPath.addRect(QRect(0, count * mRowHeight, width(), mRowHeight));
        if (count == mCurrentIndex) {
            painter.setPen("#FFFFFF");
            painter.fillPath(itemPath, QColor(mSelectedColor));
        } else {
            painter.setPen("#202020");
            painter.fillPath(itemPath, QColor(mBackgroundColor));
        }
        painter.drawText(QRect(0, count * mRowHeight, width(), mRowHeight), Qt::AlignVCenter | Qt::AlignHCenter, str);
        ++count;
    }
}

void Nav::mouseMoveEvent(QMouseEvent *event)
{
    if (event->y() / mRowHeight < mListItem->count()) {
        mCurrentIndex = event->y() / mRowHeight;

        //Q_EMIT currentItemChanged(mCurrentIndex);
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
    Q_UNUSED(event);
}
