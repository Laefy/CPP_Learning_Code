#include "Boss.h"
#include "Intern.h"
#include "Staff.h"

#include <cstdio>

void day_summary(const Staff& staff, const Intern& intern)
{
    std::printf(
        "At the end of day, %s completed %u tasks out of %u, and %s broke %u cups.\n\n",
        staff.get_name().c_str(),
        staff.get_done_tasks(),
        staff.get_assigned_tasks(),
        intern.get_name().c_str(),
        intern.get_nb_broken_cups());
}

void at_apple()
{
    constexpr auto is_nice = true;
    Boss steeve { "Steve", "Jobs", 1'000'000u, is_nice };

    Staff laura { "Laura", "Hilton", 2'500 };

    constexpr auto is_clumsy = false;
    Intern bob { "Bob", "Hepburn", 487, is_clumsy };

    steeve.assign_task(laura);
    laura.complete_task();

    steeve.ask_coffee(bob);
    
    steeve.assign_task(laura);
    laura.complete_task();
    
    day_summary(laura, bob);
}

void at_army()
{
    constexpr auto is_nice = false;
    Boss caporal { "Caporal", "McBerdy", 3'800u, is_nice };

    // When he was a child, Lt. Jordan loved basketball.
    Staff michael { "Lieutenant", "Jordan", 1'960 };

    // It's the same Bob as before, but in a more stressful environment.
    constexpr auto is_clumsy = true;
    Intern bob { "Bob", "Hepburn", 754, is_clumsy };

    caporal.assign_task(michael);
    michael.complete_task();

    caporal.ask_coffee(bob);
    caporal.assign_task(michael);

    caporal.ask_coffee(bob);
    caporal.ask_coffee(bob);
    
    caporal.assign_task(michael);
    michael.complete_task();
    
    day_summary(michael, bob);
}

int main()
{
    at_apple();
    at_army();

    return 0;
};
