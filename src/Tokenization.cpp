#include "Tokenization.hpp"

namespace Tokenization
{
  const std::vector<std::pair<std::regex, TokenType>> TokenSpec = {
      {std::regex("^\\s+"), TokenType::EMPTY},
      {std::regex("^(?:\\d+(?:\\.\\d*)?|\\.\\d+)"), TokenType::NUMBER},
      {std::regex("^[a-z]+"), TokenType::IDENTIFIER},
      {std::regex("^\\+"), TokenType::ADDITION},
      {std::regex("^\\-"), TokenType::SUBTRACTION},
      {std::regex("^\\*"), TokenType::MULTIPLICATION},
      {std::regex("^\\/"), TokenType::DIVISION},
      {std::regex("^\\^"), TokenType::EXPONENTIATION},
      {std::regex("^\\("), TokenType::PARENTHESIS_LEFT},
      {std::regex("^\\)"), TokenType::PARENTHESIS_RIGHT}};

  Tokenizer::Tokenizer(const std::string &input)
      : input{input}, cursor{0}
  {
  }

  Token Tokenizer::getNextToken()
  {
    // check if there are any tokens left
  }
}