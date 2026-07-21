#include <iostream>
/*
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}*/

/*
Make swap by using reference instead of pointers
*/
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    using namespace std;
    int a = 10;
    int b = 5;
    cout<< "a: "<< a <<" b: "<<b<<"\n";
    //swap(&a,&b);
    swap(a,b);
    cout<< "a: "<< a <<" b: "<<b<<"\n";

}