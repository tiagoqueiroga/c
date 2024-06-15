#include "includes/tasks.h"
#include "includes/database.h"

void create_tasks_table(database *db)
{
    // Table
    tasks_table *table = malloc(sizeof(tasks_table));

    if (table == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    table->index = 0;

    // Data
    table->data = (task**)malloc(MAX_TASKS * sizeof(task*));
    if (table->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < MAX_TASKS; i++) {
        table->data[i] = (task*)malloc(sizeof(task));
        if (table->data[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    db->tasks = table;

}

void print_tasks(database *db)
{
    task **data = db->tasks->data;
    size_t index = db->tasks->index;

    printf("total:%ld\n",index);

    for (int i = 0; i < index; i++) {
        printf("id:%ld\t title:%s\t done:%d\n",data[i]->id,data[i]->title,data[i]->done);
    } 
}

void free_tasks_table(database *db)
{
    task **data = db->tasks->data;
    size_t index = db->tasks->index;

    for (int i = 0; i < index; i++) {
        free(data[i]);
    } 

    free(data);
}

void create_task(database *db, task *new)
{
    task **data = db->tasks->data;
    
    data[db->tasks->index]->id = db->tasks->index;
    data[db->tasks->index]->done = new->done;
    strcpy(data[db->tasks->index]->title,new->title);

    db->tasks->index++;
}