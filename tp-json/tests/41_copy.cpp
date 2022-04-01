#include "../JsonParser.hpp"
#include "custom_assert.hpp"

int main()
{

    std::string json_dir = "json/";
    std::string filename = json_dir + "pokedex.json";
    Node_ptr    original = JsonParser::parse_from_file(filename);

    // We make the copy multiple times to ensure that deallocation works
    for (unsigned i = 0; i < 100; ++i)
    {
        Node_ptr copy = original->deep_copy();
        ASSERT_EQUAL(copy->height(), 5u);
        ASSERT_EQUAL(copy->node_count(), 3779u);
        ASSERT_EQUAL(copy->kind(), NodeKind::OBJECT);

        ASSERT_EQUAL(*original, *copy);

        ASSERT_UNEQUAL(&*original, &*copy);
    }

    // We browse the original tree to check that it was not deallocated.
    ASSERT_EQUAL(original->height(), 5u);
    ASSERT_EQUAL(original->node_count(), 3779u);
}