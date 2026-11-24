#ifndef LUAMAC_RET_CODES_H
#define LUAMAC_RET_CODES_H

#include "hlib/Array.h"
#include "hlib/String.h"

enum {
    RET_OK,
    RET_BAD_ARGS
};

extern struct luamac_state_t {
    hlib::array_t<hlib::string_t> filesInput; 
    hlib::string_t output;

    bool verbose = false;
} g_state;

#endif

