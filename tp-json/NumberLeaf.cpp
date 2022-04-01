#include "NumberLeaf.hpp"

bool NumberLeaf::operator==(const Node& other) const
{
    if (!(other.is_of_kind(kind())))
    {
        return false;
    }
    return (_data == other.as_NumberLeaf()->_data);
}