#pragma once

#include "Texture.h"

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>

class Model
{
public:
    using Container = std::unordered_map<std::string, std::unique_ptr<Model>>;

    static void Create(Container& models)
    {
        std::cout << "Model name: ";
        std::cout.flush();

        std::string name;
        std::cin >> name;

        const auto it = models.find(name);
        if (it != models.end())
        {
            std::cerr << (*it->second) << " already exists." << std::endl;
            return;
        }

        std::cout << "Texture count: ";
        std::cout.flush();

        unsigned int count = 0u;
        std::cin >> count;

        std::vector<std::unique_ptr<Texture>> textures;

        while (count-- > 0u)
        {
            std::cout << "Texture name: ";
            std::cout.flush();

            std::string texture;
            std::cin >> texture;

            textures.push_back(Texture::Load(texture));
        }

        models.emplace_hint(it, name, std::make_unique<Model>(name, std::move(textures)));
    }

    static void Destroy(Container& models)
    {
        std::cout << "Model name: ";
        std::cout.flush();

        std::string name;
        std::cin >> name;

        if (!models.erase(name))
        {
            std::cerr << "No model named: " << name << std::endl;
        }
    }

    Model(std::string_view name, std::vector<std::unique_ptr<Texture>> textures)
        : _name { name }
        , _textures { std::move(textures) }
    {
        std::cout << *this << " has been created." << std::endl;
    }

    ~Model()
    {
        std::cout << *this << " has been destroyed." << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Model& model)
    {
        return stream << "Model " << model._name;
    }

private:
    std::string _name;
    std::vector<std::unique_ptr<Texture>> _textures;
};
