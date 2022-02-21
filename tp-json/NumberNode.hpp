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
};
