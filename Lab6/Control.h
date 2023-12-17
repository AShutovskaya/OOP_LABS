#include <iostream>
#pragma once

class Control {
public:
    virtual void setPosition(int x, int y) = 0;
    virtual std::pair<int, int> getPosition() const = 0;
    virtual ~Control() {}

protected:
    int xPos;
    int yPos;
};