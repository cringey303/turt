#include "turt.h"
#include <stdio.h>
#include <string.h>

//av

char **turt_tokenize_line(char *line){
    unsigned int position = 0;
    size_t bufsize = BUFSIZ;
    char **tokens = Malloc(bufsize * sizeof *tokens);

    for (char *token = strtok(line, DEL); token; token = strtok(NULL, DEL)) {
        tokens[position++] = token;
        if (position >= bufsize) {
            bufsize *= 2;
            tokens = Realloc(tokens, bufsize * sizeof(*tokens));
        }
    }
    tokens[position] = NULL; //sentinel value
    return tokens;
}


char *turt_read_line(void) {
    char *buf;
    size_t bufsize;
    char cwd[BUFSIZ]; //current working directory
    buf = NULL;

    Getcwd(cwd, sizeof(cwd));
    p(CYAN"[%s] "RESET GREEN"turt$> "RESET, cwd);

    if (getline(&buf, &bufsize, stdin) == -1) {
        free(buf);
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
    char **args;

    printbanner();
    //REPL
    //Read-Eval-Print Loop for Turtle graphics commands
    while ((line = turt_read_line())) {
        //1) get line
        //2) get tokens gettok
        args = turt_tokenize_line(line);
        for (int i = 0; args[i]; ++i) {
            p("%s\n", args[i]);
        }
        //  -> lexing -> parsing EVALUATING

        //3) Exec
        turt_exec(args); //TODO
        
        //4) Free line
        free(line);
        free(args);
    }

    return EXIT_SUCCESS;
}