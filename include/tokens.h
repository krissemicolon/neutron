#ifndef TOKENS_H
#define TOKENS_H

typedef enum {
    Right, Left, Inc, Dec, Write, Read, Rewind, Up, Down, Await
} tokens;

unsigned short invert(unsigned short token);

#endif