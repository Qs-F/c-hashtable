#include <stdio.h>
#include "ht.h"

int main(void) {
  table_t table = init();

  printf("%d\n", hash("key1"));
  printf("%d\n", hash("key2"));
  // printf("%d\n", hash("key3"));
  // printf("%d\n", hash("key4"));
  // printf("%d\n", hash("key5"));
  // printf("%d\n", hash("key6"));
  // printf("%d\n", hash("key7"));
  // printf("%d\n", hash("key8"));
  printf("%d\n", hash("key9"));
  // printf("%d\n", hash("key10"));
  // printf("%d\n", hash("key11"));
  // printf("%d\n", hash("key12"));
  // printf("%d\n", hash("key13"));
  // printf("%d\n", hash("key14"));
  // printf("%d\n", hash("key15"));
  //
  add(table, "key1", "test1");
  add(table, "key2", "test2");
  add(table, "key9", "test9");

  char s[256];
  printf("%d\n", search(table, "key1", s));
  printf("%d\n", search(table, "key2", s));
  printf("%d\n", search(table, "key9", s));
  printf("%d\n", search(table, "key3", s));
  return 0;
}
