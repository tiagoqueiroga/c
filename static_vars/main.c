#include <stdio.h>

void call(){
    static int static_var = 1;
    int non_static_var = 0;

    printf("static var:%d\n",static_var);
    printf("non static var:%d\n",non_static_var);

    static_var++;
    non_static_var++;
}

int main(){
    call(); 
    call(); 
    call(); 
    call(); 
    return 0;
}

