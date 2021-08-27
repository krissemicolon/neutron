#ifndef TOKENS_H
#define TOKENS_H

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

unsigned short invert(unsigned short token);

#endif