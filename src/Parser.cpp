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
    = Term (("+" / "-") Term)*
*/
double Parser::handleExpression()
{
  double left = handleTerm();

  while (lookahead.type == Tokenization::TokenType::ADDITION || lookahead.type == Tokenization::TokenType::SUBTRACTION)
  {
    if (lookahead.type == Tokenization::TokenType::ADDITION)
    {
      eat(Tokenization::TokenType::ADDITION);
      double right = handleTerm();
      left += right;
    }
    else
    {
      eat(Tokenization::TokenType::SUBTRACTION);
      double right = handleTerm();
      left -= right;
    }
  }
  return left;
}

/*
Term
    = Primary(("*" / "/") Primary)*
*/
double Parser::handleTerm()
{
  double left = handlePrimary();
  while (lookahead.type == Tokenization::TokenType::MULTIPLICATION || lookahead.type == Tokenization::TokenType::DIVISION)
  {
    if (lookahead.type == Tokenization::TokenType::MULTIPLICATION)
    {
      eat(Tokenization::TokenType::MULTIPLICATION);
      double right = handlePrimary();
      left *= right;
    }
    else
    {
      eat(Tokenization::TokenType::DIVISION);
      double right = handlePrimary();
      left /= right;
    }
  }

  return left;
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