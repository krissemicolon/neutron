#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tokens.h"
#include "interpreter.h"

unsigned char tape[100000] = {0};
unsigned char *ptr = tape;

void interpret(char *input) {
    size_t i;
    size_t loop;
    tokens t;

    for(int i = 0; input[i] != 0; i++) {
        switch(input[i]) {
            case Right:
                ++ptr;
            break;

            case Left:
                --ptr;
            break;

            case Inc:
                ++*ptr;
            break;

            case Dec:
                --*ptr;
            break;

            case Write:
                putchar(*ptr);
            break;

            case Read:
                *ptr = getchar();
            break;

            case Rewind:
                interpret((char)invert((unsigned short)input[i - 1]));
            break;

            case Up:
                continue;
            break;

            case Down:
                continue;
            break;

            case Await:
            break;

            case '[':
                if(*ptr != 0) {
                    break;
                }
                loop = 1;
                while(loop > 0) {
                    input[i] = input[++i];
                    if(input[i] == '[') {
                        loop++;
                    } else if (input[i] == ']') {
                        loop--;
                    }
                }
            break;

            case ']':
                if(!*ptr) {
                    break;
                }
                loop = 1;
                while (loop > 0) {
                    input[i] = input[--i];
                    if (input[i] == '[') {
                        loop--;
                    } else if (input[i] == ']') {
                        loop++;
                    }
                }
            break;

            default:
                continue;
            break;
        }
    }
}