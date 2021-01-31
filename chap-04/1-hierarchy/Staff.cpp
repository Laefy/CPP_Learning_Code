#include "Staff.h"

#include <cstdio>

Staff::Staff(std::string_view name, std::string_view surname, unsigned int salary)
    : _name { name }
    , _surname { surname }
    , _salary { salary }
{}

void Staff::increase_salary(unsigned int raise)
{
    _salary += raise;
}

void Staff::receive_task()
{
    std::printf("%s %s (Staff): \"No problem! I'm on it!\"\n", get_name().c_str(), get_surname().c_str());
    ++_assigned_tasks;
}

void Staff::complete_task()
{
    std::printf("%s %s (Staff): \"Perfect, this is done.\"\n", get_name().c_str(), get_surname().c_str());
    ++_done_tasks;
}
