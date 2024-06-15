#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    size_t id;
    char* email;
} Person;


void* createPerson(){
    return (Person*) malloc(10 * sizeof(Person));
}

void* populate(Person* people){

    for(size_t i = 0; i < 10; i++){
        people[i].id = i;
        people[i].email = "test@email.com";
    }

}


int main(){

    Person* people = createPerson();

    populate(people);

    for(size_t i = 0; i < 10; i++){
        printf("Id: %ld \t Email:%s \n",people[i].id, people[i].email);
    }

    free(people);

}



