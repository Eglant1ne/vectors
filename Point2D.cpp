#include "Point2D.h"

Point2D::Point2D(double x, double y) : x_(x), y_(y) {}

double Point2D::getX() const { return x_; }
double Point2D::getY() const { return y_; }
void Point2D::setX(double x) { x_ = x; }
void Point2D::setY(double y) { y_ = y; }

std::istream& operator>>(std::istream& in, Point2D& p) {
    in >> p.x_ >> p.y_;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Point2D& p) {
    out << "(" << p.x_ << ", " << p.y_ << ")";
    return out;
}
