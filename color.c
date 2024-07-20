#include <stdio.h>

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int main() {
    printf(RED "This text is red.\n" RESET);
    printf(GREEN "This text is green.\n" RESET);
    printf(YELLOW "This text is yellow.\n" RESET);
    printf(BLUE "This text is blue.\n" RESET);
    printf(MAGENTA "This text is magenta.\n" RESET);
    printf(CYAN "This text is cyan.\n" RESET);
    printf("This text is the default color.\n");
    
    return 0;
}
