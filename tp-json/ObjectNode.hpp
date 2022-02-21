#include "Node.hpp"

#include <map>
#include <memory>

class ObjectNode : public Node
{
private:
    std::map<std::string, Node_ptr> _data;

public:
    std::string print() const override { return "{}"; }

    void add(std::string s, Node_ptr node) { _data.emplace(std::move(s), std::move(node)); }

    ObjectNode()
        : Node(NodeKind::OBJECT)
    {}

    ObjectNode(std::map<std::string, Node_ptr> data)
        : Node(NodeKind::OBJECT)
        , _data(std::move(data))
    {}

    static std::unique_ptr<ObjectNode> make_ptr(std::map<std::string, Node_ptr> data = {})
    {
        return std::make_unique<ObjectNode>(std::move(data));
    }
};
