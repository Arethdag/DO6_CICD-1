#include "grep_main.h"

void workFiles(FILE *file, Flags *flags, char *pattern, char *way) {
  for (char ch = '0'; (ch = getc(file)) != EOF;) {
    char *line = calloc(256, sizeof(char));
    flags->LineNum += 1;
    int length = 0;

    for (line[length] = '\0'; ch != EOF && ch != '\n'; ch = getc(file)) {
      line[length] = ch;
      line[length += 1] = '\0';
      if (length % 255 == 0) {
        line = strings_realloc(line, length + 256);
      }
    }

    workProcess(line, flags, pattern, way);
    free(line);
  }
  ProcessSup(flags, way);
}

int parseflags(int argc, char **argv, Flags *flags, char **pattern) {
  int option;
  while ((option = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (option) {
      case 'i':
        flags->i = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      case 'c':
        flags->c = 1;
        break;
      case 'l':
        flags->l = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 'h':
        flags->h = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'o':
        flags->o = 1;
        break;
      case 'e':
        flag_e(flags, pattern, optarg);
        break;
      case 'f':
        flag_f(flags, pattern, optarg);
        break;
    }
  }

  if ((flags->e || flags->f) == 0) {
    Patterns(pattern, argv[optind]);
    optind += 1;
  }
  flags->MatchCount = 0;
  Flags_Work(flags, argc);
  return optind;
}

void flag_f(Flags *flags, char **pattern, char *optarg) {
  FILE *file = fopen(optarg, "r");
  if (file != NULL) {
    for (char ch = '0'; (ch = getc(file)) != EOF;) {
      int length = 0;
      char *line = calloc(256, sizeof(char));

      for (line[length] = '\0'; ch != EOF && ch != '\n'; ch = getc(file)) {
        line[length] = ch;
        line[length += 1] = '\0';
        if (length % 255 == 0)
          line = (char *)strings_realloc(line, length + 256);
      }

      if (!(flags->e || flags->f))
        flags->f = Patterns(pattern, line);
      else
        addPattern(pattern, line);
      free(line);
    }
    fclose(file);
  } else if (flags->s == 0) {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", optarg);
  }
}

void flag_e(Flags *flags, char **pattern, char *optarg) {
  if (!(flags->e || flags->f))
    flags->e = Patterns(pattern, optarg);
  else
    addPattern(pattern, optarg);
}

void ProcessSup(Flags *flags, char *way) {
  static int filePrinted = 0;

  // Проверяем, установлен ли флаг -c.
  if (flags->c) {
    if (flags->Filecount > 1) printf("%s:", way);
    printf("%i\n", flags->MatchCount);
  }
  // Проверяем, установлен ли флаг -l, есть ли совпадения и не превышено ли
  // максимальное количество выводимых файлов.
  else if (flags->l && flags->MatchCount > 0 && filePrinted < 2) {
    printf("%s\n", way);
    filePrinted++;
  }
}

void workProcess(char *line, Flags *flags, char *pattern, char *way) {
  regex_t regex;
  if (regcomp(&regex, pattern, flags->i ? REG_ICASE : REG_EXTENDED) == 0) {
    if (regexec(&regex, line, 0, NULL, 0) == flags->v) {
      flags->MatchCount += 1;
      if ((flags->c || flags->l) == 0) {
        if (flags->Filecount > 1 && !(flags->h)) printf("%s:", way);
        if (flags->n) printf("%i:", flags->LineNum);
        if (!flags->o)
          printf("%s\n", line);
        else
          of_flags(regex, line, *flags);
      }
    }
    regfree(&regex);
  }
}

void of_flags(regex_t regex, char *line, Flags flags) {
  while (regexec(&regex, line, 0, NULL, 0) == flags.v) {
    char *aux = (char *)calloc(strlen(line) + 1, sizeof(char));
    strcpy(aux, line);
    while (regexec(&regex, aux, 0, NULL, 0) == flags.v) {
      aux[strlen(aux) - 1] = 0;
    }
    aux[strlen(aux)] = line[strlen(aux)];
    int start = 0;
    while (regexec(&regex, aux, 0, NULL, 0) == flags.v && strlen(aux) > 0) {
      start++;
      int j = 0;
      while (aux[j] != 0) {
        aux[j] = aux[j + 1];
        j++;
      }
    }
    start--;
    int i = strlen(aux);
    while (i != 0) {
      aux[i] = aux[i - 1];
      i--;
    }
    aux[0] = line[start];
    printf("%s\n", aux);
    free(aux);
    i = start + 1;
    while (line[i] != 0) {
      line[i - start - 1] = line[i];
      i++;
    }
    line[i - start - 1] = 0;
  }
}

void Flags_Work(Flags *flags, int argc) {
  if (flags->o && (flags->l || flags->v || flags->c)) flags->o = 0;
  flags->Filecount = argc - optind;
}

int Patterns(char **str, char *optarg) {
  *str = calloc(strlen(optarg) + 1, sizeof(char));
  if (*str) strcpy(*str, optarg);
  return str ? 1 : 0;
}

void addPattern(char **str, char *optarg) {
  *str = strings_realloc(*str, strlen(*str) + strlen(optarg) + 2);
  if (*str) strcat(strcat(*str, "|"), optarg);
}

void *strings_realloc(void *str, int size) {
  char *aux = realloc(str, size);
  return aux;
}
