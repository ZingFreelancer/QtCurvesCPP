#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent), m_backgroundColor(0, 0, 255),
    m_shape(Astroid), m_Pen(Qt::white)
{
    m_Pen.setWidth(2);
    on_shape_changed();
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(400, 400);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 400);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(m_backgroundColor);
    painter.setPen(m_Pen);

    //Drawing area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    QPointF prevPoint = compute(0);
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x() * m_Scale + center.x());
    prevPixel.setY(prevPoint.y() * m_Scale + center.y());
    float step = m_IntervalLength / m_StepCount;
    for(float t = 0; t < m_IntervalLength+step; t+= step)
    {
        QPointF point = compute(t);
        QPoint pixel;
        pixel.setX(point.x() * m_Scale + center.x());
        pixel.setY(point.y() * m_Scale + center.y());

        //painter.drawPoint(pixel);
        painter.drawLine(pixel, prevPixel);
        prevPixel = pixel;
    }
}

void RenderArea::on_shape_changed()
{
    switch (m_shape)
    {
        case Astroid:
            m_Scale = 90;
            m_IntervalLength = 2 * M_PI;
            m_StepCount = 256;
            shapeName = "[Astroid]";
        break;
        case Cycloid:
            m_Scale = 10;
            m_IntervalLength = 4 * M_PI;
            m_StepCount = 128;
            shapeName = "[Cycloid]";
        break;
        case HuygensCycloid:
            m_Scale = 12;
            m_IntervalLength = 4 * M_PI;
            m_StepCount = 256;
            shapeName = "[Huygens Cycloid]";
        break;
        case HypoCycloid:
            m_Scale = 40;
            m_IntervalLength = 2 * M_PI;
            m_StepCount = 256;
            shapeName = "[Hypo Cycloid]";
        break;
        case Line:
            m_IntervalLength = 2;   //Not really needed
            m_Scale = 100;           //Line length in pixels
            m_StepCount = 128;
            shapeName = "[Line]";
        break;
        case Circle:
            m_IntervalLength = 2 * M_PI;
            m_Scale = 165;
            m_StepCount = 128;
            shapeName = "[Cirlce]";
        break;
        case Ellipse:
            m_Scale = 75;
            m_IntervalLength = 2 * M_PI;
            m_StepCount = 256;
            shapeName = "[Ellipse]";
        break;
        case Fancy:
            m_Scale = 12;
            m_StepCount = 512;
            m_IntervalLength = 12*M_PI;
            shapeName = "[Fancy]";
        break;
        case Starfish:
            m_Scale = 25;
            m_StepCount = 256;
            m_IntervalLength = 6 * M_PI;
            shapeName = "[Starfish]";
        break;
        default: break;
    }
}

QPointF RenderArea::compute(float t)
{
    switch (m_shape)
    {
        case Astroid: return compute_astroid(t);
        case Cycloid: return compute_cycloid(t);
        case HuygensCycloid: return compute_huygensCycloid(t);
        case HypoCycloid: return compute_hypoCycloid(t);
        case Line: return compute_line(t);
        case Circle: return compute_circle(t);
        case Ellipse: return compute_ellipse(t);
        case Fancy: return compute_fancy(t);
        case Starfish: return compute_starfish(t);
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

QPointF RenderArea::compute_ellipse(float t)
{
    return QPointF(1.7 * cos(t), 1.2 * sin(t));
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

QPointF RenderArea::compute_line(float t)
{
    return QPointF(1-t, 1-t);
}

QPointF RenderArea::compute_circle(float t)
{
    return QPointF(cos(t), sin(t));
}

QPointF RenderArea::compute_fancy(float t)
{
    const float a(11.0f);
    const float b(6.0f);
    return QPointF(
                a * cos(t) - b * cos ((a / b) * t),
                a * sin(t) - b * sin ((a / b) * t));
}

QPointF RenderArea::compute_starfish(float t)
{
    const float R = 5.0f;
    const float r = 3.0f;
    const float d = 5.0f;

    return QPointF(
                (R - r) * cos(t) + d * cos(t * (R - r) / r),
                (R - r) * sin(t) - d * sin(t * (R - r) / r));
}
