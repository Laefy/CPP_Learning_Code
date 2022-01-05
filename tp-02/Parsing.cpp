#include "Parsing.h"

#include <regex>
#include <string>
#include <utility>

std::vector<Event> parse_events(int argc, char** argv)
{
    const std::regex reg { "(\\d+):(\\d+)\\s*(.+)\\s*" };

    std::vector<Event> events;
    for (auto i = 1; i < argc; ++i)
    {
        const std::string arg { argv[i] };

        std::smatch match;
        if (std::regex_match(arg, match, reg))
        {
            events.emplace_back(std::make_pair(std::stoul(match[1]), std::stoul(match[2])), match[3]);
        }
    }

    return events;
}
