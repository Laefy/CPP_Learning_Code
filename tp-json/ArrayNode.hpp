#include "Node.hpp"

#include <vector>

class ArrayNode : public Node
{
private:
    std::vector<Node_ptr> _data;

public:
    void push_back(Node_ptr) {}

    std::string print() const override { return "[]"; }

    void add(Node_ptr node) { _data.push_back(std::move(node)); }

    ArrayNode()
        : Node(NodeKind::ARRAY)
    {}

    ArrayNode(std::vector<Node_ptr> data)
        : Node { NodeKind::ARRAY }
        , _data { std::move(data) }
    {}

    static inline std::unique_ptr<ArrayNode> make_ptr(std::vector<Node_ptr> data)
    {
        return std::make_unique<ArrayNode>(std::move(data));
    }
};
