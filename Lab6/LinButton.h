#pragma once
#include "Control.h"
#include "Button.h"
#include <string>
#include <iostream>

class LinButton : public Button, public Control
{
    std::string text;

public:
    void setText(std::string& newText) override
    {
        text = newText;
    }

    void setOnClick() override
    {
        std::cout << "Method called from Linux " << '\n';
    }

    const std::string& getText() const override
    {
        return text;
    }

    void click() override
    {
        std::cout << "Button clicked" << '\n';
    }
};