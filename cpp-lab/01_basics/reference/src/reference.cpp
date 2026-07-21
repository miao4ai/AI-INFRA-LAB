#include <iostream>

int main(){
    using namespace std;
    int x = 10;

    int &ref = x;

    cout << "ref:" << ref <<endl;
    return 0;

}