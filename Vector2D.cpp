#include "Vector2D.h"
#include <stdexcept>

static constexpr double EPS = 1e-9;

Vector2D::Vector2D(double x, double y) : Point2D(x, y) {}

Vector2D::Vector2D(const Point2D& p) : Point2D(p) {}

double Vector2D::length() const {
    return std::sqrt(x_ * x_ + y_ * y_);
}

Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x_ * scalar, y_ * scalar);
}

Vector2D operator*(double scalar, const Vector2D& v) {
    return v * scalar;
}

double Vector2D::operator*(const Vector2D& other) const {
    return x_ * other.x_ + y_ * other.y_;
}

double Vector2D::operator/(const Vector2D& other) const {
    return x_ * other.y_ - y_ * other.x_;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x_ + other.x_, y_ + other.y_);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x_ - other.x_, y_ - other.y_);
}

bool Vector2D::operator==(const Vector2D& other) const {
    return std::abs(x_ - other.x_) < EPS && std::abs(y_ - other.y_) < EPS;
}

bool Vector2D::operator<(const Vector2D& other) const {
    return (x_ * x_ + y_ * y_) < (other.x_ * other.x_ + other.y_ * other.y_);
}

bool Vector2D::isPerpendicular(const Vector2D& other) const {
    return std::abs(*this * other) < EPS;
}

double Vector2D::angleBetween(const Vector2D& other) const {
    double lens = length() * other.length();
    if (lens < EPS) {
        throw std::invalid_argument("zero vector");
    }
    double cosVal = (*this * other) / lens;
    cosVal = std::max(-1.0, std::min(1.0, cosVal));
    return std::acos(cosVal);
}

std::istream& operator>>(std::istream& in, Vector2D& v) {
    in >> v.x_ >> v.y_;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Vector2D& v) {
    out << "vec(" << v.x_ << ", " << v.y_ << ")";
    return out;
}
