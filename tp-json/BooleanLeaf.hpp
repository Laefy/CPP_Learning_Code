#pragma once

#include "Node.hpp"

class BooleanLeaf : public Node
{
private:
    bool _data;

public:
    std::string print() const override { return _data ? "true" : "false"; }
    BooleanLeaf(bool data)
        : Node { NodeKind::BOOLEAN }
        , _data { data }
    {}

    static std::unique_ptr<BooleanLeaf> make_ptr(bool data) { return std::make_unique<BooleanLeaf>(data); }

    BooleanLeaf*       as_BooleanLeaf() override { return this; }
    BooleanLeaf const* as_BooleanLeaf() const override { return this; }

    inline bool operator==(const Node& other) const override
    {
        if (!(other.is_of_kind(kind())))
        {
            return false;
        }
        return (_data == other.as_BooleanLeaf()->_data);
    }

    const bool& data() const { return _data; }

    Node_ptr deep_copy() const override { return make_ptr(data()); }

    std::string dot_label() const override { return _data ? "true" : "false"; }
};
