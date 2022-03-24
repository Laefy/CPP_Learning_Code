#pragma once

#include "Node.hpp"

class StringLeaf : public Node
{
private:
    std::string _data;

public:
    std::string print() const override { return '"' + _data + '"'; }
    StringLeaf(std::string data)
        : Node { NodeKind::STRING }
        , _data { data }
    {}

    static inline std::unique_ptr<StringLeaf> make_ptr(std::string s)
    {
        return std::make_unique<StringLeaf>(std::move(s));
    }

    StringLeaf*       as_StringNode() override { return this; }
    const StringLeaf* as_StringNode() const override { return this; }

    inline bool operator==(const Node& other) const override
    {
        if (!(other.is_of_kind(kind())))
            return false;
        return (_data == other.as_StringNode()->_data);
    }

    inline const std::string& data() const { return _data; }

    Node_ptr deep_copy() const override { return make_ptr(data()); }

    std::string dot_label() const override { return "\\\"" + _data + "\\\""; }
};
