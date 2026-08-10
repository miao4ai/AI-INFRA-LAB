#include "integer.h"
#include <iostream>

int main(){
    Integer a(1),b(3);
    Integer sum = a+b;
    std::cout<<sum.GetValue()<<std::endl;
    return 0;
}