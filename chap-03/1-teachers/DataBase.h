#pragma once

#include <ostream>
#include <set>
#include <string>
#include <string_view>

class Teacher
{
public:
    Teacher(std::string_view name)
        : _name { name }
    {}

    friend bool operator==(const Teacher* teacher, const std::string& name) { return teacher->_name == name; }

    friend std::ostream& operator<<(std::ostream& stream, const Teacher& teacher)
    {
        return stream << teacher._name;
    }

private:
    const std::string _name;
};

class Subject
{
public:
    Subject(std::string_view name)
        : _name { name }
    {}

    void add_teacher(const Teacher& teacher) { _teachers.insert(&teacher); }

    void remove_teacher(const Teacher& teacher) { _teachers.erase(&teacher); }

    friend std::ostream& operator<<(std::ostream& stream, const Subject& subject)
    {
        stream << "-> " << subject._name << " teached by: ";

        for (const auto* teacher : subject._teachers)
        {
            stream << *teacher << ", ";
        }

        return stream;
    }

private:
    const std::string        _name;
    std::set<const Teacher*> _teachers;
};

class Curriculum
{
public:
    Curriculum(std::string_view name)
        : _name { name }
    {}

    void add_subject(const Subject& subject) { _subjects.insert(&subject); }

    friend bool operator==(const Curriculum* curriculum, const std::string& name)
    {
        return curriculum->_name == name;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Curriculum& curriculum)
    {
        stream << "Curriculum <" << curriculum._name << ">" << std::endl;

        for (const auto* subject : curriculum._subjects)
        {
            stream << *subject << std::endl;
        }

        return stream;
    }

private:
    const std::string        _name;
    std::set<const Subject*> _subjects;
};
