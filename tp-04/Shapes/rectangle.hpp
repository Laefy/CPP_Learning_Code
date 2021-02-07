#pragma once

#include <array>
#include "point.hpp"
#include "shape.hpp"
#include "line.hpp"
#include "line_seg.hpp"

class Rectangle: public Shape {
	Point lower_left, upper_right;
public:
	Rectangle(const Point& p1, const Point& p2):
		lower_left{p1}, upper_right{p2}
	{
		if(lower_left.x > upper_right.x) std::swap(lower_left.x, upper_right.x);
		if(lower_left.y > upper_right.y) std::swap(lower_left.y, upper_right.y);
	}

	bool point_is_inside(const Point& p) const {
		return (p.x >= lower_left.x) && (p.x <= upper_right.x) && (p.y >= lower_left.y) && (p.y <= upper_right.y);
	}
	
	void filter_points_inside(PointContainer& points) const {
		for(auto iter = points.begin(); iter != points.end();) {
			if(point_is_inside(*iter)) {
				++iter;
			} else {
				iter = points.erase(iter);
			}
		}
	}
	
	std::array<LineSegment, 4> get_border() const {
		return {LineSegment{upper_right, {lower_left.x, upper_right.y}},
						LineSegment{lower_left, {upper_right.x, lower_left.y}},
						LineSegment{upper_right, {upper_right.x, lower_left.y}},
						LineSegment{lower_left, {lower_left.x, upper_right.y}}};
	}

	PointContainer intersect(const Shape& other) const override {
		PointContainer result;
		for(const LineSegment& ls: get_border()){
			result.merge(ls.intersect(other));
		}
		return result;
	}

	~Rectangle() = default;
};
