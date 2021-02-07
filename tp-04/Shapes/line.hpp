
#pragma once
#include <cassert>
#include "shape.hpp"
#include "point.hpp"

class Line: public Shape {
protected:
	Point first, last;
public:
	Line(const Point& _first, const Point& _last):
		first{_first}, last{_last}
	{}

	Point direction() const {
		 return last - first;
	}

	// intersecting a line with a line is simple: just solve (for scalars a & b) the equation system:
	//  a * direction1 + offset1 = b * direction2 + offset2
	// that is:
	// a * dir1.x + offset1.x = b * dir2.x + offset2.x
	// a * dir1.y + offset1.y = b * dir2.y + offset2.y
	// that is:
	// a = (b * dir2.x + offset2.x - offset1.x) / dir1.x = (b * dir2.y + offset2.y - offset1.y) / dir1.y
	// that is:
	// dir1.y * dir2.x * b + dir1.y * (offset2.x - offset1.x) = dir1.x * dir2.y * b + dir1.x * (offset2.y - offset1.y)
	// that is:
	// b = (dir1.x * (offset2.y - offset1.y) - dir1.y * (offset2.x - offset1.x)) / (dir1.y * dir2.x - dir1.x * dir2.y)
	PointContainer intersect(const Line& ln) const {
		const Point dir1 = direction().normalized();
		const Point dir2 = ln.direction().normalized();
		// if the lines are parallel, by convention, they don't intersect
		if((dir1 != dir2) && (dir1 != -dir2)){
			assert(dir1.y * dir2.x != dir1.x * dir2.y); // <-- that's just how math works (dir1 & dir2 have the same length!)
			const Point offset_diff = ln.first - first;
			const float b = (dir1.x * offset_diff.y - dir1.y * offset_diff.x) / (dir1.y * dir2.x - dir1.x * dir2.y);
			return {dir2 * b + ln.first};
		}
		return {};
	}

	~Line() = default;

};
