#pragma once
#include <app.h>
class i_plugin
{
public:
    virtual void setup(i_app* a) = 0;
};