#include "Polygon.h"
#include "realloc.h"

Polygon::~Polygon()
{
    delete[] _vertices;
}

void Polygon::add_vertex(int x, int y)
{
    const auto old_size = _size;
    ++_size;

    _vertices = realloc(_vertices, old_size, _size);
    _vertices[old_size] = Vertex { x, y };
}

const Vertex& Polygon::get_vertex(size_t idx) const
{
    return _vertices[idx];
}

std::ostream& operator<<(std::ostream& stream, const Polygon& polygon)
{
    for (size_t i = 0; i < polygon._size; ++i)
    {
        const auto& v = polygon._vertices[i];
        stream << "(" << v.first << "," << v.second << ") ";
    }

    return stream;
}
