#pragma once

#include "Employee.h"

#include <string>
#include <string_view>

class Staff;
class Intern;

class Boss : public Employee
{
public:
    Boss(std::string_view name, std::string_view surname, unsigned int salary, bool is_nice);

    void assign_task(Staff& staff) const;
    void ask_coffee(Intern& intern) const;

private:
    bool _is_nice;
};
