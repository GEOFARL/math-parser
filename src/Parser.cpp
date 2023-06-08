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
    throw UnexpectedTokenException("Unexpected end of input, expected " + Tokenization::Tokenizer::getTokenTypeString(tokenType));
  }

  if (token.type != tokenType)
  {
    // add custom exception
    throw UnexpectedTokenException("Unexpected token: " + token.value + ", expected " + Tokenization::Tokenizer::getTokenTypeString(tokenType));
  }

  lookahead = tokenizer.getNextToken();

  return token;
}