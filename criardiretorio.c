#include <stdio.h>

int main(int argc, char **argv){
    printf("argc: %d\n", argc);
    int i;
    for (i = 0; i < argc; i++)
        printf("-> [%d] - %s\n", i, argv[i]);

    return 0;
}