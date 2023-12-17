#include "Label.h"

void Label::setText(const std::string& text) {
    setlocale(LC_ALL, "Rus");
    labelText = text;
    std::cout << "������ ����� setText � ��������� Label: " << text << "\n";
}

std::string Label::getText() const {
    setlocale(LC_ALL, "Rus");
    std::cout << "������ ����� getText � ��������� Label\n";
    return labelText;
}

void Label::setPosition(int x, int y) {
    setlocale(LC_ALL, "Rus");
    std::cout << "������ ����� setPosition � ��������� Label\n";

    xPos = x;
    yPos = y;
}

std::pair<int, int> Label::getPosition() const {
    setlocale(LC_ALL, "Rus");
    std::cout << "������ ����� getPosition � ��������� Label\n";
    return { xPos, yPos };
}