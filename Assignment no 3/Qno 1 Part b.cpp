#include <iostream>
#include<string>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }
};

int main() {

    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Shape* shape1 = &circle;
    Shape* shape2 = &rectangle;
    std::cout << "Area of Circle: " << shape1->area() << std::endl;
    std::cout << "Area of Rectangle: " << shape2->area() << std::endl;
    return 0;
}
