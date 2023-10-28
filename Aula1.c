#include <stdio.h>

int main(){

    int number = 99;
    int* pnumber = &number;

    int socorro = pnumber + 1;
    printf("%d\n", pnumber);
    printf("%d", socorro);

    float i;
    printf("%f", i);

    return 0;
}
