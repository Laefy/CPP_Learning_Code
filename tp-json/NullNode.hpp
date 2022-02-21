#include "Node.hpp"

#include <memory>

class NullNode : public Node
{
public:
    std::string print() const override { return "null"; }
    NullNode()
        : Node { NodeKind::NONE }
    {}

    static std::unique_ptr<NullNode> make_ptr() { return std::make_unique<NullNode>(); }
};
