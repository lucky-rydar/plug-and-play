#include "plugin.h"

void plugin::setup(i_app* app) {
    app->api_for_plugin("Hello world");
}
