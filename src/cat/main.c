#include "cat_main.h"

int main(int argc, char *argv[]) {
  Flags flags = rflags(argc, argv);
  const char *table[TABLES];
  charT(table);
  if (flags.e) {
    flag_e(table);
  }
  if (flags.t) {
    flag_t(table);
  }
  if (flags.v) {
    flag_v(table);
  }
  Cat(argc, argv, flags, table);

  return 0;
}
