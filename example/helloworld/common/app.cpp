#include "app.h"
#include "pap.h"

app::app() {
    cout << "application is initiated" << endl;
}

void app::api_for_plugin(string data) {
    cout << "written from plugin api: '" << data << "'" << endl;
}