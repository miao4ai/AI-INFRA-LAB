#include "car.h"
#include <iostream>
using namespace std;

Car::Car(){
    fuel = 0;
    speed = 0;
    passengers = 0;
    cout<<"Constructor!"<<endl;
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