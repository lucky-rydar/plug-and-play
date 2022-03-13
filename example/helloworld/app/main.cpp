#include <app.h>
#include <pap.h>
#include <i_plugin.h>

int main(int argc, char** argv) {
    app a;
    try {
        string plugin_name = "libplugin.so";
        pap::plugin_loader<i_plugin> p(plugin_name);
        p->setup(&a);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
