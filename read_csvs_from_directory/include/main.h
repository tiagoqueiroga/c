#ifndef __MAIN__

#define MAX_FILENAME_LEN 256
#define EXIT_ERR_PATH_REQUIRED 1
#define EXIT_ERR_DIR_NOT_FOUND 2
#define EXIT_ERR_STATUS_NO_FILE_FOUND 3
#define EXIT_ERR_STATUS_MEM_ALLOC 4

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cleanup(char **file_paths);
void *get_file_paths(const char *dir_path);
void handle_files(char **file_paths);
char *to_lower(char *word);

#endif