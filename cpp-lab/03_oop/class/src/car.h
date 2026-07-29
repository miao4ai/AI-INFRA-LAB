#pragma once 
class Car{

private:
    float fuel;
    float speed;
    int passengers;


public:
    void FillFuel(float amount);
    void Accelerate();
    void Brake();
    void AddPassengers(int count);
    void Dashboard();

};