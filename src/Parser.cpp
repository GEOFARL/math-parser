#include "Parser.hpp"

Parser::Parser(const std::string &input)
    : input{input}, tokenizer{input}
{
  lookahead = tokenizer.getNextToken();
}

double Parser::parse()
{
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
  Tokenization::Token token = eat(Tokenization::TokenType::NUMBER);
  return std::stod(token.value);
}

Tokenization::Token Parser::eat(Tokenization::TokenType tokenType)
{
  Tokenization::Token token = lookahead;

  if (token.type == Tokenization::TokenType::EMPTY)
  {
    // add custom exception
    throw std::runtime_error("Unexpected end of input");
  }

  if (token.type != tokenType)
  {
    // add custom exception
    throw std::runtime_error("Unexpected token: " + token.value);
  }

  lookahead = tokenizer.getNextToken();

  return token;
}