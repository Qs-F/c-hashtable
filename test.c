#include <stdio.h>
#include "ht.h"

int main(void) {
  table_t table = init();

  add(table, "key", "test");
  add(table, "key2", "test2");

  char s[256];
  printf("%d\n", search(table, "key", s));
  printf("%d\n", search(table, "key2", s));
  printf("%d\n", search(table, "key3", s));
  return 0;
}
