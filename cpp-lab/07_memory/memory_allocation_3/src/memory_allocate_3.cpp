#include <iostream>
using namespace std;

void NewArray(){
    int *p = new int[5]{1,2,3,4,5};
    for (int i = 0;i<5;i++){
        cout<< p[i] <<endl;
    }
    delete []p;
}

void Strings(){
    char *p = new char[4];
    strcpy(p,"C++");
    cout<<p<<endl;
    delete []p;
}

void TwoD(){
    int *p1 = new int[3];
    int *p2 = new int[3];
    
    int **pData = new int* [2];
    pData[0] = p1;
    pData[1] = p2;

    pData[0][1]=2; 
    cout<< pData[0][1]<<endl;

    delete []p1;
    delete []p2;
    delete []pData;

}

int main(){
    NewArray();
    Strings();
    TwoD();
}