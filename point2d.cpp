#include <QDebug>
#include <QtMath>

#include "point2d.h"


Point2d::Point2d(float x, float y): x(x), y(y){};

float Point2d::distanceBetweenPoints(Point2d &point1, Point2d &point2)
{
    return qSqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}

void Point2d::show()
{
    qDebug() << x << " " << y;
}
