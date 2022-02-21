#pragma once

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
    std::string    _name;
    Trainer const* _trainer = nullptr;

public:
    Pokemon(std::string name)
        : _name(std::move(name))
    {}

    std::string const& name() const { return _name; }

    void set_trainer(Trainer const* trainer) { _trainer = trainer; }

    Trainer const* trainer() const { return _trainer; }
};
