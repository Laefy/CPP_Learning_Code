#include "Car.h"
#include "FlyingCar.h"
#include "Scooter.h"
#include "Vehicle.h"

#include <iostream>

int main()
{
    Driver car_driver;
    car_driver.pass_car_licence_exam();
    car_driver.pass_air_licence_exam();

    FlyingCar  car { car_driver, 60u };
    const auto distance_in_car = car.drive();
    std::cout << distance_in_car << " km in a car." << std::endl;

    Driver     mini_gangster;
    Scooter    scooter { mini_gangster, 180u };
    const auto distance_in_scooter = scooter.drive();
    std::cout << distance_in_scooter << " km with a scooter." << std::endl;

    // Vehicle vehicle { car_driver };

    return 0;
}