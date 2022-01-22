#include <iostream>
#include <string>
#include <vector>

struct Content
{
    Content(const std::string& name)
        : name { name }
    {}

    std::string name;
};

class Bag
{
public:
    Content& add(const std::string& name) { return _contents.emplace_back(name); }

private:
    std::vector<Content> _contents;
};

int main()
{
    Bag bag;

    Content& my_thing = bag.add("my_thing");

    for (size_t i = 0; i < 200; ++i)
    {
        bag.add("another_thing");
    }

    std::cout << my_thing.name << std::endl; // my_thing ?
    my_thing.name = "still_my_thing";
    std::cout << my_thing.name << std::endl; // still_my_thing ?

    return 0;
}