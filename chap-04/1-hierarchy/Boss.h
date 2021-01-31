#pragma once

#include "Rank.h"

#include <string>
#include <string_view>

class Staff;
class Intern;

class Boss
{
public:
    Boss(std::string_view name, std::string_view surname, unsigned int salary, bool is_nice);

    const std::string& get_name() const { return _name; }
    const std::string& get_surname() const { return _surname; }

    unsigned int get_salary() const { return _salary; }
    void         increase_salary(unsigned int raise);

    Rank get_rank() const { return Rank::TopManagement; }
    
    void assign_task(Staff& staff) const;
    void ask_coffee(Intern& intern) const;

private:
    const std::string _name;
    const std::string _surname;
    unsigned int      _salary;
    bool              _is_nice;
};
