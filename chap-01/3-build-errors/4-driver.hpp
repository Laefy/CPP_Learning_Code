#include "4-car.hpp"

#include <iostream>

struct Driver
{
    void drive(Car car)
    {
        std::cout << "I'm driving a " << car.brand << std::endl; 
    }
};