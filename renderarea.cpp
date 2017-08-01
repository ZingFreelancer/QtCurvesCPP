#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent), m_backgroundColor(0, 0, 255),
m_shapeColor(255, 255, 255), m_shape(Astroid)
{}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    switch (m_shape)
    {
        case Astroid: m_backgroundColor = Qt::red; break;
        case Cycloid: m_backgroundColor = Qt::green; break;
        case HuygensCycloid: m_backgroundColor = Qt::blue; break;
        case HypoCycloid: m_backgroundColor = Qt::yellow; break;
        default: break;
    }
    painter.setBrush(m_backgroundColor);
    painter.setPen(m_shapeColor);

    //Drawing area
    painter.drawRect(this->rect());
    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());

}
