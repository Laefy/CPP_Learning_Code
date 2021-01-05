#pragma once

#include <ostream>
#include <utility>

using Vertex = std::pair<int, int>;

class Polygon
{
    friend std::ostream& operator<<(std::ostream& stream, const Polygon& polygon);

public:
    ~Polygon();

    void add_vertex(int x, int y);

    const Vertex& get_vertex(size_t idx) const;

private:
    size_t  _size     = 0u;
    Vertex* _vertices = nullptr;
};
