#include "include/main.h"

#include "csv.c" 

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stdout, "Error:\t Argument 1 - Folder path required.\n");
    exit(EXIT_ERR_PATH_REQUIRED);
  }

  const char *dir_path = argv[1];

  char **file_paths = get_file_paths(dir_path);

  handle_files(file_paths);

  cleanup(file_paths);

  return 0;
}

void *get_file_paths(const char *dir_path) {
  DIR *d;
  struct dirent *dir;
  int num_files = 0;
  int array_length = 0;
  char buffer_array[1024][1024];

  d = opendir(dir_path);

  if (!d) {
    fprintf(stdout, "Error:\tDirectory not found or does not exist.\n");
    exit(EXIT_ERR_DIR_NOT_FOUND);
  }

  while ((dir = readdir(d)) != NULL) {
    char *extension = to_lower(strrchr(dir->d_name, '.'));
    if (!strcmp(extension, ".csv")) {
      strcpy(buffer_array[num_files], dir_path);
      strcat(buffer_array[num_files], "/");
      strcat(buffer_array[num_files], dir->d_name);
      num_files++;
    }
  }

  if (num_files == 0) {
    fprintf(stdout, "Error:\t No CSV file found.\n");
    exit(EXIT_ERR_STATUS_NO_FILE_FOUND);
  }

  array_length = num_files + 1;

  char **array = malloc(array_length * sizeof(char *));

  if (array == NULL) {
    exit(EXIT_ERR_STATUS_MEM_ALLOC);
  }

  // First element stores the length of the array
  array[0] = malloc(sizeof(int *));
  sprintf(array[0], "%d", num_files);

  // From buffer to heap
  for (int i = 0; i < array_length; ++i) {
    array[i + 1] = (char *)malloc(sizeof(char *));
    array[i + 1] = buffer_array[i];
  }

  return array;
}

void print_file_paths(char **file_paths) {

  int length = atoi(file_paths[0]);

  printf("Number of files found: %d\n", length);

  for (int i = 0; i < length; ++i) {
    printf("\t%s\n", file_paths[i + 1]);
  }
}

void cleanup(char **file_paths) {
  for (int i = 0; i < atoi(file_paths[0] + 1); ++i) {
    free(file_paths[i]);
  }
  free(file_paths);
}

void handle_files(char **file_paths) {
  FILE *fptr;
  char buffer[1000];

  for (int i = 0; i < atoi(file_paths[0]); ++i) {
    const char *path = file_paths[i + 1];
    fptr = fopen(path, "r");

    while (fgets(buffer, 100, fptr)) {
      printf("%s", buffer);
    }
  }
}
