#include "NodeVisitor.hpp"

NodeVisitor::NodeVisitor(std::unordered_map<std::string, double> *variables)
    : variables{variables}
{
}

double NodeVisitor::visit(ASTNode *node)
{
  if (node->type == Tokenization::TokenType::NUMBER)
  {
    return visitNumber(node);
  }
  else if (node->type == Tokenization::TokenType::BINARY_EXPRESSION)
  {
    return visitBinaryExpression(node);
  }
  else if (node->type == Tokenization::TokenType::UNARY_EXPRESSION)
  {
    return visitUnaryExpression(node);
  }
  else if (node->type == Tokenization::TokenType::VARIABLE)
  {
    return visitVariable(node);
  }
  else if (node->type == Tokenization::TokenType::ASSIGNMENT)
  {
    return visitAssignment(node);
  }

  return 0;
}

double NodeVisitor::visitNumber(ASTNode *node)
{
  return std::stod(node->value);
}

double NodeVisitor::visitBinaryExpression(ASTNode *node)
{
  double left = visit(node->left);
  double right = visit(node->right);

  if (node->value == "+")
  {
    return left + right;
  }
  else if (node->value == "-")
  {
    return left - right;
  }
  else if (node->value == "*")
  {
    return left * right;
  }
  else if (node->value == "/")
  {
    return left / right;
  }
  else if (node->value == "^")
  {
    return pow(left, right);
  }
  else
  {
    throw InvalidOperatorException("Invalid operation: " + node->value);
  }
}

double NodeVisitor::visitUnaryExpression(ASTNode *node)
{
  double value = visit(node->left);
  return -value;
}

double NodeVisitor::visitVariable(ASTNode *node)
{
  const std::string &variableName = node->value;
  if (variables->count(variableName) == 0)
  {
    // add custom exception
    throw std::runtime_error("Undefined variable: " + variableName);
  }
  return variables->at(variableName);
}

double NodeVisitor::visitAssignment(ASTNode *node)
{
  std::string variableName = node->value;
  double value = visit(node->right);
  addVariable(variableName, value);
  return value;
}

void NodeVisitor::addVariable(const std::string &name, double value)
{
  (*variables)[name] = value;
}