#ifndef TOKENS_H
#define TOKENS_H

#include <stdbool.h>

typedef enum {
    Right  = 62,
    Left   = 60,
    Inc    = 43,
    Dec    = 45,
    Write  = 46,
    Read   = 44,
    Rewind = 126,
    Up     = 94,
    Down   = 118,
    Await  = 64
} tokens;

bool is_valid_token(char);

bool is_rewindable_token(char);

unsigned short invert(unsigned short);

#endif