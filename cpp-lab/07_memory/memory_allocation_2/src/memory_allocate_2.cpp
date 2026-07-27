#include <iostream>
using namespace std;

void New(){
    int *p = new int;
    *p = 6;
    cout<< *p <<endl;
    delete p;
    p = nullptr;
}


int main(){
    New();
}