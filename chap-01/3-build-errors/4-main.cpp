#include "4-car.hpp"
#include "4-driver.hpp"

int main()
{
    Car car { "golf" };

    Driver driver;
    driver.drive(car);

    return 0;
}
