#ifndef POINT2D_H
#define POINT2D_H



class Point2d

{
    float x;
    float y;
public:
    Point2d(float x, float y);

    static float distanceBetweenPoints(Point2d &point1, Point2d &point2);
    void show();
};

#endif // POINT2D_H
