#include "Label.h"

void Label::setText(const std::string& text) {
    setlocale(LC_ALL, "Rus");
    labelText = text;
    std::cout << "Вызван метод setText у контролла Label: " << text << "\n";
}

std::string Label::getText() const {
    setlocale(LC_ALL, "Rus");
    std::cout << "Вызван метод getText у контролла Label\n";
    return labelText;
}

void Label::setPosition(int x, int y) {
    setlocale(LC_ALL, "Rus");
    std::cout << "Вызван метод setPosition у контролла Label\n";

    xPos = x;
    yPos = y;
}

std::pair<int, int> Label::getPosition() const {
    setlocale(LC_ALL, "Rus");
    std::cout << "Вызван метод getPosition у контролла Label\n";
    return { xPos, yPos };
}