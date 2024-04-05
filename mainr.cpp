#include <iostream>
#include <cmath>

using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }

    double getArea() {
        return width * height;
    }

    double getDiagonalLength() {
        return sqrt(width * width + height * height);
    }
};

int main() {
    double width, height;
    cout << "Введите ширину прямоугольника: ";
    cin >> width;
    cout << "Введите высоту прямоугольника: ";
    cin >> height;

    Rectangle rect(width, height);

    cout << "Периметр прямоугольника: " << rect.getPerimeter() << std::endl;
    cout << "Площадь прямоугольника: " << rect.getArea() << std::endl;
    cout << "Длина диагонали прямоугольника: " << rect.getDiagonalLength() << std::endl;

    return 0;
}