#pragma once

#include <iostream>
#include <string>

struct Content
{
    Content(const std::string& name)
        : name { name }
    {
        std::cout << "Content created" << std::endl;
    }

    Content(const Content& other)
        : name { other.name }
    {
        std::cout << "Content copied" << std::endl;
    }

    ~Content() { std::cout << "Content destroyed" << std::endl; }

    std::string name;
};

class Box
{
public:
    Box(const std::string& name)
        : _content { name }
    {
        std::cout << "Box created" << std::endl;
    }

    ~Box() { std::cout << "Box destroyed" << std::endl; }

    Content& get_content() { return _content; }

private:
    Content _content { "thing" };
};
