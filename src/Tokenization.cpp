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

  bool Tokenizer::hasMoreTokens()
  {
    return cursor < input.length();
  }

  Token Tokenizer::getNextToken()
  {
    if (!hasMoreTokens())
    {
      return Token(TokenType::EMPTY, "");
    }

    std::string inputSlice = input.substr(cursor);
    for (const auto &spec : TokenSpec)
    {
      // need to match a regex to a next token
    }
  }
}