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

double Parser::handleBinaryExpression(std::function<double()> leftRule, std::function<double()> rightRule, Tokenization::TokenType operatorType1, Tokenization::TokenType operatorType2)
{
  double left = leftRule();

  while (lookahead.type == operatorType1 || lookahead.type == operatorType2)
  {
    Tokenization::TokenType operatorType = eat(lookahead.type).type;
    switch (operatorType)
    {
    case Tokenization::TokenType::ADDITION:
    {
      left += rightRule();
      break;
    }
    case Tokenization::TokenType::SUBTRACTION:
    {
      left -= rightRule();
      break;
    }
    case Tokenization::TokenType::MULTIPLICATION:
    {
      left *= rightRule();
      break;
    }
    case Tokenization::TokenType::DIVISION:
    {
      left /= rightRule();
      break;
    }
    case Tokenization::TokenType::EXPONENTIATION:
    {
      left = pow(left, rightRule());
      break;
    }
    default:
      break;
    }
  }

  return left;
}

/*
Expression
    = Term (("+" / "-") Term)*
*/
double Parser::handleExpression()
{
  return handleBinaryExpression(
      [&]()
      { return handleTerm(); },
      [&]()
      { return handleTerm(); },
      Tokenization::TokenType::ADDITION,
      Tokenization::TokenType::SUBTRACTION);
}

/*
Term
    = Factor(("*" / "/") Factor)*
*/
double Parser::handleTerm()
{
  return handleBinaryExpression(
      [&]()
      { return handleFactor(); },
      [&]()
      { return handleFactor(); },
      Tokenization::TokenType::MULTIPLICATION,
      Tokenization::TokenType::DIVISION);
}

/*
Factor
    = Primary ("^" Factor)*
*/
double Parser::handleFactor()
{
  return handleBinaryExpression(
      [&]()
      { return handlePrimary(); },
      [&]()
      { return handleFactor(); },
      Tokenization::TokenType::EXPONENTIATION,
      Tokenization::TokenType::EXPONENTIATION);
}

/*
Primary
    = NUMBER
*/
double Parser::handlePrimary()
{
  if (lookahead.type == Tokenization::TokenType::PARENTHESIS_LEFT)
  {
    return handleParenthesizedExpression();
  }
  Tokenization::Token token = eat(Tokenization::TokenType::NUMBER);
  return std::stod(token.value);
}

/*
ParenthesizedExpression
    = "(" Expression ")"
*/
double Parser::handleParenthesizedExpression()
{
  eat(Tokenization::TokenType::PARENTHESIS_LEFT);
  double expression = handleExpression();
  eat(Tokenization::TokenType::PARENTHESIS_RIGHT);

  return expression;
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