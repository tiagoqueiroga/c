#ifndef H_TASK_
#define H_TASK_

#define MAX_TASKS 100

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t id;
    char title[100];
    bool done;
} task;

typedef struct {
    task **data;
    size_t index;
} tasks_table;

#include "database.h"

void create_tasks_table(database *db);

void print_tasks(database *db);

void free_tasks_table(database *db);

void create_task(database *db, task *new);

#endif