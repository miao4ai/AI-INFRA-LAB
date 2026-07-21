#include <iostream>

int main(){
    using namespace std;
    int x = 0;
    cout << &x <<endl;
    void *ptr = nullptr;
    cout << ptr << endl;
    return 0;
}