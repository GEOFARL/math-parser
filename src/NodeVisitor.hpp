#pragma once
#include "Parser.hpp"

class NodeVisitor
{
  std::unordered_map<std::string, double> *variables;

public:
  NodeVisitor(std::unordered_map<std::string, double> *);
  double visit(ASTNode *);

private:
  double visitNumber(ASTNode *);
  double visitBinaryExpression(ASTNode *);
  double visitUnaryExpression(ASTNode *);
  double visitVariable(ASTNode *);
  double visitAssignment(ASTNode *);

  void addVariable(const std::string &, double);
};
