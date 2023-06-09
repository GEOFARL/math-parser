#pragma once

#include <string>
#include <math.h>
#include "Tokenization.hpp"
#include "Exceptions.hpp"

struct ASTNode
{
  Tokenization::TokenType type;
  std::string value;
  ASTNode *left;
  ASTNode *right;
};

class Parser
{
  std::string input;
  Tokenization::Tokenizer tokenizer;
  Tokenization::Token lookahead;

public:
  Parser(const std::string &);

  ASTNode *parse();

private:
  ASTNode *handleBinaryExpression(std::function<ASTNode *()>, std::function<ASTNode *()>, Tokenization::TokenType, Tokenization::TokenType);
  ASTNode *handleParenthesizedExpression();
  ASTNode *handleUnaryExpression();
  ASTNode *handleExpression();
  ASTNode *handleTerm();
  ASTNode *handleFactor();
  ASTNode *handlePrimary();

  Tokenization::Token eat(Tokenization::TokenType);
};
