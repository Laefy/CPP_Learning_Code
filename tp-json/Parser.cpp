#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<string_view>
#include<vector>
#include<memory>
#include "NodeKind.hpp"
#include "Node.hpp"
#include "NullNode.hpp"
#include "BooleanNode.hpp"
#include "NumberNode.hpp"
#include "ArrayNode.hpp"
#include "ObjectNode.hpp"
#include "StringNode.hpp"

class JsonParser {
private:
  std::istream& _in;

  bool check(int c, std::string_view v) {
    int c2 = _in.peek();
    if (c == c2) {
      _in.get();
      return true;
    }
    std::cerr << "Unexpected character (";
    if ( c2>=20 && c2 <127) 
      std::cerr << (char) c;
    else if (c2 == -1)
      std::cerr << "EOF";
    else
      std::cerr << '\\' << c;
    std::cerr << "). Expecting a char in\""
              << v << "\"." << std::endl;
    return false;
  }

  Node_ptr parseNode() {
    int c;
    switch (c = _in.peek()) {
      case '{' : return parseObject();
      case '[' : return parseArray();
      case '"' : return parseString();
      case 'n' : return parseConstant("null");
      case 'f' : return parseConstant("false");
      case 't' : return parseConstant("true");
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
      case 'e': case 'E': case '.': case '-': case '+':
        return parseNumber();
      default: 
        check(-123456789, "{[\"nft0123456789eE.-+");
        return nullptr;
    }
  }

  Node_ptr 
  parseConstant(std::string_view target)
  {
    char c[6];
    for (size_t x=0; x<target.size(); x++) {
      _in >> c[x];
      if (c[x] != target[x]) {
        c[x+1]= '\0';
        std::cerr << "Expecting JSON value (probably constant " << target 
                  << ") at position " << (_in.tellg()-(long)x)
                  << ". Got string starting with " << c << std::endl;
        return nullptr;
      }
    }
    if (target == "null")
      return Node_ptr(new NullNode());
    if (target == "true")
      return Node_ptr(new BooleanNode(true));
    if (target == "false")
      return Node_ptr(new BooleanNode(false));
    return nullptr;
  }

  std::string extract_string() {
    int c = _in.get();
    std::string s = "";
    while (c != '"' && !_in.eof()) {
      s += c;
      c = _in.get();
    }
    if (!_in.eof()) {
      std::cerr << "Found EOF while looking for closing \"." << std::endl;
      return nullptr;
    }
    return s;
  }
  
  Node_ptr
  parseString() {
    return Node_ptr(new StringNode(extract_string()));
  }

  Node_ptr
  parseNumber() {
    double d;
    _in >> d;
    return Node_ptr(new NumberNode(d));
  }

  Node_ptr
  parseArray() {
    int c = _in.get();
    auto arrayNode = new ArrayNode();
    
    while (c == ',' || c == '[') {
      arrayNode->add(parseNode());
      c = _in.get();
    }
    
    if (check(']',",]"))
      return Node_ptr(arrayNode);
    else
      return nullptr;
  }

  Node_ptr
  parseObject() {
    return nullptr;
  }

public:
  JsonParser(std::istream& i) : _in(i) {}

  Node_ptr run() { return parseNode(); }

  static Node_ptr parseFromFile(std::string const& s) {
    std::ifstream in(s.c_str());
    JsonParser parser(in);
    return parser.run();
  }

  static Node_ptr parseFromString(std::string const& s) {
    std::stringstream in(s);
    JsonParser parser(in);
    return parser.run();
  }
};
