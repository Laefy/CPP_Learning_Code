#pragma once

#include "Node.hpp"

#include <memory>

class NullNode : public Node
{
public:
    std::string print() const override { return "null"; }
    NullNode()
        : Node { NodeKind::NONE }
    {}

    static std::unique_ptr<NullNode> make_ptr() { return std::make_unique<NullNode>(); }

    inline bool operator==(const Node& node) const override { return (node.is_of_kind(kind())); }

    NullNode*       as_NullNode() override { return this; }
    NullNode const* as_NullNode() const override { return this; }

    Node_ptr deep_copy() const override { return make_ptr(); }

    std::string dot_label() const override { return "null"; }
};
