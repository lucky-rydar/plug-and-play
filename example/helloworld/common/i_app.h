#pragma once
#include <string>

using namespace std;

class i_app
{
public:
    virtual void api_for_plugin(string data) = 0;
};