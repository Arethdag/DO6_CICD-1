#ifndef S21_CAT
#define S21_CAT

#include <errno.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define TABLES 256

typedef struct {
  bool b;
  bool e;
  bool n;
  bool s;
  bool t;
  bool v;
} Flags;

void CatFile(FILE *file, Flags flags, const char *table[static TABLES]);
void charT(const char *table[static TABLES]);
void flag_e(const char *table[static TABLES]);
void flag_t(const char *table[static TABLES]);
void Cat(int argc, char *argv[], Flags flags, const char *table[static TABLES]);
Flags rflags(int argc, char *argv[]);
void flag_v(const char *table[static TABLES]);

#endif
