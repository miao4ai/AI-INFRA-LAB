#include <iostream>

int Add(int x,int y){
    return x+y;
}


int main(){
    int &&r1 = 10;
    int &&r2 = Add(3,2);
    return 0;
}