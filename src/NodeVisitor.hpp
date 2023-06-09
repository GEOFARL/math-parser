#pragma once
#include "Parser.hpp"

class NodeVisitor
{
public:
  double visit(ASTNode *);

private:
  double visitNumber(ASTNode *);
  double visitBinaryExpression(ASTNode *);
  double visitUnaryExpression(ASTNode *);
};
