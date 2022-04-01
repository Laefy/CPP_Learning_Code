#pragma once

#include "NodeKind.hpp"
#include "Node_ptr.hpp"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class NullNode;
class BooleanLeaf;
class NumberLeaf;
class StringLeaf;
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
    virtual ~Node() = default;

    NodeKind     kind() const { return _kind; }
    virtual bool is_of_kind(NodeKind kind) const { return _kind == kind; }

    virtual std::string print() const = 0;

    virtual bool operator==(const Node&) const = 0;
    inline bool  operator!=(const Node& other) const { return !(*this == other); }

    virtual BooleanLeaf* as_BooleanLeaf() { return nullptr; }
    virtual NumberLeaf*  as_NumberLeaf() { return nullptr; }
    virtual StringLeaf*  as_StringLeaf() { return nullptr; }
    virtual ArrayNode*   as_ArrayNode() { return nullptr; }
    virtual ObjectNode*  as_ObjectNode() { return nullptr; }

    virtual const BooleanLeaf* as_BooleanLeaf() const { return nullptr; }
    virtual const NumberLeaf*  as_NumberLeaf() const { return nullptr; }
    virtual const StringLeaf*  as_StringLeaf() const { return nullptr; }
    virtual const ArrayNode*   as_ArrayNode() const { return nullptr; }
    virtual const ObjectNode*  as_ObjectNode() const { return nullptr; }

    virtual size_t height() const { return 0u; }
    virtual size_t node_count() const { return 1u; }

    virtual Node_ptr deep_copy() const = 0;

    virtual void dot(std::ostream& o) const
    {
        o << dot_id() << " [label=\"" << dot_label() << "\"];" << std::endl;
    }

    inline std::string dot_id() const
    {
        const void*       address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << "n";
        ss << address;
        return ss.str();
    }

    virtual std::string dot_label() const = 0;

    virtual size_t child_count() const { return 0; }

    virtual Node*       at(std::string const&) { return nullptr; }
    virtual const Node* at(std::string const&) const { return nullptr; }
    virtual const Node* at(size_t) const { return nullptr; }
    virtual Node*       at(size_t) { return nullptr; }
};
std::ostream& operator<<(std::ostream& o, const Node& node);
