#include <stdio.h>
#include <stdlib.h>

/* If we are compiling on Windows: */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* otherwise include the editline headers */
#else
#include <editline/readline.h>
#include <histedit.h>
#endif

int main(int argc, char** argv) {
    /* Print version and exit info */
    puts("Niblisp Version 0.1");
    puts("Wow!");
    puts("Press Ctrl+c to Exit\n");

    /* In a never ending loop... */
    while (1) {
        /* ... output our prompt and get input ... */
        char* input = readline("nibLISP> ");

        /* ... add it to history ... */
        add_history(input);

        /* ... and echo it back to the user. */
        printf("You can't get ye %s\n", input);

        /* Finally, free retrieved input. */
        free(input);
    }
    
    return 0;
}
