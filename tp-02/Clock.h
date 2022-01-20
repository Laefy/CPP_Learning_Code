#pragma once

#include "Event.h"
#include "MinuteHand.h"
#include "SecondHand.h"

#include <ostream>
#include <vector>

class Clock
{
    friend std::ostream& operator<<(std::ostream& stream, const Clock& clock)
    {
        return stream << clock._min_hand.get_minutes() << " min " << clock._sec_hand.get_seconds() << " sec";
    }

public:
    void add_event(const Event& event) { _events.emplace_back(event); }

    void tick()
    {
        _sec_hand.advance();

        for (auto it = _events.begin(); it != _events.end();)
        {
            const auto& event = *it;

            if (event.notify_time(_min_hand.get_minutes(), _sec_hand.get_seconds()))
            {
                it = _events.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

private:
    MinuteHand         _min_hand;
    SecondHand         _sec_hand { _min_hand };
    std::vector<Event> _events;
};
