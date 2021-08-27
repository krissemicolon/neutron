#include "tokens.h"

unsigned short invert(unsigned short token) {
    t = tokens;

    switch(token) {
        case t.Right:
            return t.Left;
        break;

        case t.Left:
            return t.Right;
        break;

        case t.Inc:
            return t.Dec;
        break;

        case t.Dec:
            return t.Inc;
        break;

        case t.Up:
            return t.Down;
        break;

        case t.Down:
            return t.Up;
        break;
    }
}