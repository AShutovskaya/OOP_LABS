#include "Workflow.h"
#include "Keyboard.hpp"

int main()
{
    setlocale(LC_ALL, "Rus");
    Keyboard keyboard;

    keyboard.registerKey("W", []() { std::cout << " W  ������ \n"; }, []() { std::cout << " W �������� \n"; });
    keyboard.registerKey("A", []() { std::cout << " A ������ \n"; }, []() { std::cout << " A �������\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Ctrl+C ������\n"; }, []() { std::cout << "Ctrl+C ��������\n"; });
    keyboard.registerKey("Ctrl+X", []() { std::cout << "Ctrl+X ������ \n"; }, []() { std::cout << "Ctrl+X ��������\n"; });
  
    Workflow workflow(keyboard);

    workflow.add([&]() { workflow.keypress("W"); });
    workflow.add([&]() { workflow.keypress("A"); });
    workflow.add([&]() { workflow.keypress("Ctrl+C"); });
    workflow.add([&]() { workflow.keypress("Ctrl+X"); });

    workflow.add([&]() { workflow.undo(); });
    workflow.add([&]() { workflow.undo(); });

    std::cout << "������ ������\n";
    workflow.run();

    std::cout << "\n�������������� ������ � ����������\n";
    keyboard.registerKey("W",
        []() {std::cout << " W �������� �� �������� ������\n"; },
        []() { std::cout << " W\n"; } );
    keyboard.registerKey("A",
        []() { std::cout << " A �������� �� �������� �����\n"; },
        []() { std::cout << "������ A\n"; });
    keyboard.registerKey("Ctrl+C",
        []() { std::cout << " Ctrl+C �������� ��������� �����\n"; },
        []() { std::cout << "������ Ctrl+C\n";});
    keyboard.registerKey("Ctrl+X",
        []() { std::cout << "Ctrl+X �������� ��������� �����\n"; },
        []() { std::cout << "������ Ctrl+X\n"; });

    workflow.run();

    if (keyboard.isKeyRegistered("W"))
    {
        std::cout << "������� W ���������������� � �������\n";
    }

    return 0;
}
