#include <stdint.h>
#include <stdio.h>

size_t slen(char *str) {
  size_t size = 0;
  while (str[size] != '\0') {
    size++;
  }
  return size;
}

int scmp(char *first, char *second) {
  while (*first != '\0' || *second != '\0') {
    if (*first > *second)
      return 1;
    if (*first < *second)
      return -1;
    first++;
    second++;
  }
  return 0;
}

char *scpy(char *toHere, char *fromHere) {
  for (size_t i = 0; i <= slen(fromHere); i++) {
    toHere[i] = fromHere[i];
  }
  return toHere;
}

int is_symbol(char s1, const char *accept) {
  while (*accept != '\0') {
    if (s1 == *accept)
      return 1;
    accept++;
  }
  return 0;
}

size_t sspn(char *s, const char *accept) {
  size_t size = 0;
  size_t counter = 0;
  while (*s != '\0') {
    if (is_symbol(*s, accept))
      counter++;
    else
      counter = 0;
    size = size > counter ? size : counter;
    s++;
  }
  return size;
}

int stok(char *s, const char symbol, char *output[]) {
  int count = 0;
  output[count++] = s;
  size_t size = slen(s);
  for (size_t i = 0; i < size; i++) {
    if (s[i] == symbol) {
      s[i] = '\0';
      output[count++] = &s[i + 1];
    }
  }
  return count;
}

char *satok(char *result, const char symbol, char *input[], int count) {
  return result;
}