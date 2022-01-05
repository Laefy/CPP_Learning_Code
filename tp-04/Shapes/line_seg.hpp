#pragma once

#include "line.hpp"

class LineSegment : public Line
{
public:
    using Line::Line;

    ~LineSegment() = default;
};
