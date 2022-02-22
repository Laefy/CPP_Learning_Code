#include "Node.hpp"

class BooleanNode : public Node
{
private:
    bool _data;

public:
    std::string print() const override { return _data ? "true" : "false"; }
    BooleanNode(bool data)
        : Node { NodeKind::BOOLEAN }
        , _data { data }
    {}

    static std::unique_ptr<BooleanNode> make_ptr(bool data) { return std::make_unique<BooleanNode>(data); }

    BooleanNode*       as_BooleanNode() override { return this; }
    BooleanNode const* as_BooleanNode() const override { return this; }

    inline bool operator==(const Node& other) const override
    {
        if (!(other.is_of_kind(kind())))
        {
            return false;
        }
        return (_data == other.as_BooleanNode()->_data);
    }
};
