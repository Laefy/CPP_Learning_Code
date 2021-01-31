#pragma once

#include "Rank.h"

#include <string>
#include <string_view>

class Intern
{
public:
    Intern(std::string_view name, std::string_view surname, unsigned int salary, bool is_clumsy);

    const std::string& get_name() const { return _name; }
    const std::string& get_surname() const { return _surname; }

    unsigned int get_salary() const { return _salary; }
    void         increase_salary(unsigned int raise);

    Rank get_rank() const { return Rank::Slave; }
    
    void fetch_coffee();

    unsigned int get_nb_broken_cups() const { return _nb_broken_cups; }

private:
    const std::string _name;
    const std::string _surname;
    unsigned int      _salary;
    bool              _is_clumsy;
    unsigned int      _nb_broken_cups = 0u;
};
