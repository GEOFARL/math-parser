#include "Parser.hpp"

double Parser::parse(const std::string &inputString)
{
  std::string input{inputString};
  Tokenization::Tokenizer tokenizer{inputString};
  Tokenization::Token lookahead{tokenizer.getNextToken()};

  return handleExpression();
}