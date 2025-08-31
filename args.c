#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);

    
    for(int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
        printf("argv[%d] first char = %c\n", i, *argv[i]);
    }
    

    // printf("%c\n", argv[1][4]);


    return 0;
}