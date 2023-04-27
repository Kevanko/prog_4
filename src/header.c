#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "strings.h"

char *input(char *delim) {
  char *path = (char *)malloc(MAX_PATH);
  printf("delim: ");
  scanf("%c", delim);
  printf("\npath: ");
  scanf("%s", path);
  printf("\n");
  return path;
}

/*\	разделитель подкаталогов
/	ключи командного интерпретатора
:	отделяет букву диска в Windows-путях
*	заменяющий символ (маска «любое количество любых символов»)
?	заменяющий символ (маска «один любой символ»)
«	используется для указания путей, содержащих пробелы
<	обозначение перенаправления ввода
>	обозначение перенаправления вывода
|	обозначение программного конвейера*/
int is_currect_symbol(char symbol) {
  char symbols[] = ":*?«<>|\\";
  for (size_t i = 0; i < slen(symbols); i++) {
    if (symbols[i] == symbol)
      return 1;
  }
  return 0;
}

void print_error(Error err) {
  char *err_name;
  switch (err.err) {
  case 0:
    return;
  case Error_Symbol:
    err_name = "Error unresolved character - :*?«<>|";
    break;
  case Error_Length:
    err_name = "Error max length - 260 symbols";
    break;
  case Error_String:
    err_name = "Error unexpected token";
    break;
  default:
    err_name = "Unexpected Error";
    break;
  }

  fprintf(stdout, "\n%s\n", err.str);
  for (size_t i = 0; i < err.num; i++) {
    fprintf(stdout, " ");
  }
  fprintf(stdout, "^\n%s\n\n", err_name);
}

Error check(char *path) {
  if (slen(path) > MAX_PATH)
    return (Error){slen(path), Error_Length, path};
  for (size_t i = 0; i < slen(path); i++) {
    if (is_currect_symbol(path[i]))
      return (Error){i, Error_Symbol, path};
  }
  return (Error){0, 0, NULL};
}

/*delim: +
paths:
/cygdrive/c/Windows/system32+/cygdrive/e/Distrib/msoffice.exe+/home/alex/prog/lab4.c
Выход:
new paths: C:\Windows\system32+E:\Distrib\msoffice.exe+/home/alex/prog/lab4.c*/
Error process(char *path, const char delim) {
  char *output[12];
  int count = stok(path, delim, output);
  for (int i = 0; i < count; i++) {
    if (output[i][0] != '/')
      return (Error){0, Error_String, output[i]};

    if (!replace(output[i], "/cygdrive/", "")) {
      output[i][0] = to_upper(output[i][0]);
      replace(output[i], "/", ":\\");
      replace_all(output[i], "/", "\\");
    }
  }
  path = satok(path, delim, output, count);
  return (Error){0, 0, NULL};
}

void output(char *path, char delim) {
  Error status;
  if (print_error(status = check(path)), status.err)
    return;
  if (print_error(status = process(path, delim)), status.err)
    return;
  printf("new paths: %s\n", path);
}