#pragma once

#include "Node.hpp"

class NumberLeaf : public Node
{
private:
    int _data;

public:
    inline const int& data() const { return _data; }

    std::string print() const override { return std::to_string(_data); }

    NumberLeaf(int data)
        : Node { NodeKind::NUMBER }
        , _data { data }
    {}

    static std::unique_ptr<NumberLeaf> make_ptr(int data) { return std::make_unique<NumberLeaf>(data); }

    bool operator==(const Node& other) const override;

    NumberLeaf*       as_NumberLeaf() override { return this; }
    NumberLeaf const* as_NumberLeaf() const override { return this; }

    Node_ptr deep_copy() const override { return make_ptr(data()); }

    std::string dot_label() const override { return std::to_string(_data); }
};
