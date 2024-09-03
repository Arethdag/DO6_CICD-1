#include "grep_main.h"

int main(int argc, char **argv) {
  if (argc > 1) {
    char *temp = NULL;
    Flags flags = {0};

    int c = parseflags(argc, argv, &flags, &temp);
    while (c < argc) {
      FILE *file = fopen(argv[c], "r");
      if (file != NULL) {
        workFiles(file, &flags, temp, argv[c]);
        fclose(file);
      } else if (flags.s == 0) {
        fprintf(stderr, "s21_grep: %s: No such file or directory\n", argv[c]);
      }
      c++;
    }

    if (temp != NULL) free(temp);
  }
  return 0;
}
