#pragma once
#include "Control.h"
#include <string>

class Label : public Control {
public:
    void setText(const std::string& text);
    std::string getText() const;

    void setPosition(int x, int y) override;
    std::pair<int, int> getPosition() const override;

private:
    std::string labelText;
};