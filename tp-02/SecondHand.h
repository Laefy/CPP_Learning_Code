#pragma once

#include "MinuteHand.h"

class SecondHand
{
public:
    explicit SecondHand(MinuteHand& min_hand)
        : _min_hand { min_hand }
    {}

    void advance()
    {
        ++_seconds;
        if (_seconds >= 60)
        {
            _min_hand.advance();
            _seconds = 0;
        }
    }

    int get_seconds() const { return _seconds; }

private:
    MinuteHand& _min_hand;
    int         _seconds = 0;
};