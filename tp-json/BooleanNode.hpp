#include "Node.hpp"

class BooleanNode : public Node {
private:
  bool _data;
public:
  std::string print() const override {return _data?"true":"false";}
  BooleanNode(bool data) : Node{NodeKind::BOOL}, _data{data} {}
};
