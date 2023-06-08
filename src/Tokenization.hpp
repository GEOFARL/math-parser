#pragma once

#include <vector>
#include <string>
#include <utility>
#include <regex>

namespace Tokenization
{
  enum class TokenType
  {
    EMPTY,
    NUMBER,
    IDENTIFIER,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    EXPONENTIATION,
    PARENTHESIS_LEFT,
    PARENTHESIS_RIGHT
  };

  struct Token
  {
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string &value) : type{type}, value{value} {}
  };

  extern const std::vector<std::pair<std::regex, TokenType>> TokenSpec;

  class Tokenizer
  {
    std::string input;
    std::size_t cursor;

  public:
    Tokenizer(const std::string &);

    Token getNextToken();

  private:
    bool hasMoreTokens();
  };
}