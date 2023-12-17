#pragma once
#include "ControlFactory.h"

class MacOSControlFactory : public ControlFactory {
public:
    Control* createForm() override;
    Control* createLabel() override;
};