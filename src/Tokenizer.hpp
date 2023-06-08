#pragma once

#include <vector>
#include <string>

enum class TokenType
{
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
};

class Tokenizer
{
};