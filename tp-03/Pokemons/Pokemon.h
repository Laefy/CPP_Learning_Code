#pragma once

#include <string>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(const std::string& name)
        : _name { name }
    {}

    const std::string& name() const { return _name; }

    void           captured_by(const Trainer& trainer) { _trainer = &trainer; }
    const Trainer* trainer() const { return _trainer; }

private:
    std::string    _name;
    const Trainer* _trainer = nullptr;
};
