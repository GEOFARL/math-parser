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