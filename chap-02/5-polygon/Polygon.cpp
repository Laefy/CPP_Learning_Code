#include "Polygon.h"

void Polygon::add_vertex(int x, int y)
{
    _vertices.emplace_back(x, y);
}

const Vertex& Polygon::get_vertex(size_t idx) const
{
    return _vertices[idx];
}

std::ostream& operator<<(std::ostream& stream, const Polygon& polygon)
{
    for (const auto& v : polygon._vertices)
    {
        stream << "(" << v.first << "," << v.second << ") ";
    }

    return stream;
}
