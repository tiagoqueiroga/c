#include "includes/database.h"

database * init_database()
{
    database *db = malloc(sizeof(database));

    if(db == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

}

