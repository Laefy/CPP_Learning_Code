#pragma once

#include "NodeKind.hpp"
#include "Node_ptr.hpp"

#include <memory>
#include <string>
#include <vector>

class Node
{
private:
    const NodeKind _kind;

protected:
    Node(NodeKind kind)
        : _kind(kind)
    {}

public:
    virtual NodeKind kind() const { return _kind; }
    virtual bool     is_of_kind(NodeKind kind) const { return _kind == kind; }

    virtual std::string print() const = 0;
};
