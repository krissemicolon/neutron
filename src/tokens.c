#include <stddef.h>
#include <stdio.h>

#include "tokens.h"

unsigned short invert(unsigned short token) {
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
            return 0;
        break;
    }
}

/*
 *   Some Predicate Functions for the Preprocessor
 */

bool is_valid_token(char token) {
    switch(token) {
        case Right:
        case Left:
        case Inc:
        case Dec:
        case Write:
        case Read:
        case Rewind:
        case Up:
        case Down:
        case Await:
        case '[':
        case ']':
            return true;
        break;

        default:
            return false;
        break;
    }
}

bool is_rewindable_token(char token) {
    switch(token) {
        case Right:
        case Left:
        case Inc:
        case Dec:
        case Read:
            return true;
        break;

        default:
            return false;
        break;
    }
}