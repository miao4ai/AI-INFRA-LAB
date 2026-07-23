#include <iostream>


int main(){
    using namespace std;
    int arr[]{1,2,3,4,5};
    for (int i = 0; i<5; i++){
        cout <<arr[i]<< " ";
    }
    cout << endl;
    for (auto &x : arr){
        x = 3;
        cout << x << " ";
    }
    
    cout<<endl;

    auto begin= std::begin(arr);
    auto end = std::end(arr);

    for (;begin!=end;++begin){
        auto v = *begin;
        cout << v << " ";
    }

    cout <<endl;

}