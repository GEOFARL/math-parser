#pragma once

#include <string>
#include <math.h>
#include <unordered_map>
#include "Tokenization.hpp"
#include "Exceptions.hpp"

struct ASTNode
{
  Tokenization::TokenType type;
  std::string value;
  ASTNode *left;
  ASTNode *right;

  ~ASTNode()
  {
    if (left != nullptr)
    {
      delete left;
    }
    if (right != nullptr)
    {
      delete right;
    }
  }
};

class Parser
{
  std::string input;
  Tokenization::Tokenizer tokenizer;
  Tokenization::Token lookahead;
  ASTNode *top;
  std::unordered_map<std::string, double> *variables;

public:
  Parser(const std::string &, std::unordered_map<std::string, double> *);

  ~Parser();

  ASTNode *parse();

private:
  ASTNode *handleBinaryExpression(std::function<ASTNode *()>, std::function<ASTNode *()>, Tokenization::TokenType, Tokenization::TokenType);
  ASTNode *handleParenthesizedExpression();
  ASTNode *handleUnaryExpression();
  ASTNode *handleExpression();
  ASTNode *handleTerm();
  ASTNode *handleFactor();
  ASTNode *handleVariable();
  ASTNode *handlePrimary();

  Tokenization::Token eat(Tokenization::TokenType);
};
