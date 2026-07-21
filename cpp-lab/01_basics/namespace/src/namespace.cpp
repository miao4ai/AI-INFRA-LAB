#include <iostream>
namespace avg{
    float calculator(float a, float b){
        return (a+b)/2;
    }
}


namespace basic {
    float calculator(float a, float b){
        return a+b;
    }
}

int main(){
    using namespace avg;
    using namespace std;
    float c = calculator(1.0f,2.0f);
    cout << "Average is: "<<c<<endl;
    float d = basic::calculator(1.0,2.0f);
    cout << "Sum is: "<<d<<endl;
}