#include "turt.h"



// WRAPPERS

void Getcwd(char *buf, size_t size) {
    if (NULL == getcwd(buf, size)) {
        perror(RED"getcwd failed"RESET);
        exit(EXIT_FAILURE);
    }
}

void *Malloc(size_t size) {
    void *ptr;

    if (size == 0) {return NULL;}
    ptr = malloc(size);
    if (!ptr) {
        perror(RED"Malloc failed"RESET);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void *Realloc(void *ptr, size_t size) {
    void *new_ptr;

    if (size == 0) {return NULL;}
    new_ptr = realloc(ptr, size);
    if (!new_ptr) {
        perror(RED"Realloc failed"RESET);
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

pid_t Fork(void) {
    pid_t pid = fork();

    if (pid<0) {
        perror(RED"Fork failed"RESET);
        exit(EX_OSERR); //can't fork error
    }
    return pid;
}

void Execvp(const char *file, char *const argv[]) {
    if (!file || !argv) {
        fprintf(stderr, RED"Execvp: invalid arguments\n"RESET);
        exit(EXIT_FAILURE);
    }
    if (execvp(file, argv) == -1) {
        perror(RED"TURT_Jr failed"RESET);
        exit(EX_UNAVAILABLE); //service unavailable
    }
}

pid_t Wait(int *status) {
    pid_t result;

    if (!status) {
        fprintf(stderr, RED"Wait: status argument required\n"RESET);
        return (-1);
    }
    result = wait(status);
    if (result == -1) {perror(RED"Wait failed"RESET);}
    return result;
}

void loading() {
    const char *charging[] = {
        (YELLOW"[          ]"),
        (YELLOW"[=         ]"),
        (YELLOW"[==        ]"),
        (YELLOW"[===       ]"),
        (YELLOW"[====      ]"),
        (YELLOW"[=====     ]"),
        (YELLOW"[======    ]"),
        (YELLOW"[=======   ]"),
        (YELLOW"[========  ]"),
        (YELLOW"[========= ]"),
        (YELLOW"[==========]"RESET)
    };
    const int frames = sizeof(charging) / sizeof(charging[0]);
    p(RED"Shutting down TURT shell...\n"RESET);
    for (int i = 0; i < frames; ++i) {
        p("\r%s", charging[i]);
        fflush(stdout);
        usleep(100000/2);
    }
    p(CYAN"\nGoodbye\n"RESET);
    exit(EXIT_SUCCESS);
}
void printbanner(void) {
    p(CYAN "\n\t\t=== TURTLE SHELL INITIALIZED ===\n\n" RESET);

    p(GREEN
      "████████╗██╗   ██╗██████╗ ████████╗      ▄█████▄   ████\n"
      "╚══██╔══╝██║   ██║██╔══██╗╚══██╔══╝     ██     ██ █  O █\n"
      "   ██║   ██║   ██║██████╔╝   ██║       ██       ██ ████\n"
      "   ██║   ██║   ██║██╔══██╗   ██║       ███████████\n"
      "   ██║   ╚██████╔╝██║  ██║   ██║       ██ ██ ██ ██\n"
      "   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝       ╚╝ ╚╝ ╚╝ ╚╝\n\n" RESET);

    p(CYAN "\t\t   Tiny UNIX REPL Terminal\n\n" RESET);
}