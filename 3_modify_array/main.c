#include <stdio.h>

void arraySetter(const int value, const int size, int *array){
    for (int i = 0; i < size; i++)
    {
        array[i] = value;
    }
}

void printArray(int *array, const int size){
    for (int i = 0; i < size; i++)
    {
        printf("array[%d] => %d \n",i,array[i]);
    }
}


int main(){
    int array[] = {0,1,2,3,4};

    int size = sizeof(array) / sizeof(int);

    arraySetter(5,size,array);

    printArray(array,size);
    
}


void sayHello(){
    printf("sayHello");
}


