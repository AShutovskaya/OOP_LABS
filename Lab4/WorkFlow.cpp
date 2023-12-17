#include "Workflow.h"
void Workflow::keypress(const std::string& key)
{
    keyboard.pressKey(key);
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
}
void Workflow::undo()
{
    keyboard.undo();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
void Workflow::run()
{
    for (const auto& action : actions)
    {
        action();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
void Workflow::add(const Action& action)
{
    actions.push_back(action);
}
