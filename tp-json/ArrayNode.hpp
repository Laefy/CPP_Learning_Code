#pragma once

#include "Node.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class ArrayNode : public Node
{
private:
    std::vector<Node_ptr> _data;

public:
    std::vector<Node_ptr> const& data() const { return _data; }

    std::string print() const override
    {
        std::string result = "[";
        for (unsigned i = 0; i < _data.size(); ++i)
        {
            if (i > 0)
                result += ",";
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

    size_t child_count() const override { return _data.size(); }

    ArrayNode*       as_ArrayNode() override { return this; }
    const ArrayNode* as_ArrayNode() const override { return this; }

    inline bool operator==(const Node& other) const override
    {
        if (!(other.is_of_kind(kind())))
        {
            std::cerr << kind() << "!=" << other.kind() << std::endl;
            return false;
        }
        ArrayNode const* other_s = other.as_ArrayNode();
        size_t           size    = child_count();
        if (other_s->child_count() != size)
        {
            std::cerr << size << " != " << other_s->child_count() << std::endl;
            return false;
        }
        for (unsigned i = 0; i < size; i++)
        {
            if (*(other_s->_data[i]) != *(_data[i]))
            {
                std::cerr << *(other_s->_data[i]) << std::endl;
                std::cerr << *_data[i] << std::endl;
                return false;
            }
        }
        return true;
    }

    size_t height() const override
    {
        return std::accumulate(_data.begin(), _data.end(), 0,
                               [](size_t i, Node_ptr const& child)
                               { return std::max(i, 1u + child->height()); });
    }

    virtual size_t node_count() const override
    {
        return std::accumulate(_data.begin(), _data.end(), 1,
                               [](size_t i, Node_ptr const& child) { return i + child->node_count(); });
    }

    std::vector<Node_ptr>::iterator begin() { return _data.begin(); }
    std::vector<Node_ptr>::iterator end() { return _data.end(); }

    std::vector<Node_ptr>::const_iterator begin() const { return _data.begin(); }
    std::vector<Node_ptr>::const_iterator end() const { return _data.end(); }

    Node_ptr deep_copy() const override
    {
        auto result = make_ptr();
        for (auto const& elt : this->data())
            result->add(elt->deep_copy());
        return result;
    }

    std::string dot_label() const override { return "[...]"; }

    virtual void dot(std::ostream& o) const
    {
        Node::dot(o);
        o << "subgraph cluster_" << dot_id() << " {style=invis;" << std::endl;
        for (auto it = _data.rbegin(); it != _data.rend(); ++it)
        {
            (*it)->dot(o);
            o << dot_id() << " -> " << (*it)->dot_id() << " ;" << std::endl;
        }
        o << "}" << std::endl;
    }

    Node* at(size_t index) override
    {
        if (index < child_count())
            return _data.at(index).get();
        else
            return nullptr;
    }
    const Node* at(size_t index) const override
    {
        if (index < child_count())
            return _data.at(index).get();
        else
            return nullptr;
    }
};
