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

  std::string Tokenizer::match(const std::regex &regex, const std::string &inputSlice)
  {
    std::smatch matched;
    if (!std::regex_search(inputSlice, matched, regex))
    {
      return "";
    }

    cursor += matched[0].length();
    return matched[0].str();
  }

  Token Tokenizer::getNextToken()
  {
    if (!hasMoreTokens())
    {
      return Token();
    }

    std::string inputSlice = input.substr(cursor);
    for (const auto &spec : TokenSpec)
    {
      const std::string tokenValue = match(spec.first, inputSlice);

      if (tokenValue.empty())
      {
        continue;
      }

      TokenType type = spec.second;
      if (type == TokenType::EMPTY)
      {
        return getNextToken();
      }

      return Token(type, tokenValue);
    }

    throw UnexpectedTokenException(std::string("Unexpected token: \"" + std::string(1, inputSlice[0]) + "\""));
  }

  std::string Tokenizer::getTokenTypeString(TokenType tokenType)
  {
    switch (tokenType)
    {
    case TokenType::NUMBER:
      return "NUMBER";
    case TokenType::IDENTIFIER:
      return "IDENTIFIER";
    case TokenType::ADDITION:
      return "ADDITION";
    case TokenType::SUBTRACTION:
      return "SUBTRACTION";
    case TokenType::MULTIPLICATION:
      return "MULTIPLICATION";
    case TokenType::DIVISION:
      return "DIVISION";
    case TokenType::EXPONENTIATION:
      return "EXPONENTIATION";
    case TokenType::PARENTHESIS_LEFT:
      return "PARENTHESIS_LEFT";
    case TokenType::PARENTHESIS_RIGHT:
      return "PARENTHESIS_RIGHT";
    case TokenType::EMPTY:
      return "EMPTY";
    default:
      return "";
    }
  }
}