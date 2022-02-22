#include "Node.hpp"

class NumberNode : public Node
{
private:
    int _data;

public:
    std::string print() const override { return std::to_string(_data); }
    NumberNode(int data)
        : Node { NodeKind::NUMBER }
        , _data { data }
    {}

    static std::unique_ptr<NumberNode> make_ptr(int data) { return std::make_unique<NumberNode>(data); }

    inline bool operator==(const Node& other) const override
    {
        if (!(other.is_of_kind(kind())))
        {
            return false;
        }
        return (_data == other.as_NumberNode()->_data);
    }

    NumberNode*       as_NumberNode() override { return this; }
    NumberNode const* as_NumberNode() const override { return this; }
};
