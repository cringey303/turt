#include "turt.h"

// WRAPPERS

void Getcwd(char *buf, size_t size) {
    if (NULL == getcwd(buf, size)) {
        perror(RED"getcwd failed"RESET);
        exit(EXIT_FAILURE);
    }
}