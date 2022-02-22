#include "Node.hpp"

#include <map>
#include <memory>

class ObjectNode : public Node
{
private:
    std::map<std::string, Node_ptr> _data;

public:
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

    void add(std::string key, Node_ptr value) { _data.emplace(std::move(key), std::move(value)); }

    size_t children_count() const { return _data.size(); }

    std::string print() const override
    {
        std::string result = "{";
        bool        first  = true;
        for (auto const& el : _data)
        {
            if (first)
                first = false;
            else
                result += ", ";
            result += '"' + el.first + "\":";
            result += el.second->print();
        }
        result += '}';
        return result;
    }

    ObjectNode*       as_ObjectNode() override { return this; }
    const ObjectNode* as_ObjectNode() const override { return this; }

    inline bool operator==(const Node& other) const override
    {
        if (!(other.is_of_kind(kind())))
            return false;
        ObjectNode const* other_s = other.as_ObjectNode();
        size_t            size    = children_count();
        if (other_s->children_count() != size)
            return false;
        for (auto& pair : other_s->_data)
        {
            auto it = _data.find(pair.first);
            if (it == _data.end())
                return false;
            if (it->second != pair.second)
                return false;
        }
        return true;
    }
};
