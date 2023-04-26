#pragma once

#include <stdint.h>
#include <stdio.h>

size_t slen(const char * str);
int scmp(char * first, char * second);
char *scpy(char *toHere, char *fromHere);
size_t sspn(char *s, const char *accept);
int stok(char *s, const char symbol, char *output[]);
char * satok(const char symbol, char *input[], int count);