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
    enum ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid };
    //Setter
    void setBackgroundColor(QColor color) { m_backgroundColor = color; }
    //Getter
    QColor getBackgroundColor() const
    { return m_backgroundColor; }

    void setShape(ShapeType shape) { m_shape = shape; }
    ShapeType getShape() const { return m_shape; }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:

public slots:

private:
    QColor m_backgroundColor;
    QColor m_shapeColor;
    ShapeType m_shape;

    QPointF compute_astroid(float t);
};

#endif // RENDERAREA_H
