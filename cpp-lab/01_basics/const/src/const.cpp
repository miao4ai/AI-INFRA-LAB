#include <iostream>

void Print(const int *ptr){
    using namespace std;
    cout << *ptr <<endl;
    //*ptr = 700;
}

int main(){
    using namespace std;

    const int CHUNK_SIZE = 512;
    
    int x = 10;
    int* const ptr =&x;
    //const int *const ptr = &CHUNK_SIZE;

    //int x = 10;
    Print (&x);
    *ptr = 5;

    cout<<*ptr<<endl;
    
    const int* pt1 = &CHUNK_SIZE;
    pt1 = &x;
    cout <<*pt1<<endl;
}