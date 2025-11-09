#include "turt.h"
#include <stdio.h>

char *turt_read_line(void) {
    char *buf;
    size_t bufsize;
    char cwd[BUFSIZ]; //current working directory
    buf = NULL;

    Getcwd(cwd, sizeof(cwd));
    p(CYAN"[%s] "RESET GREEN"turt$> "RESET, cwd);

    if (getline(&buf, &bufsize, stdin) == -1) {
        buf = NULL;
        if (feof(stdin)) { // End Of File
            p(RED"[EOF]"RESET);
            exit(EXIT_SUCCESS);
        } else {
            p(RED"Getline Failed"RESET);
            exit(EXIT_FAILURE);
        }            
    }
    return buf;
}

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    char *line;

    printbanner();
    //REPL
    //Read-Eval-Print Loop for Turtle graphics commands
    while ((line = turt_read_line())) {
        //1) get line
        p("%s\n", line);

        //2) get tokens gettok
        //  -> lexing -> parsing EVALUATING

        //3) Exec
    }

    return EXIT_SUCCESS;
}