#include <stdio.h>

int main(){

    float step = 20;
    float max = 300;
    float cel = 0;
    float fah = 0;

    for(cel = 0; cel <= 120; cel+=1 )
    {
        fah = (cel * 1.8) + 32;
        printf("%3.f°C \t %3.f°F\n",cel,fah);
    }

    return 0;
}