#include "../ArrayNode.hpp"
#include "../BooleanLeaf.hpp"
#include "../Node.hpp"
#include "../NodeKind.hpp"
#include "../NumberLeaf.hpp"
#include "../ObjectNode.hpp"
#include "../StringLeaf.hpp"
#include "custom_assert.hpp"

#include <utility>

int main()
{
    Node_ptr null_node_ptr = nullptr;
    Node_ptr bool_node_ptr = BooleanLeaf::make_ptr(true);
    Node_ptr int_node_ptr  = NumberLeaf::make_ptr(1);
    Node_ptr str_node_ptr  = StringLeaf::make_ptr("Hello world");
    Node_ptr arr_node_ptr  = ArrayNode::make_ptr();
    Node_ptr obj_node_ptr  = ObjectNode::make_ptr();
}
