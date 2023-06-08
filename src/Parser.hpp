#pragma once

#include <string>
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
  double handleExpression();
  double handlePrimary();
  double handleTerm();

  Tokenization::Token eat(Tokenization::TokenType);
};
