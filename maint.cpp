
#include <cmath>
#include <algorithm>
#include <iostream>

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