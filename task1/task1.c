#include "task1.h"
#include <ctype.h>

void str_lower(char *orig, char *copy) {
    while (*orig) {
        *copy = tolower(*orig);
        orig++;
        copy++;
    }
    *copy = '\0';
}

void str_lower_mutate(char *orig) {
    while (*orig) {
        *orig = tolower(*orig);
        orig++;
    }
}