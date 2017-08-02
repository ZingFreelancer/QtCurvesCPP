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
        QPointF point = compute_astroid(t);
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
        case Cycloid: m_backgroundColor = Qt::green; break;
        case HuygensCycloid: m_backgroundColor = Qt::blue; break;
        case HypoCycloid: m_backgroundColor = Qt::yellow; break;
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
    float cos_t = cos (t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;

    return QPointF(x, y);
}

QPointF RenderArea::compute_huygensCycloid(float t)
{
    float cos_t = cos (t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;

    return QPointF(x, y);
}

QPointF RenderArea::compute_hypoCycloid(float t)
{
    float cos_t = cos (t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;

    return QPointF(x, y);
}
