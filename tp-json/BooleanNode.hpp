#pragma once

#include "Node.hpp"

class BooleanNode : public Node
{
private:
    bool _data;

public:
    std::string print() const override { return _data ? "true" : "false"; }
    BooleanNode(bool data)
        : Node { NodeKind::BOOLEAN }
        , _data { data }
    {}

    static std::unique_ptr<BooleanNode> make_ptr(bool data) { return std::make_unique<BooleanNode>(data); }

    BooleanNode*       as_BooleanNode() override { return this; }
    BooleanNode const* as_BooleanNode() const override { return this; }

    inline bool operator==(const Node& other) const override
    {
        if (!(other.is_of_kind(kind())))
        {
            return false;
        }
        return (_data == other.as_BooleanNode()->_data);
    }

    const bool& data() const { return _data; }

    Node_ptr deep_copy() const override { return make_ptr(data()); }

    std::string dot_label() const override { return std::to_string(_data); }
};
