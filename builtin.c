#include "turt.h"

int turt_exit(char **args) {
    (void) args;
    loading();
    exit(EXIT_SUCCESS);
}

int turt_env(char **args) {
    extern char **environ;

    (void) args;
    if (!environ) {return (1);}
    
    for (int i = 0; environ[i]; i++) {p("%s\n", environ[i]);}
    
    return (0);
}