# Лабараторная работа №1
## «Работа с Git и GitHub»
## по дисциплине: «Программирование»
### Цели и задачи работы: изучение платформы GitHub и практическое использование Git для хранения, обновления и распространения исходного кода проекта.
### Задание к работе: Разработать алгоритм решения задачи по индивидуальному заданию. 
### Геометрические фигуры. Реализовать функции вычисления параметров для двух-трех следующих геометрических фигур (по одной фигуре на студента):
### Прямоугольник – периметр, площадь, длина диагонали;
### Треугольник – периметр, площадь по формуле Герона, проверка на равнобедренность;
### Трапеция – периметр, площадь, длина средней линии;
### Окружность – длина окружности, площадь круга, площадь кругового сектора.

### Задание на прямоугольник выполнил Бутаков Никита Максимович, часть кода представлена ниже:
```C++
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
```

### Задание на Трапецию выполнил Когумбаев Данил Валерьевич, часть кода представлена ниже:
```C++
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
```
