#pragma once

#include "line.hpp"

class LineSegment: public Line {
protected:
	using Line::first;
	using Line::last;
public:
	using Line::Line;

	~LineSegment() = default;
};
