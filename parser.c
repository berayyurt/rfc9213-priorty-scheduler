#include <stdio.h>
#include "parser.h"

int parse_priority(const char *header) {
    int priority;

    if (sscanf(header, "u=%d", &priority) == 1) {
        return priority;
    }

    return 5;
}
