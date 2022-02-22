#include "Node.hpp"

#include <vector>

class ArrayNode : public Node
{
private:
    std::vector<Node_ptr> _data;

public:
    void push_back(Node_ptr) {}

    std::string print() const override
    {
        std::string result = "[";
        for (unsigned i = 0; i < _data.size(); ++i)
        {
            if (i > 0)
                result += ", ";
            result += _data[i]->print();
        }
        result += ']';
        return result;
    }

    void add(Node_ptr node) { _data.push_back(std::move(node)); }

    ArrayNode()
        : Node(NodeKind::ARRAY)
    {}

    ArrayNode(std::vector<Node_ptr> data)
        : Node { NodeKind::ARRAY }
        , _data { std::move(data) }
    {}

    static inline std::unique_ptr<ArrayNode> make_ptr(std::vector<Node_ptr> data = {})
    {
        return std::make_unique<ArrayNode>(std::move(data));
    }

    size_t children_count() const { return _data.size(); }

    ArrayNode*       as_ArrayNode() override { return this; }
    const ArrayNode* as_ArrayNode() const override { return this; }

    inline bool operator==(const Node& other) const override
    {
        if (!(other.is_of_kind(kind())))
            return false;
        ArrayNode const* other_s = other.as_ArrayNode();
        size_t           size    = children_count();
        if (other_s->children_count() != size)
            return false;
        for (unsigned i = 0; i < size; i++)
            if (!(other_s->_data[i] == _data[i]))
                return false;
        return true;
    }
};
