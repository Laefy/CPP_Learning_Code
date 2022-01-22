#pragma once

#include <string>

struct Content
{
    Content(const std::string& name)
        : name { name }
    {}

    std::string name;
};

class Box
{
public:
    Box(const std::string& name)
        : _content { name }
    {}

    Content& get_content() { return _content; }

private:
    Content _content;
};
