#pragma once
#include "Control.h"

class ControlFactory {
public:
    virtual Control* createForm() = 0;
    virtual Control* createLabel() = 0;
    virtual ~ControlFactory() {}
};