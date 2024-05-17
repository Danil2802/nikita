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

// Функция для вычисления периметра прямоугольника
float calculateRectanglePerimeter(float length, float width) {
    return 2 * (length + width);
}

// Функция для вычисления площади прямоугольника
float calculateRectangleArea(float length, float width) {
    return length * width;
}

// Функция для вычисления длины диагонали прямоугольника
float calculateRectangleDiagonal(float length, float width) {
    return sqrt(pow(length, 2) + pow(width, 2));
}

int main() {
    setlocale(LC_ALL, "Russian");
    float length, width;
    cout << "Введите длину прямоугольника: ";
    cin >> length;
    cout << "Введите ширину прямоугольника: ";
    cin >> width;

    // Проверка на отрицательные числа
    if (length < 0 || width < 0) {
        cout << "Введите положительные числа!" << endl;
        return 1;
    }

    cout << "Периметр прямоугольника: " << calculateRectanglePerimeter(length, width) << endl;
    cout << "Площадь прямоугольника: " << calculateRectangleArea(length, width) << endl;
    cout << "Длина диагонали прямоугольника: " << calculateRectangleDiagonal(length, width) << endl;

    return 0;
}
```

### Задание на Трапецию выполнил Когумбаев Данил Валерьевич, часть кода представлена ниже:
```C++
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Функция для проверки возможности построения трапеции
bool isTrapezoidPossible(float a, float b, float c, float d) {
    // Сортируем стороны по возрастанию
    float sides[4] = { a, b, c, d };
    sort(sides, sides + 4);

    // Проверяем условие для возможности построения трапеции
    // Сумма двух наименьших сторон должна быть больше одной из оставшихся сторон
    return (sides[0] + sides[1] > sides[2]) && (sides[1] + sides[2] > sides[3]);
}

// Функция для вычисления периметра трапеции
float calculateTrapezoidPerimeter(float side1, float side2, float base1, float base2) {
    return side1 + side2 + base1 + base2;
}

// Функция для вычисления площади трапеции
float calculateTrapezoidArea(float base1, float base2, float height) {
    return (base1 + base2) * height / 2;
}

// Функция для вычисления длины средней линии трапеции
float calculateTrapezoidMedian(float base1, float base2) {
    return (base1 + base2) / 2;
}

int main() {
    setlocale(LC_ALL, "Russian");
    float side1, side2, base1, base2, height;
    cout << "Введите длину первого бокового ребра трапеции: ";
    cin >> side1;
    cout << "Введите длину второго бокового ребра трапеции: ";
    cin >> side2;
    cout << "Введите длину верхнего основания трапеции: ";
    cin >> base1;
    cout << "Введите длину нижнего основания трапеции: ";
    cin >> base2;
    cout << "Введите высоту трапеции: ";
    cin >> height;

    // Проверка на отрицательные числа
    if (side1 < 0 || side2 < 0 || base1 < 0 || base2 < 0 || height < 0) {
        cout << "Введите положительные числа!" << endl;
        return 1;
    }

    // Проверка на соотношение высоты и боковой стороны
    if (height > side1 || height > side2) {
        cout << "Высота должна быть меньше боковой стороны!" << endl;
        return 1;
    }

    // Проверка на возможность построения трапеции
    if (!isTrapezoidPossible(side1, side2, base1, base2)) {
        cout << "Трапеция невозможна." << endl;
        return 1;
    }

    cout << "Периметр трапеции: " << calculateTrapezoidPerimeter(side1, side2, base1, base2) << endl;
    cout << "Площадь трапеции: " << calculateTrapezoidArea(base1, base2, height) << endl;
    cout << "Длина средней линии трапеции: " << calculateTrapezoidMedian(base1, base2) << endl;

    return 0;
}
```
