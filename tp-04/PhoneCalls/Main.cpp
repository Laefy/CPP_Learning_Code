#include "Person.h"
#include "Phone.h"

int main()
{
    Person paul { "Paul", 3 };
    Phone  phone { paul };
    phone.ring();

    return 0;
}
