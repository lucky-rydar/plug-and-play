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
        const std::string version_sym = "version";
        const std::string author_sym = "author";

        void* dl_handler = NULL;
        InterfaceType* instance = NULL;
        function_p get_instance = NULL;

        char* version;
        char* author;
    public:
        plugin_loader(std::string filename) {
            dl_handler = dlopen(("./" + filename).c_str(), RTLD_LAZY);

            if(dl_handler == NULL) {
                throw runtime_error(std::string(dlerror()));
            }

            get_instance = (function_p)dlsym(dl_handler, get_instance_func_name.c_str());
            instance = (InterfaceType*)get_instance();

            version = (char*)dlsym(dl_handler, version_sym.c_str());
            author = (char*)dlsym(dl_handler, author_sym.c_str());
        }

        InterfaceType* operator->() {
            return instance;
        }

        std::string get_version() {
            return std::string(version);
        }

        std::string get_author() {
            return std::string(author);
        }

        ~plugin_loader() {
            dlclose(dl_handler);
        }
    };
}