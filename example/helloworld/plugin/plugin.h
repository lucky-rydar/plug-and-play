#pragma once
#include <pap.h>
#include <app.h>
#include <i_plugin.h>

class i_app;

PAP_DECLARE(plugin, i_plugin, "Mykhailo Didur", 1,
{
public:
    void setup(i_app* a) override;
})
