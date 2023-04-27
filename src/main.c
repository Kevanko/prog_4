/*/-----------------------------/*/
/*---->     Variant: 16     <----*/
/*/-----------------------------/*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "strings.h"

int main() {
  char test1[] = "/cygdrive/c/Windows/system32+home/Andrey";
  char test2[] = "/cygdrive/c/Windows/system323232323232/4343253255552343242342367/532723456235r43734533332632/6346346346r634tgre543gfdt43543grdg34534/5345346y75rghftgr654634gfdt643/634yghfy346r6y734/fyhg4265t4yrt6t54u7yrt654yghfy45/cygdrive/c/Windows/system323232323232/4343253255552343242342367/532723456235r43734533332632/6346346346r634tgre543gfdt43543grdg34534/5345346y75rghftgr654634gfdt643/634yghfy346r6y734/fyhg4265t4yrt6t54u7yrt654yghfy45";
  char test3[] = "/cygdr:ive/c/Windows/system32";

  printf("----TEST----\n");
  output(test1, '+');
  output(test2, '+');
  output(test3, '+');
  printf("----TEST----\n");
  
  char delim;
  char *test = input(&delim);
  output(test, delim);

  free(test);
  return 0;
}