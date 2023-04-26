/*/-----------------------------/*/
/*---->     Variant: 16     <----*/
/*/-----------------------------/*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "strings.h"
#include "header.h"

int main() {
  char first[] = "Hello World";
  char second[slen(first)];

  printf("slen(123)\t%ld\n", slen("123"));
  printf("scmp(123, 123)\t%d\n", scmp("123", "123"));
  printf("scmp(132, 123)\t%d\n", scmp("132", "123"));
  printf("scmp(123, 132)\t%d\n", scmp("123", "132"));
  printf("scpy\t%s\n", scpy(second, first));
  printf("sspn\t%ld\n", sspn(second, "l oeH"));

  char * output[6];
  char string[] = "25 55 666 32 6";
  int count = stok(string, ' ', output);
  for(int i = 0; i < count; i++){
    printf(" stok\t%s\n", output[i]);
  }
  char delim;
  char* test = input(&delim);
  printf("[%c] %s\n", delim, test);

  free(test);
  return 0;
}