#include "car.h"
#include <iostream>
using namespace std;

int Car::totalCount = 0;

Car::Car(){
    ++totalCount;
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

void Car::ShowCount(){
    cout<<"Car count: "<<totalCount<<endl;
}