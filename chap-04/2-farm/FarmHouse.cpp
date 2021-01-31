#include "Animal.h"
#include "Cat.h"
#include "Chicken.h"
#include "Cow.h"
#include "Dog.h"

void sing_a_lot(const Animal& animal, unsigned int times)
{
    while (times-- > 0)
    {
        animal.sing();
    }
}

int main()
{
    Cat cat;
    Chicken chicken;
    Dog dog;
    Cow cow;

    sing_a_lot(cat, 2u);
    sing_a_lot(dog, 1u);
    sing_a_lot(cow, 3u);
    sing_a_lot(dog, 1u);
    sing_a_lot(chicken, 2u);

    return 0;
}

