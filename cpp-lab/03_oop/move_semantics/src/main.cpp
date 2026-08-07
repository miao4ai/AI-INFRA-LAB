#include "Integer.h"
#include <iostream>

Integer Add(int a, int b){
    return Integer(a+b);

}
Integer Add(const Integer &a, const Integer &b){
    Integer temp;
    temp.SetValue(a.GetValue()+b.GetValue());
    return temp;
}
int main(){
    //Integer a(1),b(3);
    //a.SetValue(Add(a,b).GetValue());
    //Integer c = Add(3,5);
    Integer a(1);
    Integer b{std::move(a)};
    return 0;
}