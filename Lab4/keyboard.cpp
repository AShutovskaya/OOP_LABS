#include "keyboard.hpp"
void Keyboard::pressKey(const std::string& key)
{
    assert(keymap.count(key) && "������ ������������ ������� ");
    history.push_back(key);
    keymap[key].first();
}
void Keyboard::undo()
{
    if (!history.empty())
    {
        std::cout << "������ ��� : " << history.back() << "\n";
        keymap[history.back()].second();
        history.pop_back();
    }
}
bool Keyboard::isKeyRegistered(const std::string& key) const
{
    return keymap.count(key) > 0;
}