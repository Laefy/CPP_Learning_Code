#include "JsonParser.hpp"

#include <cassert>
#include <cctype>
#include <fstream>
#include <sstream>
#include <string>
#include <string_view>

void JsonParser::extract_spaces()
{
    while (!_in.eof() && std::isspace(_in.peek()))
        _in.get();
}

bool JsonParser::check_next_char_equals(char expected_char, std::string_view alternatives)
{
    int expected_char_as_int = expected_char;
    int next_char            = _in.peek();
    if (expected_char_as_int == next_char)
    {
        _in.get();
        return true;
    }
    std::cerr << "Unexpected character (";
    if (std::isprint(next_char))
    {
        std::cerr << static_cast<unsigned char>(next_char);
    }
    else if (next_char == std::char_traits<char>::eof())
    {
        std::cerr << "EOF";
    }
    else
    {
        std::cerr << "code: " << next_char;
    }

    if (alternatives != "")
    {
        std::cerr << "). Expecting a char in \"" << alternatives << "\"." << std::endl;
    }
    else
    {
        std::cerr << "). Expecting '" << expected_char << "'." << std::endl;
    }
    return false;
}

Node_ptr JsonParser::parse_Node()
{
    extract_spaces();
    const int c = _in.peek();
    switch (c)
    {
    case '{':
        return parse_ObjectNode();
    case '[':
        return parse_ArrayNode();
    case '"':
        return parse_StringLeaf();
    case 'f':
        return parse_constant("false");
    case 't':
        return parse_constant("true");
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'e':
    case 'E':
    case '.':
    case '-':
    case '+':
        return parse_NumberLeaf();
    default:
        check_next_char_equals('{', "{[\"ft0123456789eE.-+");
        return nullptr;
    }
}

Node_ptr JsonParser::parse_constant(std::string_view target)
{
    assert(target == "true" || target == "false");
    std::string actual_string;
    actual_string.reserve(target.size());
    for (char expected_char : target)
    {
        char actual_char;
        _in >> actual_char;
        actual_string += actual_char;
        if (actual_char != expected_char)
        {
            std::cerr << "Expecting JSON value (probably constant " << target << ") at position "
                      << (_in.tellg() - (long)actual_string.size()) << ". Got string starting with "
                      << actual_string << std::endl;
            return nullptr;
        }
    }
    if (target == "true")
        return BooleanLeaf::make_ptr(true);
    if (target == "false")
        return BooleanLeaf::make_ptr(false);
    return nullptr;
}

std::optional<std::string> JsonParser::extract_string()
{
    extract_spaces();
    check_next_char_equals('"');
    std::string s;
    char        c = '\0';
    while (((c = _in.get()) != '"') && !_in.eof())
    {
        if (c == '\\') /* If c is a '\' then the next char is escaped. */
        {
            c = _in.get();
            if (_in.eof())
                break;
        }
        s += c;
    }

    if (_in.eof())
    {
        std::cerr << "Found EOF while looking for closing \"." << std::endl;
        return std::optional<std::string>();
    }
    return s;
}

Node_ptr JsonParser::parse_StringLeaf()
{
    auto str = extract_string();
    if (str)
        return StringLeaf::make_ptr(std::move(str.value()));
    else
        return nullptr;
}

Node_ptr JsonParser::parse_NumberLeaf()
{
    unsigned starting_pos = _in.tellg();

    double d;
    _in >> d;

    size_t end_pos = _in.tellg();

    if (starting_pos == end_pos)
        return nullptr;
    else
        return NumberLeaf::make_ptr(d);
}

Node_ptr JsonParser::parse_ArrayNode()
{
    if (!check_next_char_equals('['))
        return nullptr;
    auto arrayNode = ArrayNode::make_ptr();
    extract_spaces();
    if (_in.peek() == ']')
    {
        _in.get();
        return arrayNode;
    }
    else
    {
        do
        {
            auto child = parse_Node();
            if (child == nullptr)
                return nullptr;
            else
                arrayNode->add(std::move(child));
            extract_spaces();
        }
        while (_in.get() == ',');

        _in.unget();
        if (check_next_char_equals(']', ",]"))
            return arrayNode;
        else
            return nullptr;
    }
}

Node_ptr JsonParser::parse_ObjectNode()
{
    if (!check_next_char_equals('{'))
        return nullptr;
    auto objectNode = ObjectNode::make_ptr();
    extract_spaces();
    if (_in.peek() == '}')
    {
        _in.get();
        return objectNode;
    }

    do
    {
        std::optional<std::string> opt_key = extract_string();
        if (!opt_key)
            return nullptr;
        extract_spaces();
        if (!check_next_char_equals(':'))
            return nullptr;
        auto child = parse_Node();
        if (child == nullptr)
            return nullptr;
        else
            objectNode->add(std::move(opt_key.value()), std::move(child));
        extract_spaces();
    }
    while (_in.get() == ',');
    _in.unget();
    if (check_next_char_equals('}', ",}"))
        return objectNode;
    else
        return nullptr;
}

Node_ptr JsonParser::run()
{
    return parse_Node();
}

Node_ptr JsonParser::parse_from_istream(std::istream& in)
{
    JsonParser parser(in);
    Node_ptr   parsed_tree = parser.run();
    if (parsed_tree)
    {
        parser.extract_spaces();
        if (in.good() && (in.get() != std::char_traits<char>::eof()))
            std::cerr << "[Warning] Ended parsing before reaching EOF." << std::endl;
        return parsed_tree;
    }
    else
        exit(EXIT_FAILURE);
}

Node_ptr JsonParser::parse_from_file(std::string const& path)
{
    std::ifstream in(path.c_str(), std::ifstream::in);
    if (!in.is_open())
    {
        std::cerr << "Could not open file: \"" << path << '"' << std::endl;
        exit(EXIT_FAILURE);
    }
    return parse_from_istream(in);
}

Node_ptr JsonParser::parse_from_string(std::string const& str)
{
    std::stringstream ss { str };
    return parse_from_istream(ss);
}
