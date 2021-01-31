#pragma once

#include "Animal.h"
#include "Cat.h"
#include "Chicken.h"
#include "Cow.h"
#include "Dog.h"

#include <iostream>
#include <vector>

class Opera
{
public:
    Opera()
    {
        _animals.emplace_back(new Cat {});
        _animals.emplace_back(new Chicken {});
        _animals.emplace_back(new Cow {});
        _animals.emplace_back(new Dog {});
    }

    ~Opera()
    {
        for (auto* animal : _animals)
        {
            delete animal;
        }
    }

    void sing() const
    {
        for (const auto* animal : _animals)
        {
            animal->sing(' ');
        }

        std::cout << std::endl;
    }

private:
    std::vector<Animal*> _animals;
};