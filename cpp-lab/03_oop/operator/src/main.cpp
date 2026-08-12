#include "integer.h"
#include <iostream>

int main(){
    Integer a(1),b(3);
    Integer c;
    c=a;
    //Integer sum = a+b;
    std::cout<<c.GetValue()<<std::endl;
    return 0;
}