#pragma once

#include <iostream>

class Driver
{
};

class Vehicle
{
public:
    Vehicle(const Driver& driver)
        : _driver { driver }
    {}

    virtual ~Vehicle() {}

    virtual unsigned int drive() const
    {
        std::cerr << "Not implemented" << std::endl;
        return 0u;
    }

private:
    const Driver& _driver;
};
