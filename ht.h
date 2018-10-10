#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 8
#define KEY_SIZE 128
#define VALUE_SIZE 1024

typedef struct elem_t {
  char *key;
  char *value;
  struct elem_t *NEXT;
} elem_t;

typedef elem_t** table_t;

table_t init() {
  table_t table;
  table = (table_t)malloc(sizeof(elem_t *) * TABLE_SIZE);
  if (!table) {
    fprintf(stderr, "Cannot allocate memory\n");
    return NULL;
  }
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i] = NULL;
  }
  return table;
}

int hash(char *v) {
  int buf = 0;
  while (*v) {
    buf += *v++;
  }
  return buf % TABLE_SIZE;
}

bool search(table_t table, char *key, char *value) {
  int h = hash(key);
  if (table[h] == NULL)
    return false;
  if ((table[h] -> key) == NULL)
    return false;
  elem_t *e = table[h];
  int c = strncmp(table[h] -> key, key, KEY_SIZE);
  while (e != NULL &&  e -> key != NULL && c > 0) {
    e = e -> NEXT;
  }

  if (e == NULL || e -> key == NULL || c != 0) {
    return false;
  } else {
    value = e -> value;
    return true;
  }
  return false;
}

bool add(table_t table, char *key, char *value) {
  if (search(table, key, value)) {
    fprintf(stderr, "key already exists\n");
    return true;
  }

  elem_t *e = (elem_t *)malloc(sizeof(elem_t));
  if (e == NULL) {
    fprintf(stderr, "cannot allocate memory for element\n");
    return false;
  }

  e -> key = (char *)malloc(sizeof(char) * KEY_SIZE);
  strncpy((e -> key), key, KEY_SIZE);
  e -> value = (char *)malloc(sizeof(char) * VALUE_SIZE);
  strncpy((e -> value), value, VALUE_SIZE);

  int h = hash(key);
  e -> NEXT = table[h];
  table[h] = e;

  return true;
}
