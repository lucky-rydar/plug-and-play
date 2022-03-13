#pragma once

#include <string>
#include <functional>

#define PAP_DECLARE(pap_class_name, interface, pap_author, pap_version, pap_class_body) \
class pap_class_name : public interface \
pap_class_body; \
extern "C" pap_class_name* get_instance() \
{ \
    static pap_class_name instance; \
    return &instance;\
} \
extern "C" const char author[] = pap_author; \
extern "C" const char version[] = pap_version;
