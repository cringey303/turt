#ifndef TURT_H
# define TURT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
** ANSI Colors for terminal output
*/
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

#define p(...) printf(__VA_ARGS__)
#define DEL " \t\n\v\f\r"
#define TURT_Jr 0

typedef struct s_builtin {
    const char *builtin_name;
    int (*foo)(char **);
}   t_builtin;

int turt_env(char **);
int turt_exit(char **);
void loading();

//WRAPPERS
void Getcwd(char *buf, size_t size);
void *Malloc(size_t size);
void *Realloc(void *ptr, size_t size);
pid_t Fork(void);
void Execvp(const char *file, char *const argv[]);
pid_t Wait(int *status);

void printbanner(void);
#endif