#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tokens.h"
#include "preprocessor.h"
#include "util.h"

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

void print_result(char *name, bool passed) {
    if(passed) {
        fprintf(stdout, "Test: %s%s Passed!%s\n", name, KGRN, KNRM);
    } else {
        fprintf(stderr, "Test: %s%s Failed!%s\n", name, KRED, KNRM);
    }
}

int main() {
    // TOKENS SECTION ========================
    printf("-- TOKENS.C TESTS: --\n");

    bool res_invert = false;
    if(invert(Inc) == Dec) { res_invert = true; }
    print_result("invert()", res_invert);

    bool res_is_valid_token = false;
    if(is_valid_token(Rewind) == true) { res_is_valid_token = true; }
    print_result("is_valid_token()", res_is_valid_token);

    bool res_is_rewindable_token = false;
    if(is_rewindable_token(Inc) == true) { res_is_rewindable_token = true; }
    print_result("is_rewindable_token()", res_is_rewindable_token);

    printf("\n");

    // PREPROCESSOR SECTION ========================
    printf("-- PREPROCESSOR.C TESTS: --\n");

    bool res_preprocess = false;
    if(strcmp(preprocess("this is not src this is src: [+]- some > other > comment"), "[+]->>") == 0) { res_preprocess = true; }
    print_result("preprocess()", res_preprocess);

    printf("\n");

    // UTIL SECTION ========================
    printf("-- UTIL.C TESTS --\n");

    bool res_append_char = false;
    char s[12] = "templeo";
    char c = 's';
    append_char(s, c);
    if(strcmp(s, "templeos") == 0) { res_append_char = true; }
    print_result("append_char()", res_append_char);

    printf("\n");

    return 0;
}