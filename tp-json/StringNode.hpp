#include "Node.hpp"

class StringNode : public Node
{
private:
    std::string _data;

public:
    std::string print() const override { return _data; }
    StringNode(std::string data)
        : Node { NodeKind::STRING }
        , _data { data }
    {}

    static inline std::unique_ptr<StringNode> make_ptr(std::string s)
    {
        return std::make_unique<StringNode>(std::move(s));
    }
};
