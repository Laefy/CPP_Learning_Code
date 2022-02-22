#include "../Node.hpp"

struct TreeData
{
    size_t height;
    size_t node_count;

    TreeData(Node_ptr const& node)
        : height { node->height() }
        , node_count { node->node_count() }
    {}
    TreeData(size_t h, size_t c)
        : height { h }
        , node_count { c }
    {}

    inline bool operator==(TreeData const& other)
    {
        return (other.height == height) && (other.node_count == node_count);
    }
}