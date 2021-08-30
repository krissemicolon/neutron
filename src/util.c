#include <stdlib.h>
#include <string.h>

void append_char(char *s, char c) {
    size_t s_len = strlen(s);
    s[s_len] = c;
    s[s_len + 1] = '\0';
}