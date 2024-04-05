#include <iostream>
#include <cmath>

using namespace std;

class Trapezium {
private:
    double a, b, h, c;

public:
    Trapezium(double topBase, double bottomBase, double height, double side) {
        a = topBase;
        b = bottomBase;
        h = height;
        c = side;
    }

    double getPerimeter() {
        return a + b + 2 * c;
    }

    double getArea() {
        return 0.5 * (a + b) * h;
    }

    double getMidLineLength() {
        return (a + b) / 2;
    }
};

int main() {
    double topBase, bottomBase, height, side;
    cout << "Введите верхнюю основу трапеции: ";
    cin >> topBase;
    cout << "Введите нижнюю основу трапеции: ";
    cin >> bottomBase;
    cout << "Введите высоту трапеции: ";
    cin >> height;
    cout << "Введите длину боковой стороны: ";
    cin >> side;

    Trapezium trapezium(topBase, bottomBase, height, side);

    cout << "Периметр трапеции: " << trapezium.getPerimeter() << std::endl;
    cout << "Площадь трапеции: " << trapezium.getArea() << std::endl;
    cout << "Длина средней линии трапеции: " << trapezium.getMidLineLength() << std::endl;

    return 0;
}