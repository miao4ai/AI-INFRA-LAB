#include <iostream>

void Print(int count, char ch){
    using namespace std;
    for (int i=0; i<count; ++i){
        cout <<ch;

    }
    cout<<endl;
}


int main(){
    Print(5,'#');
    void(*pfn)(int,char)=Print;
    (*pfn)(8,'@');
    pfn(5,'a');

    return 0;
}