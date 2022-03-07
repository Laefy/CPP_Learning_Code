#include "all_nodes.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

class JsonParser
{
private:
    std::istream& _in;

    void ignore_spaces()
    {
        while (!_in.eof() && std::isspace(_in.peek()))
        {
            _in.get();
        }
    }

    bool check(int c, std::string_view v = "")
    {
        int c2 = _in.peek();
        if (c == c2)
        {
            _in.get();
            return true;
        }
        std::cerr << "Unexpected character (";
        if (c2 >= 20 && c2 < 127)
            std::cerr << (char)c2;
        else if (c2 == -1)
            std::cerr << "EOF";
        else
            std::cerr << '\\' << c2;
        if (v != "")
            std::cerr << "). Expecting a char in \"" << v << "\"." << std::endl;
        else
            std::cerr << "). Expecting '" << (char)c << "'." << std::endl;
        return false;
    }

    Node_ptr parse_Node()
    {
        ignore_spaces();
        int c {};
        switch (c = _in.peek())
        {
        case '{':
            return parse_ObjectNode();
        case '[':
            return parse_ArrayNode();
        case '"':
            return parse_StringNode();
        case 'n':
            return parse_constant("null");
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
            return parse_NumberNode();
        default:
            check(-123456789, "{[\"nft0123456789eE.-+");
            return nullptr;
        }
    }

    Node_ptr parse_constant(std::string_view target)
    {
        char c[6];
        for (size_t x = 0; x < target.size(); x++)
        {
            _in >> c[x];
            if (c[x] != target[x])
            {
                c[x + 1] = '\0';
                std::cerr << "Expecting JSON value (probably constant " << target << ") at position "
                          << (_in.tellg() - (long)x) << ". Got string starting with " << c << std::endl;
                return nullptr;
            }
        }
        if (target == "null")
            return NullNode::make_ptr();
        if (target == "true")
            return BooleanNode::make_ptr(true);
        if (target == "false")
            return BooleanNode::make_ptr(false);
        return nullptr;
    }

    std::optional<std::string> extract_string()
    {
        ignore_spaces();
        check('"');
        std::string s = "";
        char        c = '\0';
        while (((c = _in.get()) != '"') && !_in.eof())
        {
            s += c;
            if (c == '\\') /* If c is a '\' then the next char is not a closing '"' */
            {
                c = _in.get();
                if (_in.eof())
                    break;
                s += _in.get();
            }
        }

        if (_in.eof())
        {
            std::cerr << "Found EOF while looking for closing \"." << std::endl;
            return std::optional<std::string>();
        }
        return s;
    }

    Node_ptr parse_StringNode()
    {
        auto str = extract_string();
        if (str)
            return StringNode::make_ptr(std::move(str.value()));
        else
            return nullptr;
    }

    Node_ptr parse_NumberNode()
    {
        double d;
        _in >> d;
        return NumberNode::make_ptr(d);
    }

    Node_ptr parse_ArrayNode()
    {
        if (!check('['))
            return nullptr;
        auto arrayNode = ArrayNode::make_ptr();
        ignore_spaces();
        if (_in.peek() == ']')
        {
            _in.get();
            return arrayNode;
        }

        do
        {
            auto child = parse_Node();
            if (child == nullptr)
                return nullptr;
            else
                arrayNode->add(std::move(child));
            ignore_spaces();
        }
        while (_in.get() == ',');

        _in.unget();
        if (check(']', ",]"))
            return arrayNode;
        else
            return nullptr;
    }

    Node_ptr parse_ObjectNode()
    {
        if (!check('{'))
            return nullptr;
        auto objectNode = ObjectNode::make_ptr();
        ignore_spaces();
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
            ignore_spaces();
            if (!check(':'))
                return nullptr;
            auto child = parse_Node();
            if (child == nullptr)
                return nullptr;
            else
                objectNode->add(std::move(opt_key.value()), std::move(child));
            ignore_spaces();
        }
        while (_in.get() == ',');
        _in.unget();
        if (check('}', ",}"))
            return objectNode;
        else
            return nullptr;
    }

public:
    JsonParser(std::istream& in)
        : _in(in)
    {}

    Node_ptr run() { return parse_Node(); }

    static Node_ptr parse_from_istream(std::istream& in)
    {
        JsonParser parser(in);
        Node_ptr   parsed_tree = parser.run();
        if (parsed_tree)
            return parsed_tree;
        else
            exit(EXIT_FAILURE);
    }

    static Node_ptr parse_from_file(std::string const& path)
    {
        std::ifstream in(path.c_str(), std::ifstream::in);
        if (!in.is_open())
        {
            std::cerr << "Could not open file: " << path << std::endl;
            exit(EXIT_FAILURE);
        }
        return parse_from_istream(in);
    }

    static Node_ptr parse_from_string(std::string const& str)
    {
        std::stringstream ss { str };
        return parse_from_istream(ss);
    }
};
