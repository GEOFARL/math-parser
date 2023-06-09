#include "NodeVisitor.hpp"

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