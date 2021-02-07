#pragma once

#include <cassert>
#include <cmath>
#include "point.hpp"
#include "shape.hpp"
#include "line.hpp"

class Circle: public Shape {
	Point center;
	float radius;
public:
	Circle(const Point& _center, const float _radius):
		center{_center}, radius{_radius}
	{}
	
	// intersection of 2 circles is the intersection of one cicle with the line L "in the middle" such that
	// L intersects the line between the centers of the circles at distances d1 from circle 1 and d2 from circle 2 where
	// r1^2 - d1^2  = r2^2 - d2^2
	// using d1 + d2 = distance dc between the centers, we get:
	// d1^2 = r1^2 - r2^2 + (dc - d1)^2, that is
	// (d1 + (dc - d1))(d1 - (dc - d1)) = r1^2 - r2^2, that is
	// 2d1 = (r1^2 - r2^2) / dc + dc
	PointContainer intersect(const Circle& other) const {
		PointContainer result;
		const Point center_to_center = other.center - center;
		const float dc = center_to_center.dist_to_0();
		// by convention, circles with the same center do not intersect
		if(dc > 0) {
			const float radii = radius + other.radius;
			if(dc < radii) {
				const float d1 = (dc + (radius * radius - other.radius * other.radius) / dc) / 2;
				const Point P = center + center_to_center * (d1 / dc);
				result.merge(intersect(Line{P, center_to_center.rotate_90deg()}));
			} else if(dc == radii) {
				result.emplace_back(center + center_to_center * (radius / dc));
			}
		}
		return result;
	}

	// to intersect a circle with a line, determine the point on the line that is closest to the center.
	// to this end, form a line L from the circle center in orthogonal direction of the given line and intersect the two lines
	// if the distance d of this intersection point P to the center is larger than the radius, they don't intersect;
	// otherwise, they intersect on the points at distance sqrt(radius * radius - d * d) on L around P
	PointContainer intersect(const Line& ln) const {
		PointContainer result;
		Point ln_dir = ln.direction();
		const Line L = {center, center + ln_dir.rotate_90deg()};
		const PointContainer intersection = L.intersect(ln);
		assert(intersection.size() == 1);
		const Point P = intersection.front();
		const float d = center.dist(P);
		if(d < radius) {
			const float dist_to_p = std::sqrt(radius * radius - d * d);
			ln_dir.normalize();
			result.emplace_back(ln_dir * dist_to_p + P);
			result.emplace_back(ln_dir * -dist_to_p + P);
		} else if(d == radius) {
			result.emplace_back(P);
		}
		return result;
	}

	~Circle() = default;
};
