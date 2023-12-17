#include "Form.h"

void Form::addControl(Control* control) {
    controls.push_back(control);
}

void Form::setPosition(int x, int y) {
    setlocale(LC_ALL, "Rus");
    std::cout << "������ ����� setPosition � ��������� Form\n";

    xPos = x;
    yPos = y;
}

std::pair<int, int> Form::getPosition() const {
    setlocale(LC_ALL, "Rus");
    std::cout << "������ ����� getPosition � ��������� Form\n";
    return { xPos, yPos };
}