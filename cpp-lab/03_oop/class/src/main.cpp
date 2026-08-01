#include "car.h"

int main(){
    Car car;
    car.FillFuel(6);
    car.Accelerate();
    car.Accelerate(); 
    car.Dashboard();
    Car::ShowCount();
    return 0;
}