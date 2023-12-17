#include "MacOSControlFactory.h"
#include "Form.h"
#include "Label.h"

int main() {
    setlocale(LC_ALL, "Rus");
    ControlFactory* factory = new MacOSControlFactory();

    Control* form = factory->createForm();

    Control* label = factory->createLabel();
    dynamic_cast<Form*>(form)->addControl(label);

    form->setPosition(256, 256);
    std::cout << "Форма находится на позиции: " << form->getPosition().first << ", " << form->getPosition().second << "\n";

    Label* labelControl = dynamic_cast<Label*>(label);
    if (labelControl) {
        labelControl->setText("Добро пожаловать!");
        std::cout << "Текст Label: " << labelControl->getText() << "\n";
    }

    delete form;
    delete label;
    delete factory;

    return 0;
}