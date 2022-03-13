#pragma once

#include <string>
#include <functional>

#define PAP_DECLARE(pap_class_name, interface, pap_author, pap_version, pap_class_body) \
class pap_class_name : public interface \
pap_class_body; \
extern "C" pap_class_name* get_instance() \
{ \
    pap_class_name* instance = new pap_class_name(); \
    return instance;\
} \
extern "C" const char author[] = pap_author; \
extern "C" const unsigned int version = pap_version;
