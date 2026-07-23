#include <iostream>
#include <array>

void array(){
    std::array<int,5> arr{1,2,3,4,5};
    auto itr = arr.begin();
    for (auto x:arr){
        std::cout<<x<<std::endl;
    }

}

int main(){
    array();
    return 0;

}