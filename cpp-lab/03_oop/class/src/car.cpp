#include "car.h"
#include <iostream>
using namespace std;

Car::Car(){
 
}

Car::~Car(){
    cout<<"Destructor!"<<endl;
}

void Car::FillFuel(float amount){
    fuel += amount;
}

void Car::Accelerate(){
    speed++;
    fuel-=0.5;
}

void Car::Dashboard(){
    cout<<"Speed: "<<speed<<endl;
    cout<<"Fuel: "<<fuel<<endl;
}