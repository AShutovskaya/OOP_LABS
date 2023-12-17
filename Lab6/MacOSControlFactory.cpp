#include "MacOSControlFactory.h"
#include "Form.h"
#include "Label.h"

Control* MacOSControlFactory::createForm() {
    return new Form();
}

Control* MacOSControlFactory::createLabel() {
    return new Label();
}