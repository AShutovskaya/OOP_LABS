#pragma once
#include "keyboard.hpp"

class Workflow
{
public:
    explicit Workflow(Keyboard& keyboard) : keyboard(keyboard) {}

    void keypress(const std::string& key);

    void undo();

    void run();

    void add(const Action& action);

private:
    Keyboard& keyboard;
    std::vector<Action> actions;
};