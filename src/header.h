#pragma once
#define MAX_PATH 260

enum errors{
    Error_Length = 1,
    Error_Symbol,
    Error_String,
};

typedef struct Error{
    size_t num;
    int err;
    char * str;
} Error;

char * input(char *delim);
void print_error(Error err);
Error check(char* path);
Error process(char *path, const char delim);
void output(char * path, char delim);
