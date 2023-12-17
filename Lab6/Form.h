#pragma once
#include "Control.h"
#include <vector>

class Form : public Control {
public:
    void addControl(Control* control);

    void setPosition(int x, int y) override;
    std::pair<int, int> getPosition() const override;

private:
    std::vector<Control*> controls;
};