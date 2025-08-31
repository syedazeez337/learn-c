// fileinfo.c - count bytes and lines of a file
// usage: ./fileinfo [file]

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *path = NULL;
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [file]\n", argv[0]);
        return 2;
    }

    if(argc == 2) {
        path = argv[1];
    } else {
        path = NULL;
    }

    // printf("Printing %s\n", path);

    FILE *fp = path ? fopen(path, "r") : stdin;
    if(!fp) {
        perror("fopen");
        return 1;
    }

    unsigned long long bytes = 0, lines = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        bytes++;
        if(c == '\n') lines++;
    }

    if(fp != stdin) fclose(fp);

    printf("bytes=%llu, lines=%llu\n", bytes, lines);
    return 0;
}