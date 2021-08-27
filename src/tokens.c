#include <stddef.h>

#include "tokens.h"

unsigned short invert(unsigned short token) {
    tokens t;

    switch(token) {
        case Right:
            return Left;
        break;

        case Left:
            return Right;
        break;

        case Inc:
            return Dec;
        break;

        case Dec:
            return Inc;
        break;

        case Up:
            return Down;
        break;

        case Down:
            return Up;
        break;

        default:
            return NULL;
        break;
    }
}