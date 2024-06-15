#include <stdio.h>
#include <stdlib.h>

// Create heap variable
void* initArray(const int size){
    return (int*) malloc(size * sizeof(int));
}


int main(){
    const int size = 100;
    int* myArray = initArray(size);

   if (myArray == NULL) {
        fprintf(stderr, "myArray not allocated");     
        exit(0);
    }

    for(size_t i = 0; i < size; i++){
        printf("myArray[%ld] => %d \n",i,myArray[i]);
    }

    printf("Int bytes => %ld \n", sizeof(int) * size);

    printf("myArray length => %ld \n", sizeof(int) * size);

// Free heap variable
    free(myArray);
}



