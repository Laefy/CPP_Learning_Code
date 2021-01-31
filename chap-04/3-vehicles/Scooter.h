#pragma once

#include "Vehicle.h"

#include <algorithm>
#include <iostream>

class Scooter : public Vehicle
{
public:
    Scooter(const Driver& driver, unsigned int speed)
        : Vehicle { driver }
        , _speed { std::min(speed, 50u) }
    {}

    unsigned int drive() const override
    {
        std::cout << "PufPufPufPufPuf!" << std::endl;
        return _speed;
    }

private:
    unsigned int _speed = 0;
};
