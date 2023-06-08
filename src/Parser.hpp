#pragma once

#include <string>
#include "Tokenization.hpp"

class Parser
{
  std::string input;
  Tokenization::Tokenizer tokenizer;
  Tokenization::Token lookahead;

public:
  Parser(const std::string &);

  double parse();

private:
  double handleExpression();
  double handlePrimary();

  Tokenization::Token eat(Tokenization::TokenType);
};
