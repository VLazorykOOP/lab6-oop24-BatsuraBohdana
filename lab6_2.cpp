#include <iostream>
#include <cmath>
using namespace std;

// Абстрактний клас
class Figure {
public:
    virtual double area() const = 0; // Чиста віртуальна функція
    virtual ~Figure() {} // Віртуальний деструктор
};

// Прямокутник
class Rectangle : public Figure {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

// Коло
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

// Прямокутний трикутник
class RightTriangle : public Figure {
private:
    double base, height;
public:
    RightTriangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
};

// Трапеція
class Trapezoid : public Figure {
private:
    double base1, base2, height;
public:
    Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}
    double area() const override {
        return 0.5 * (base1 + base2) * height;
    }
};

// Основна функція
int main() {
    const int SIZE = 4;
    Figure* figures[SIZE];

    figures[0] = new Rectangle(4, 5);
    figures[1] = new Circle(3);
    figures[2] = new RightTriangle(3, 4);
    figures[3] = new Trapezoid(5, 7, 4);

    for (int i = 0; i < SIZE; ++i) {
        cout << "Площа фігури " << i + 1 << " = " << figures[i]->area() << endl;
    }

    // Звільнення пам'яті
    for (int i = 0; i < SIZE; ++i) {
        delete figures[i];
    }

    return 0;
}