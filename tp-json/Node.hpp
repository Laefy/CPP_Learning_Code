#pragma once

#include "NodeKind.hpp"
#include "Node_ptr.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class NullNode;
class BooleanNode;
class NumberNode;
class StringNode;
class ArrayNode;
class ObjectNode;

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

    virtual bool operator==(const Node&) const = 0;

    virtual NullNode*    as_NullNode() { return nullptr; }
    virtual BooleanNode* as_BooleanNode() { return nullptr; }
    virtual NumberNode*  as_NumberNode() { return nullptr; }
    virtual StringNode*  as_StringNode() { return nullptr; }
    virtual ArrayNode*   as_ArrayNode() { return nullptr; }
    virtual ObjectNode*  as_ObjectNode() { return nullptr; }

    virtual const NullNode*    as_NullNode() const { return nullptr; }
    virtual const BooleanNode* as_BooleanNode() const { return nullptr; }
    virtual const NumberNode*  as_NumberNode() const { return nullptr; }
    virtual const StringNode*  as_StringNode() const { return nullptr; }
    virtual const ArrayNode*   as_ArrayNode() const { return nullptr; }
    virtual const ObjectNode*  as_ObjectNode() const { return nullptr; }

    virtual size_t height() const { return 0u; }
    virtual size_t node_count() const { return 1u; }
};

std::ostream& operator<<(std::ostream& o, const Node& node);