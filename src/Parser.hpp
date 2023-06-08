#pragma once

#include <string>
#include <math.h>
#include "Tokenization.hpp"
#include "Exceptions.hpp"

class Parser
{
  std::string input;
  Tokenization::Tokenizer tokenizer;
  Tokenization::Token lookahead;

public:
  Parser(const std::string &);

  double parse();

private:
  double handleBinaryExpression(std::function<double()>, std::function<double()>, Tokenization::TokenType, Tokenization::TokenType);
  double handleExpression();
  double handleTerm();
  double handleFactor();
  double handlePrimary();

  Tokenization::Token eat(Tokenization::TokenType);
};
