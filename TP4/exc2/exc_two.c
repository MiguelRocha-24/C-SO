

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        exit(EXIT_FAILURE);
    }
    if (argc == 2) {
        char* w1 = strdup(argv[1]);
        char* t = w1;
        while (*w1 != '\0') {
            *w1 = tolower(*w1);
            w1++;
        }
        w1 = t;
        printf("String is \"%s\"\n", w1);
        exit(EXIT_SUCCESS);
    }
    else {
        char* w1 = strdup(argv[1]);
        char* w2 = strdup(argv[2]);
        char* fo = strstr(w2, w1);
        int i = 0;
        while (fo != NULL) {
            i++;
            w2 = fo;
            w2++;
            fo = strstr(w2, w1);
        }
        if (i == 0) {
            printf("The string %s doesn't occur in %s\n", argv[1], argv[2]);
        }
        else {
            printf("the string %s occurs %i times in %s\n", argv[1], i, argv[2]);
        }
        exit(EXIT_SUCCESS);
    }
}
