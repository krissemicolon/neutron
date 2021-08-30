#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "util.h"
#include "tokens.h"

char *preprocess(char *input) {
    register char *output = malloc(sizeof(char) * 6000);

    for(int i = 0; is_valid_token(input[i]) && input[i] != 0; i++) {
        if(input[i + 1] == Rewind && is_rewindable_token(input[i])) { continue; }

        append_char(output, input[i]);
    }
    return output;
}