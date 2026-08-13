#include "integer.h"
#include <iostream>
#include <memory>

void Process(std::unique_ptr<Integer> ptr){
    std::cout<<ptr->GetValue()<<std::endl;
}


void CreateInteger(){
    std::unique_ptr<Integer> p(new Integer);
    (*p).SetValue(3);
    Process(std::move(p));
}

int main(){
    CreateInteger();
    return 0;
}