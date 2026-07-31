#pragma once 
class Car{

private:
    float fuel {0};
    float speed {0};
    int passengers {0};


public:
    Car();
    ~Car();
    void FillFuel(float amount);
    void Accelerate();
    void Brake();
    void AddPassengers(int count);
    void Dashboard();

};