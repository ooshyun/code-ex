#include <iostream>
#include <stdio.h>

int main(int argc, char** argv) {
    printf("You have entered %d arguments:\n", argc);
 
    for (int i = 0; i < argc; i++) {
        printf("%d: %s\n", i, argv[i]);
    }

    printf("-------\n");

    if (strcmp(argv[1], "false") == 0) {
        printf("error because of false argu");
        printf("%s\n", argv[100]);
    } else {
        printf("true\n");
    }

    printf("Success!\n-------\n");
    return 0;
}