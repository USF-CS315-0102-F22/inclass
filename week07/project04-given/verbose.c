/* verbose.c - Implement a logging function for debugging */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "rv_emu.h"

bool g_verbose = false;

void verbose(char *fmt, ...) {
    if (g_verbose) {
        va_list args;
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
    }
}
