#pragma once

class MinuteHand
{
public:
    void advance() { ++_minutes; }
    int  get_minutes() const { return _minutes; }

private:
    int _minutes = 0;
};