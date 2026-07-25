#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p =(int *) calloc(1,sizeof(int));
    *p = 5;
    printf("%d\n",*p);
    free(p);
    // Important
    p = NULL;
    return 0;
}