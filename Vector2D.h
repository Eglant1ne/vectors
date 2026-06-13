#pragma once
#include "Point2D.h"
#include <cmath>

class Vector2D : public Point2D {
public:
    // Вектор начинается в (0,0), конец — в точке (x, y)
    Vector2D(double x = 0.0, double y = 0.0);

    // Конструктор из точки — конец вектора совпадает с точкой
    explicit Vector2D(const Point2D& p);

    double length() const;

    // Умножение вектора на скаляр
    Vector2D operator*(double scalar) const;
    friend Vector2D operator*(double scalar, const Vector2D& v);

    // Скалярное произведение
    double operator*(const Vector2D& other) const;

    // Векторное произведение (z-компонента, т.к. 2D)
    // Фишка: используем operator/, потому что крест-произведение — это "деление"
    // пространства на две полуплоскости; знак результата показывает ориентацию.
    double operator/(const Vector2D& other) const;

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;

    bool operator==(const Vector2D& other) const;
    bool operator<(const Vector2D& other) const; // для std::sort по длине

    bool isPerpendicular(const Vector2D& other) const;
    double angleBetween(const Vector2D& other) const; // в радианах

    // Ввод/вывод переопределяем отдельно от Point2D,
    // чтобы выводить вектор как "vec(x, y)", а не просто точку.
    // Это и есть та самая "фишка": наследник переопределяет операторы
    // базового класса — они не виртуальные, но friend-функции в производном
    // классе создают собственные перегрузки для типа Vector2D.
    friend std::istream& operator>>(std::istream& in, Vector2D& v);
    friend std::ostream& operator<<(std::ostream& out, const Vector2D& v);
};
