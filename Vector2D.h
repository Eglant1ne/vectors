#pragma once
#include "Point2D.h"
#include <cmath>

class Vector2D : public Point2D {
public:
    Vector2D(double x = 0.0, double y = 0.0);

    explicit Vector2D(const Point2D& p);

    double length() const;

    Vector2D operator*(double scalar) const;
    friend Vector2D operator*(double scalar, const Vector2D& v);

    double operator*(const Vector2D& other) const;


    double operator/(const Vector2D& other) const;

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;

    bool operator==(const Vector2D& other) const;
    bool operator<(const Vector2D& other) const;

    bool isPerpendicular(const Vector2D& other) const;
    double angleBetween(const Vector2D& other) const; // в радианах

    friend std::istream& operator>>(std::istream& in, Vector2D& v);
    friend std::ostream& operator<<(std::ostream& out, const Vector2D& v);
};
