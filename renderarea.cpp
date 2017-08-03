#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent), m_backgroundColor(0, 0, 255),
m_shapeColor(255, 255, 255), m_shape(Astroid)
{ on_shape_changed(); }

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
    painter.setBrush(m_backgroundColor);
    painter.setPen(m_shapeColor);

    //Drawing area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    float step = m_IntervalLength / m_StepCount;
    for(float t = 0; t < m_IntervalLength; t+= step)
    {
        QPointF point = compute(t);
        QPoint pixel;
        pixel.setX(point.x() * m_Scale + center.x());
        pixel.setY(point.y() * m_Scale + center.y());

        painter.drawPoint(pixel);
    }
}

void RenderArea::on_shape_changed()
{
    switch (m_shape)
    {
        case Astroid:
            m_Scale = 40;
            m_IntervalLength = 2 * M_PI;
            m_StepCount = 256;
        break;
        case Cycloid:
            m_Scale = 4;
            m_IntervalLength = 6 * M_PI;
            m_StepCount = 128;
        break;
        case HuygensCycloid:
            m_Scale = 4;
            m_IntervalLength = 4 * M_PI;
            m_StepCount = 256;
        break;
        case HypoCycloid:
            m_Scale = 15;
            m_IntervalLength = 2 * M_PI;
            m_StepCount = 256;
        break;
        default: break;
    }
}

QPointF RenderArea::compute(float t)
{
    switch (m_shape)
    {
        case Astroid: return compute_astroid(t); break;
        case Cycloid: return compute_cycloid(t); break;
        case HuygensCycloid: return compute_huygensCycloid(t); break;
        case HypoCycloid: return compute_hypoCycloid(t); break;
        default: break;
    }
    return QPointF(0,0);
}

QPointF RenderArea::compute_astroid(float t)
{
    float cos_t = cos (t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;

    return QPointF(x, y);
}

QPointF RenderArea::compute_cycloid(float t)
{
    return QPointF(1.5 * (1 - cos(t)),  //X
                   1.5 * (t - sin(t))); //Y
}

QPointF RenderArea::compute_huygensCycloid(float t)
{
    return QPointF(4 * (3 * cos(t) - cos(3 * t)),  //X
                   4 * (3 * sin(t) - sin(3 * t))); //Y
}

QPointF RenderArea::compute_hypoCycloid(float t)
{
    return QPointF(1.5 *(2 * cos(t) + cos(2 * t)),    //X
                   1.5 * (2 * sin(t) - sin(2 * t)));  //Y
}
