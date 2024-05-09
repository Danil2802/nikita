#include <iostream>
#include <cmath>

using namespace std;

// ������� ��� ���������� ��������� ��������
float calculateTrapezoidPerimeter(float side1, float side2, float base1, float base2) {
    return side1 + side2 + base1 + base2;
}

// ������� ��� ���������� ������� ��������
float calculateTrapezoidArea(float base1, float base2, float height) {
    return (base1 + base2) * height / 2;
}

// ������� ��� ���������� ����� ������� ����� ��������
float calculateTrapezoidMedian(float base1, float base2) {
    return (base1 + base2) / 2;
}

int main() {
    setlocale(LC_ALL, "Russian");
    float side1, side2, base1, base2, height;
    cout << "������� ����� ������� �������� ����� ��������: ";
    cin >> side1;
    cout << "������� ����� ������� �������� ����� ��������: ";
    cin >> side2;
    cout << "������� ����� �������� ��������� ��������: ";
    cin >> base1;
    cout << "������� ����� ������� ��������� ��������: ";
    cin >> base2;
    cout << "������� ������ ��������: ";
    cin >> height;

    // �������� �� ������������� �����
    if (side1 < 0 || side2 < 0 || base1 < 0 || base2 < 0 || height < 0) {
        cout << "������� ������������� �����!" << endl;
        return 1;
    }

    cout << "�������� ��������: " << calculateTrapezoidPerimeter(side1, side2, base1, base2) << endl;
    cout << "������� ��������: " << calculateTrapezoidArea(base1, base2, height) << endl;
    cout << "����� ������� ����� ��������: " << calculateTrapezoidMedian(base1, base2) << endl;

    return 0;
}

