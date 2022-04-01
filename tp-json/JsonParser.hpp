#pragma once

#include "ArrayNode.hpp"
#include "BooleanLeaf.hpp"
#include "Node.hpp"
#include "NodeKind.hpp"
#include "NumberLeaf.hpp"
#include "ObjectNode.hpp"
#include "StringLeaf.hpp"

#include <iostream>
#include <optional>

class JsonParser
{
private:
    std::istream& _in;

    void extract_spaces();
    bool check_next_char_equals(char expected_char, std::string_view alternatives = "");

    std::optional<std::string> extract_string();

    Node_ptr parse_Node();
    Node_ptr parse_constant(std::string_view target);
    Node_ptr parse_StringLeaf();
    Node_ptr parse_NumberLeaf();
    Node_ptr parse_ArrayNode();
    Node_ptr parse_ObjectNode();

public:
    JsonParser(std::istream& in)
        : _in(in)
    {}

    Node_ptr run();

    static Node_ptr parse_from_istream(std::istream& in);
    static Node_ptr parse_from_file(std::string const& path);
    static Node_ptr parse_from_string(std::string const& str);
};
