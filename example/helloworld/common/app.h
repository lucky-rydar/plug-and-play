#pragma once
#include <iostream>
#include <string>
#include <i_app.h>

using namespace std;

class app : public i_app
{
public:
    app();

    void api_for_plugin(string data) override;
};
