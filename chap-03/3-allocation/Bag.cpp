#include <iostream>
#include <memory>
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
    Content& add(const std::string& name)
    {
        std::unique_ptr<Content>& content = _contents.emplace_back(std::make_unique<Content>(name));
        return *content;
    }

private:
    std::vector<std::unique_ptr<Content>> _contents;
};

int main()
{
    Bag bag;

    Content& my_thing = bag.add("my_thing");

    for (size_t i = 0; i < 200; ++i)
    {
        bag.add("another_thing");
    }

    std::cout << my_thing.name << std::endl;
    my_thing.name = "still_my_thing";
    std::cout << my_thing.name << std::endl;

    return 0;
}