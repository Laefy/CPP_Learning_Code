#include "Boss.h"

#include "Intern.h"
#include "Rank.h"
#include "Staff.h"

#include <cstdio>

Boss::Boss(std::string_view name, std::string_view surname, unsigned int salary, bool is_nice)
    : Employee { name, surname, salary, Rank::TopManagement }
    , _is_nice { is_nice }
{}

void Boss::assign_task(Staff& staff) const
{
    if (_is_nice)
    {
        std::printf("%s %s (Boss): \"Please %s, could you do this for me?\"\n", get_name().c_str(),
                    get_surname().c_str(), staff.get_name().c_str());
    }
    else
    {
        std::printf("%s %s (Boss): \"%s! Hurry your ass up and finish me this right away!\"\n",
                    get_name().c_str(), get_surname().c_str(), staff.get_surname().c_str());
    }

    staff.receive_task();
}

void Boss::ask_coffee(Intern& intern) const
{
    if (_is_nice)
    {
        std::printf("%s %s (Boss): \"Could you fetch me a coffee %s?\"\n", get_name().c_str(),
                    get_surname().c_str(), intern.get_name().c_str());
    }
    else
    {
        std::printf("%s %s (Boss): \"Hey %s! Can't you see I'm thirsty ?!\"\n", get_name().c_str(),
                    get_surname().c_str(), intern.get_surname().c_str());
    }

    intern.fetch_coffee();
}
