#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned char tape[30000] = {0};
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
                *ptr += 1;                
            break;

            case '-':
                *ptr -= 1;
            break;

            case '.':
                putchar(*ptr);
            break;
            
            case ',':
                *ptr = getchar();
            break;
        }
    }
}