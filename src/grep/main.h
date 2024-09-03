#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 8000

typedef struct {
  int e, i, v, c, l, n, h, s, f, o;
  int files;
  char str[BUFF];
  char str_o[BUFF];
  char filename[BUFF];
  char str_reg[BUFF];
} flags;

void check_flag(int argc, char *argv[], flags *flagi);
void output(char *argv[], flags *flagi);