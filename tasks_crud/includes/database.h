#ifndef H_DB_
#define H_DB_

#include "tasks.h"

typedef struct
{
    tasks_table *tasks;
} database;

database *init_database();

#endif