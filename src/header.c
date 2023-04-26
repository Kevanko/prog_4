#include <stdio.h>
#include <stdlib.h>

#include "header.h"

char * input(char *delim){
    char *path = (char*)malloc(MAX_PATH);
    printf("delim: ");
    scanf("%c", delim);
    printf("\npath: ");
    scanf("%s", path);
    printf("\n");
    return path;
}