#ifndef S21_GREP
#define S21_GREP

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int Filecount;
  int LineNum;
  int MatchCount;
} Flags;

int parseflags(int argc, char **argv, Flags *flags, char **pattern);
void workProcess(char *str, Flags *Flags, char *pattern, char *name);
void workFiles(FILE *file, Flags *flags, char *pattern, char *way);
void flag_f(Flags *flags, char **pattern, char *optarg);
void flag_e(Flags *flags, char **pattern, char *optarg);
void of_flags(regex_t my_regex, char *str, Flags flags);
void ProcessSup(Flags *flags, char *way);
void *strings_realloc(void *str, int size);
int Patterns(char **str, char *optarg);
void Flags_Work(Flags *flags, int argc);
void addPattern(char **str, char *optarg);

#endif
