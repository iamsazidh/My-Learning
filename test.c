#include <stdio.h>
#include <stdlib.h>


int main(){
    int *p;
    printf("%p\n", p);
    p = (int *)malloc(sizeof(int));
    int k;
    k = *p;
    *p = 5;
    printf("%p\n", p);
    printf("%d", *p);

    return 0;
}