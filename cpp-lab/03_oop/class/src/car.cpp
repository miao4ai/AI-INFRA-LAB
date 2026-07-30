#include "car.h"

Car::Car(){
    fuel = 0;
    speed = 0;
    passengers = 0;
}

void Car::FillFuel(float amount){
    fuel = amount;
}

void Car::Accelerate(){
    speed++;
    fuel-=0.5;
}