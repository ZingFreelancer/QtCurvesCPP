#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    enum ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line };
    //Render area background setter
    void setBackgroundColor(QColor color) { m_backgroundColor = color; }
    //Render area background getter
    QColor getBackgroundColor() const
    { return m_backgroundColor; }

    //Setters
    void setShape(ShapeType shape) { m_shape = shape; on_shape_changed(); }
    void setScale(float scale) { m_Scale = scale; repaint(); }
    void setIntervalLength(float length) { m_IntervalLength = length; repaint(); }
    void setStepCount(int count) { m_StepCount = count; repaint(); }

    //Getters
    ShapeType getShape() const { return m_shape; }
    float getScale() const { return m_Scale; }
    float getIntervalLength() const { return m_IntervalLength; }
    int getStepCount() const { return m_StepCount; }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

//Member variables
private:
    QColor m_backgroundColor;
    QColor m_shapeColor;
    ShapeType m_shape;
    int m_StepCount;
    float m_Scale;
    float m_IntervalLength;

//Functions
private:
    QPointF compute(float t);
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygensCycloid(float t);
    QPointF compute_hypoCycloid(float t);
    void on_shape_changed();
    QPointF compute_line(float t);
};

#endif // RENDERAREA_H
