#pragma once

#include "Rank.h"

#include <string>
#include <string_view>

class Staff
{
public:
    Staff(std::string_view name, std::string_view surname, unsigned int salary);

    const std::string& get_name() const { return _name; }
    const std::string& get_surname() const { return _surname; }

    unsigned int get_salary() const { return _salary; }
    void         increase_salary(unsigned int raise);

    Rank get_rank() const { return Rank::Default; }
    
    void receive_task();
    void complete_task();
    
    unsigned int get_assigned_tasks() const { return _assigned_tasks; }
    unsigned int get_done_tasks() const { return _done_tasks; }

private:
    const std::string _name;
    const std::string _surname;
    unsigned int      _salary;
    unsigned int      _assigned_tasks = 0u;
    unsigned int      _done_tasks = 0u;
};
