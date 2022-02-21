#pragma once

#include <iostream>

enum class NodeKind
{
    /* NONE is used for NullNode since NULL is reserved */
    NONE,
    BOOL,
    NUMBER,
    STRING,
    ARRAY,
    OBJECT
};

/* std::ostream& operator<<(std::ostream& o, NodeKind kind)
{
    switch (kind)
    {
    case NodeKind::NONE:
        return o << "NONE";
    case NodeKind::BOOL:
        return o << "BOOL";
    case NodeKind::NUMBER:
        return o << "NUMBER";
    case NodeKind::STRING:
        return o << "STRING";
    case NodeKind::OBJECT:
        return o << "OBJECT";
    case NodeKind::ARRAY:
        return o << "ARRAY";
    }
    // Never happens
    return o;
}*/
