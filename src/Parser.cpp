#include "Parser.hpp"

double Parser::parse(const std::string &inputString)
{
  std::string input{inputString};
  Tokenization::Tokenizer tokenizer{inputString};
  Tokenization::Token lookahead{tokenizer.getNextToken()};

  return handleExpression();
}

/*
Expression
    = Primary
*/
double Parser::handleExpression()
{
  return handlePrimary();
}

/*
Primary
    = NUMBER
*/
double Parser::handlePrimary()
{
  Tokenization::Token token; // get token of a NUMBER type
  return std::stod(token.value);
}