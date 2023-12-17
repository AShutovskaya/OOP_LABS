#include "Workflow.h"
#include "Keyboard.hpp"

int main()
{
    setlocale(LC_ALL, "Rus");
    Keyboard keyboard;

    keyboard.registerKey("W", []() { std::cout << " W  нажата \n"; }, []() { std::cout << " W отменена \n"; });
    keyboard.registerKey("A", []() { std::cout << " A нажата \n"; }, []() { std::cout << " A оменена\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Ctrl+C нажата\n"; }, []() { std::cout << "Ctrl+C отменена\n"; });
    keyboard.registerKey("Ctrl+X", []() { std::cout << "Ctrl+X нажата \n"; }, []() { std::cout << "Ctrl+X отменена\n"; });
  
    Workflow workflow(keyboard);

    workflow.add([&]() { workflow.keypress("W"); });
    workflow.add([&]() { workflow.keypress("A"); });
    workflow.add([&]() { workflow.keypress("Ctrl+C"); });
    workflow.add([&]() { workflow.keypress("Ctrl+X"); });

    workflow.add([&]() { workflow.undo(); });
    workflow.add([&]() { workflow.undo(); });

    std::cout << "Первый запуск\n";
    workflow.run();

    std::cout << "\nПереназначение клавиш и перезапуск\n";
    keyboard.registerKey("W",
        []() {std::cout << " W отвечает за движение вперед\n"; },
        []() { std::cout << " W\n"; } );
    keyboard.registerKey("A",
        []() { std::cout << " A отвечает за движение влево\n"; },
        []() { std::cout << "отмена A\n"; });
    keyboard.registerKey("Ctrl+C",
        []() { std::cout << " Ctrl+C копирует выбранный текст\n"; },
        []() { std::cout << "отмена Ctrl+C\n";});
    keyboard.registerKey("Ctrl+X",
        []() { std::cout << "Ctrl+X вырезает выбранный текст\n"; },
        []() { std::cout << "отмена Ctrl+X\n"; });

    workflow.run();

    if (keyboard.isKeyRegistered("W"))
    {
        std::cout << "Клавиша W зарегистрирована в системе\n";
    }

    return 0;
}
