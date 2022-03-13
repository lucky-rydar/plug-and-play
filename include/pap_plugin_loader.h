#pragma once

#include <string>
#include <functional>
#include <exception>
#include <dlfcn.h>

namespace pap
{
    template <class InterfaceType>
    class plugin_loader
    {
        typedef InterfaceType* (*function_p)(); 

        const std::string get_instance_func_name = "get_instance";
        void* dl_handler = NULL;
        InterfaceType* instance = NULL;
        function_p get_instance = NULL;
    public:
        plugin_loader(std::string filename) {
            dl_handler = dlopen(("./" + filename).c_str(), RTLD_LAZY);

            if(dl_handler == NULL) {
                throw runtime_error(std::string(dlerror()));
            }

            get_instance = (function_p)dlsym(dl_handler, get_instance_func_name.c_str());
            instance = (InterfaceType*)get_instance();
        }

        InterfaceType* operator->() {
            return instance;
        }

        ~plugin_loader() {
            dlclose(dl_handler);
        }
    };
}