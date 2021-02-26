#pragma once

#include "Texture.h"

#include <iostream>
#include <memory>
#include <string>
#include <string_view>

class Texture
{
public:
    static std::unique_ptr<Texture> Load(std::string_view name)
    {
        std::cout << "Texture width: ";
        std::cout.flush();

        int width = 0;
        std::cin >> width;

        std::cout << "Texture height: ";
        std::cout.flush();

        int height = 0;
        std::cin >> height;

        return std::make_unique<Texture>(name, width, height);
    }

    static unsigned int Count() { return _count; }

    Texture(std::string_view name, int width, int height)
        : _name { name }
        , _width { width }
        , _height { height }
    {
        std::cout << *this << " has been loaded." << std::endl;
        ++_count;
    }

    ~Texture()
    {
        --_count;
        std::cout << *this << " has been unloaded." << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Texture& texture)
    {
        return stream << "Texture " << texture._name << " (" << texture._width << "x" << texture._height << ")";
    }

private:
    static inline unsigned int _count = 0u;

    std::string _name;
    int _width;
    int _height;
};
