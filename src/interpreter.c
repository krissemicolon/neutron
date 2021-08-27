#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned char tape[100000] = {0};
unsigned char *ptr = tape;

void interpret(char *input) {
    size_t i;
    size_t loop;

    for(int i = 0; input[i] != 0; i++) {
        switch(input[i]) {
            case '>':
                ++ptr;
            break;

            case '<':
                --ptr;
            break;

            case '+':
                ++*ptr;
            break;

            case '-':
                --*ptr;
            break;

            case '.':
                putchar(*ptr);
            break;
            
            case ',':
                *ptr = getchar();
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
        }
    }
}