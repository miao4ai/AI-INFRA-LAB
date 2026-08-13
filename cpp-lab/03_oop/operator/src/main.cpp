#include "integer.h"
#include <iostream>

Integer operator +(int x, const Integer &y){
    Integer temp;
    temp.SetValue(x+y.GetValue());
    return temp;
}

std::ostream & operator <<(std::ostream &out, const Integer &b){
    out << b.GetValue();
    return out;
}
int main(){
    //Integer a(1),b(3);
    //Integer c;
    //c=a;
    Integer a(1);
    Integer sum1 = a + 5;
    //Integer sum = a+b;
    std::cout<<sum1.GetValue()<<std::endl;
    return 0;
}