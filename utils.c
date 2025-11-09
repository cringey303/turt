#include "turt.h"

// WRAPPERS

void Getcwd(char *buf, size_t size) {
    if (NULL == getcwd(buf, size)) {
        perror(RED"getcwd failed"RESET);
        exit(EXIT_FAILURE);
    }
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
}