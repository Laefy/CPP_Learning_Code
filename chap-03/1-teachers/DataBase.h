#pragma once

#include <ostream>
#include <string>
#include <string_view>

class Teacher
{
public:
    Teacher(std::string_view name)
        : _name { name }
    {
    }

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
    {
    }

    void add_teacher(const Teacher& teacher)
    {
        // ???
    }

    friend std::ostream& operator<<(std::ostream& stream, const Subject& subject)
    {
        stream << "-> " << subject._name << " teached by: ";
        // Display teachers.
        return stream;
    }

private:
    const std::string _name;
    // ??? _teachers;
};

class Curriculum
{
public:
    Curriculum(std::string_view name)
        : _name { name }
    {
    }

    void add_subject(const Subject& subject)
    {
        // ???
    }

    friend std::ostream& operator<<(std::ostream& stream, const Curriculum& curriculum)
    {
        stream << "Curriculum <" << curriculum._name << ">" << std::endl;
        // Display subjects.
        return stream;
    }

private:
    const std::string _name;
    // ??? _subjects;
};
