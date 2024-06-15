#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void populate_strings(char **strings, int length) {
  for (int i = 0; i < length; i++) {
    strings[i] = malloc(sizeof(char *));
    sprintf(strings[i], "this is the string %d", i + 1);
  }
}

void clean_heap(char **strings, int length) {
  printf("deleting from the heap\n");
  for (int i = 0; i < length; i++) {
    free(strings[i]);
  }
  free(strings);
}

int main() {
  int length = 10;

  char **strings = malloc(length * sizeof(char *));

  if (strings == NULL) {
    exit(1);
  }

  populate_strings(strings, length);

  for (int i = 0; i < length; i++) {
    printf("i:%d, value:%s\n", i, strings[i]);
  }

  clean_heap(strings, length);

  return 0;
}
