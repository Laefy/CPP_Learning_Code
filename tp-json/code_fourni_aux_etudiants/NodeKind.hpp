#pragma once

#include <iostream>

enum class NodeKind
{
    BOOLEAN,
    NUMBER,
    STRING,
    ARRAY,
    OBJECT
};

inline std::ostream& operator<<(std::ostream& o, NodeKind kind)
{
    switch (kind)
    {
    case NodeKind::BOOLEAN:
        return o << "BOOLEAN";
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
}
