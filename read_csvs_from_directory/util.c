#include "include/util.h"

char *to_lower(char *word) {
  for (size_t i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  return word;
}