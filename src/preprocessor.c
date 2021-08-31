#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "util.h"
#include "tokens.h"

char *preprocess(char *input) {
    register char *output = (char *)malloc(sizeof(char) * 6000);

    for(int i = 0; input[i] != 0; i++) {
        if(is_valid_token(input[i])) {
            if(is_rewindable_token(input[i]) && input[i + 1] == Rewind) { 
                i++; 
                continue; 
            } else if(!is_rewindable_token(input[i]) && input[i + 1] == Rewind) {
                fprintf(stderr, "Syntax Error: Invalid use of Rewind ('~')\n");
            }

            append_char(output, input[i]);
        } else if(input[i + 1] == Rewind) {
            fprintf(stderr, "Syntax Error: Invalid use of Rewind ('~')\n");
        }
    }
    return output;
}