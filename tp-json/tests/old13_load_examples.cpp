#include "basic_node_instances.cpp"

int main()
{
    for (auto const& node : example::instances)
    {
        std::cout << node->print() << std::endl;
    }
}