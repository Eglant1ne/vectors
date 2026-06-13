#pragma once
#include <iostream>

class Point2D {
public:
    Point2D(double x = 0.0, double y = 0.0);

    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);

    friend std::istream& operator>>(std::istream& in, Point2D& p);
    friend std::ostream& operator<<(std::ostream& out, const Point2D& p);

protected:
    double x_;
    double y_;
};
