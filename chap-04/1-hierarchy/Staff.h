#pragma once

#include "Employee.h"

#include <string>
#include <string_view>

class Staff : public Employee
{
public:
    Staff(std::string_view name, std::string_view surname, unsigned int salary);

    void receive_task();
    void complete_task();

    unsigned int get_assigned_tasks() const { return _assigned_tasks; }
    unsigned int get_done_tasks() const { return _done_tasks; }

private:
    unsigned int _assigned_tasks = 0u;
    unsigned int _done_tasks     = 0u;
};
