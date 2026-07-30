#pragma once 
class Car{

private:
    float fuel;
    float speed;
    int passengers;


public:
    Car();
    void FillFuel(float amount);
    void Accelerate();
    void Brake();
    void AddPassengers(int count);
    void Dashboard();

};