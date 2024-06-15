#include <stdio.h>
#include <stdlib.h>

// Create heap variable
void* initArray(const int size){
    return (int*) malloc(size * sizeof(int));
}

void* reallocArray(const int newSize, int*array){
    return (int*) realloc(array, newSize * sizeof(int));
}

void* setArrayValue(const int size, int *array){
    for(size_t i = 0; i < size; i++){
        array[i] = rand();
    } 
}

void print(char* msg, const int size, int* array){

    printf("Int bytes => %ld \n", sizeof(int));
    printf("myArray bytes => %ld \n", sizeof(int) * size);

    for(size_t i = 0; i < size; i++){
        printf("\t myArray[%ld] => %d \n",i,array[i]);
    }

}

int main(){
    int size = 10;
    int* myArray = initArray(size);

    srand(time(NULL));

    setArrayValue(size,myArray);

   if (myArray == NULL) {
        fprintf(stderr, "myArray not allocated");     
        exit(0);
    }


    print("Initial:",size,myArray);

    size = 20;

    myArray = reallocArray(20,myArray);

    setArrayValue(size,myArray);

    print("New sized array:",size,myArray);

// Free heap variable
    free(myArray);
}



