#include "MathInterpreter.hpp"

MathInterpreter::MathInterpreter(const char *filepath)
    : reader{fs::path{std::string{filepath}}}
{
}

double MathInterpreter::interpret()
{
  std::string content = reader.readFile();
  Parser parser{content};
  NodeVisitor visitor{&variables};
  std::vector<ASTNode *> nodes;
  while (parser.leftSomething())
  {
    nodes.push_back(parser.parse());
  }
  for (size_t i{}; i < nodes.size() - 1; ++i)
  {
    visitor.visit(nodes[i]);
  }
  return visitor.visit(nodes[nodes.size() - 1]);
}