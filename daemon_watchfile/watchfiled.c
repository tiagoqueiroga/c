#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#include <unistd.h>

#define EXIT_SUCCESS 0
#define EXIT_ERR_TOO_FEW_ARGS 1
#define EXIT_ERR_INIT_INOTIFY 2
#define EXIT_ERR_ADD_WATCH 3
#define EXIT_ERR_BASE_PATH_NULL 4
#define EXIT_ERR_READ_INOTIFY 5

int IeventQueue = -1;
int IeventStatus = -1;

const struct inotify_event *watchEvent;

void signalHandler(int signal) {
  int closeStatus = -1;

  printf("Signal received, cleaning up...\n");

  closeStatus = inotify_rm_watch(IeventQueue, IeventStatus);

  if (closeStatus == -1) {
    fprintf(stderr, "Error removing from watch queue\n");
  }

  exit(EXIT_SUCCESS);
}

void handleEvents() {}

int main(int argc, char **argv) {
  char *basePath = NULL;
  char *token = NULL;

  char buffer[4096];
  int readLength;

  char *notificationMessage = NULL;

  const uint32_t watchMask = IN_CREATE | IN_DELETE | IN_ACCESS |
                             IN_CLOSE_WRITE | IN_MODIFY | IN_MOVE_SELF;

  if (argc < 2) {
    fprintf(stderr, "USAGE: daemon_watchfile PATH\n");
    exit(EXIT_ERR_TOO_FEW_ARGS);
  }

  basePath = (char *)malloc(sizeof(char) * (strlen(argv[1]) + 1));

  strcpy(basePath, argv[1]);

  token = strtok(basePath, "/");

  while (token != NULL) {
    basePath = token;
    token = strtok(NULL, "/");
  }

  if (basePath == NULL) {
    fprintf(stdout, "Error initializing inotify initialize\n");
    exit(EXIT_ERR_BASE_PATH_NULL);
  }

  IeventQueue = inotify_init();

  if (IeventQueue == -1) {
    fprintf(stdout, "Error getting basePath\n");
    exit(EXIT_ERR_INIT_INOTIFY);
  }

  IeventStatus = inotify_add_watch(IeventQueue, argv[1], watchMask);
  if (IeventStatus == -1) {
    fprintf(stdout, "Error adding file to watch instance\n");
    exit(EXIT_ERR_ADD_WATCH);
  }

  signal(SIGABRT, signalHandler);
  signal(SIGINT, signalHandler);
  signal(SIGTERM, signalHandler);

  while (true) {
    readLength = read(IeventQueue, buffer, sizeof(buffer));

    if (readLength == -1) {
      fprintf(stdout, "Error reading from inotify instance\n");
      exit(EXIT_ERR_READ_INOTIFY);
    }

    for (char *bufferPointer = buffer; bufferPointer < buffer + readLength;
         bufferPointer += sizeof(struct inotify_event) + watchEvent->len) {
      notificationMessage = NULL;
      watchEvent = (const struct inotify_event *)bufferPointer;

      if (watchEvent->mask & IN_MODIFY) {
        notificationMessage = "File modified";
      }

      if (watchEvent->mask & IN_CREATE) {
        notificationMessage = "File has been created";
      }

      if (notificationMessage == NULL) {
        continue;
      }

      printf("-----------------------------------------\n");
      printf("%s => %s\n", argv[1], notificationMessage);
      printf("Cookie:%d\n", watchEvent->cookie);
      printf("Wd:%d\n", watchEvent->wd);
      printf("Name:%s\n", watchEvent->name);
      printf("Mask:%d\n", watchEvent->mask);
    }
  }

  free(basePath);
}
