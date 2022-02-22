#include "../json.hpp"
#include "assert.cpp"

int main()
{
    Node_ptr nullnode1 = NullNode::make_ptr();
    Node_ptr nullnode2 = NullNode::make_ptr();
    ASSERT_EQUAL(*nullnode1, *nullnode2);

    Node_ptr boolnode1 = NumberNode::make_ptr(true);
    Node_ptr boolnode2 = NumberNode::make_ptr(true);
    ASSERT_EQUAL(*boolnode1, *boolnode2);

    Node_ptr numbernode1 = NumberNode::make_ptr(0);
    Node_ptr numbernode2 = NumberNode::make_ptr(0);
    ASSERT_EQUAL(*numbernode1, *numbernode2);

    Node_ptr stringnode1 = StringNode::make_ptr("Hello");
    Node_ptr stringnode2 = StringNode::make_ptr("Hello");
    ASSERT_EQUAL(*stringnode1, *stringnode2);

    Node_ptr arraynode1 = ArrayNode::make_ptr();
    Node_ptr arraynode2 = ArrayNode::make_ptr();
    ASSERT_EQUAL(*arraynode1, *arraynode2);
}