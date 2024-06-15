#include "tasks.c"
#include "database.c"

int main()
{

    database *db = init_database();

    create_tasks_table(db);

    task t1 = { .id = 0, .title = "learn c", .done = false};
    task t2 = { .id = 0, .title = "learn js", .done = true};
    task t3 = { .id = 0, .title = "learn english", .done = false};

    create_task(db,&t1);
    create_task(db,&t2);
    create_task(db,&t3);

    print_tasks(db);

    // Free
    free_tasks_table(db);

    return 0;
}