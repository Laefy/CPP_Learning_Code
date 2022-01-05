#include <iostream>
#include <string>

class Person
{
public:
    const std::string& get_name() const { return _name; }
    unsigned int       get_age() const { return _age; }

    void set_name(const std::string& name) { _name = name; }
    void set_age(unsigned int age) { _age = age; }

private:
    std::string  _name;
    unsigned int _age = 0u;
};

int main()
{
    Person p;

    p.set_name("Batman");
    p.set_age(23);

    std::cout << "Person named '" << p.get_name() << "' is " << p.get_age() << " years old." << std::endl;

    return 0;
}
