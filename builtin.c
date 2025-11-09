#include "turt.h"

int turt_exit(char **args) {
    (void) args;
    loading();
    exit(EXIT_SUCCESS);
}