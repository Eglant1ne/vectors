#include <iostream>
#include <vector>
#include <algorithm>
#include <numbers>
#include "Vector2D.h"

int main() {
    const int N = 12;
    std::vector<Vector2D> vecs(N);

    std::cout << "Введите " << N << " векторов (каждый — два числа x y):\n";
    for (auto& v : vecs) {
        std::cin >> v;
    }

    std::sort(vecs.begin(), vecs.end());

    std::cout << "\nОтсортированные векторы по длине:\n";
    for (const auto& v : vecs) {
        std::cout << v << "  |длина| = " << v.length() << "\n";
    }

    const Vector2D& a = vecs.front();
    const Vector2D& b = vecs.back();

    std::cout << "\n--- Демонстрация ---\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "b - a = " << (b - a) << "\n";
    std::cout << "a * 3 = " << (a * 3) << "\n";
    std::cout << "Скалярное произведение a·b = " << (a * b) << "\n";
    std::cout << "Векторное произведение a×b = " << (a / b) << "\n";
    std::cout << "a == b: " << std::boolalpha << (a == b) << "\n";
    std::cout << "Перпендикулярны: " << a.isPerpendicular(b) << "\n";

    if (a.length() > 1e-9 && b.length() > 1e-9) {
        double angle = a.angleBetween(b);
        std::cout << "Угол между a и b: " << angle << " рад ("
                  << angle * 180.0 / std::numbers::pi << "°)\n";
    }

    return 0;
}
