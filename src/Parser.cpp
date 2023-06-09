#include "Parser.hpp"

Parser::Parser(const std::string &input)
    : input{input}, tokenizer{input}, top{nullptr}
{
  lookahead = tokenizer.getNextToken();
}

ASTNode *Parser::parse()
{
  top = handleExpression();
  return top;
}

Parser::~Parser()
{
  delete top;
}

ASTNode *Parser::handleBinaryExpression(std::function<ASTNode *()> leftRule, std::function<ASTNode *()> rightRule, Tokenization::TokenType operatorType1, Tokenization::TokenType operatorType2)
{
  ASTNode *left = leftRule();

  while (lookahead.type == operatorType1 || lookahead.type == operatorType2)
  {
    std::string operatorValue = eat(lookahead.type).value;
    ASTNode *right = rightRule();
    ASTNode *binaryExpressionNode = new ASTNode();
    binaryExpressionNode->type = Tokenization::TokenType::BINARY_EXPRESSION;
    binaryExpressionNode->value = operatorValue;
    binaryExpressionNode->left = left;
    binaryExpressionNode->right = right;

    left = binaryExpressionNode;
  }

  return left;
}

/*
Expression
    = Term (("+" / "-") Term)*
*/
ASTNode *Parser::handleExpression()
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
ASTNode *Parser::handleTerm()
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
ASTNode *Parser::handleFactor()
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
    = ParenthesizedExpression
    / UnaryExpression
    / NUMBER
*/
ASTNode *Parser::handlePrimary()
{
  if (lookahead.type == Tokenization::TokenType::PARENTHESIS_LEFT)
  {
    return handleParenthesizedExpression();
  }

  if (lookahead.type == Tokenization::TokenType::SUBTRACTION)
  {
    return handleUnaryExpression();
  }
  Tokenization::Token token = eat(Tokenization::TokenType::NUMBER);

  ASTNode *numberNode = new ASTNode();
  numberNode->type = Tokenization::TokenType::NUMBER;
  numberNode->value = token.value;

  return numberNode;
}

/*
ParenthesizedExpression
    = "(" Expression ")"
*/
ASTNode *Parser::handleParenthesizedExpression()
{
  eat(Tokenization::TokenType::PARENTHESIS_LEFT);
  ASTNode *expression = handleExpression();
  eat(Tokenization::TokenType::PARENTHESIS_RIGHT);

  return expression;
}

/*
UnaryExpression
    = "-" Factor
*/
ASTNode *Parser::handleUnaryExpression()
{
  eat(Tokenization::TokenType::SUBTRACTION);
  ASTNode *factor = handleFactor();
  ASTNode *unaryExpressionNode = new ASTNode();
  unaryExpressionNode->type = Tokenization::TokenType::UNARY_EXPRESSION;
  unaryExpressionNode->value = "-";
  unaryExpressionNode->left = factor;
  return unaryExpressionNode;
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