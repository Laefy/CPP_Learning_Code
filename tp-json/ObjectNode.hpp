#pragma once

#include "Node.hpp"

#include <map>
#include <memory>
#include <numeric>

class ObjectNode : public Node
{
private:
    std::map<std::string, Node_ptr> _data;

public:
    const std::map<std::string, Node_ptr>& data() const { return _data; }

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

    size_t child_count() const override { return _data.size(); }

    std::string print() const override
    {
        std::string result = "{";
        bool        first  = true;
        for (auto const& el : _data)
        {
            if (first)
                first = false;
            else
                result += ",";
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
        {
            std::cerr << kind() << "!=" << other.kind() << std::endl;
            return false;
        }
        ObjectNode const* other_s = other.as_ObjectNode();
        size_t            size    = child_count();
        if (other_s->child_count() != size)
        {
            std::cerr << size << " != " << other_s->child_count() << std::endl;
            return false;
        }
        for (auto& pair : other_s->_data)
        {
            auto it = _data.find(pair.first);
            if (it == _data.end())
            {
                std::cerr << pair.first << std::endl;
                return false;
            }
            if (*(it->second) != *(pair.second))
            {
                std::cerr << pair.first << std::endl;
                std::cerr << *pair.second << std::endl;
                std::cerr << *it->second << std::endl;
                return false;
            }
        }
        return true;
    }

    size_t height() const override
    {
        return std::accumulate(_data.begin(), _data.end(), 0,
                               [](size_t i, auto const& pair)
                               { return std::max(i, 1u + pair.second->height()); });
    }

    virtual size_t node_count() const override
    {
        return std::accumulate(_data.begin(), _data.end(), 1,
                               [](size_t i, auto const& pair) { return i + pair.second->node_count(); });
    }

    Node* at(std::string const& key) override
    {
        if (has_child(key))
            return _data.at(key).get();
        else
            return nullptr;
    }
    const Node* at(std::string const& key) const override
    {
        if (has_child(key))
            return _data.at(key).get();
        else
            return nullptr;
    }

    Node_ptr deep_copy() const override
    {
        auto result = make_ptr();
        for (auto const& [key, child] : this->data())
            result->add(key, child->deep_copy());
        return result;
    }

    std::string dot_label() const override { return "{...}"; }

    virtual void dot(std::ostream& o) const
    {
        o << "subgraph cluster_" << dot_id() << " {style=invis;" << std::endl;
        Node::dot(o);
        for (auto& [k, v] : _data)
        {
            v->dot(o);
            o << dot_id() << " -> " << v->dot_id() << " [label= \"" << k << "\"];" << std::endl;
        }
        o << "}" << std::endl;
    }

    bool has_child(const std::string& key) const { return _data.count(key); }
};
