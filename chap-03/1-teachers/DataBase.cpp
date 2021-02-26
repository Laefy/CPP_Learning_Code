#include "DataBase.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

struct SubjectArgs
{
    operator bool() const { return !name.empty() && !curriculum.empty(); }

    std::string              name;
    std::string              curriculum;
    std::vector<std::string> teachers;
};

SubjectArgs parse_subject_args(const std::string& args)
{
    std::stringstream stream;
    stream << args;

    SubjectArgs result;
    stream >> result.name;
    stream >> result.curriculum;

    while (!stream.eof())
    {
        stream >> result.teachers.emplace_back();
    }

    return result;
}

int main()
{
    std::vector<Curriculum*> curriculums;
    std::vector<Subject*>    subjects;
    std::vector<Teacher*>    teachers;

    auto quit = false;
    while (!quit)
    {
        std::cout << "$> ";
        std::cout.flush();

        std::string command;
        std::cin >> command;

        if (command == "q")
        {
            quit = true;
            continue;
        }
        else if (command == "d")
        {
            for (const auto* curriculum : curriculums)
            {
                std::cout << *curriculum << std::endl;
            }

            std::cout << std::endl;
        }
        else if (command == "c")
        {
            std::string name;
            std::cin >> name;

            curriculums.emplace_back(new Curriculum { name });
        }
        else if (command == "t")
        {
            std::string name;
            std::cin >> name;

            teachers.emplace_back(new Teacher { name });
        }
        else if (command == "r")
        {
            std::string name;
            std::cin >> name;

            const auto teacher_it = std::find(teachers.begin(), teachers.end(), name);
            if (teacher_it == teachers.end())
            {
                continue;
            }

            auto* teacher = *teacher_it;
            for (auto* subject : subjects)
            {
                subject->remove_teacher(*teacher);
            }

            teachers.erase(teacher_it);
            delete teacher;
        }
        else if (command == "s")
        {
            std::string args;
            std::getline(std::cin, args);

            if (auto result = parse_subject_args(args))
            {
                const auto curriculum_it =
                    std::find(curriculums.begin(), curriculums.end(), result.curriculum);
                if (curriculum_it == curriculums.end())
                {
                    continue;
                }

                auto* subject = subjects.emplace_back(new Subject { result.name });
                (*curriculum_it)->add_subject(*subject);

                for (const auto& teacher_name : result.teachers)
                {
                    const auto teacher_it = std::find(teachers.begin(), teachers.end(), teacher_name);
                    if (teacher_it == teachers.end())
                    {
                        continue;
                    }

                    subject->add_teacher(**teacher_it);
                }
            }
        }
    }

    for (auto* teacher : teachers)
    {
        delete teacher;
    }

    for (auto* subject : subjects)
    {
        delete subject;
    }

    for (auto* curriculum : curriculums)
    {
        delete curriculum;
    }

    return 0;
}
