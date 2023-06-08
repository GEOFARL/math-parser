#pragma once

#include <string>
#include "Tokenization.hpp"

class Parser
{
public:
  Parser() = default;

  double parse(const std::string &);

private:
  double handleExpression();
  double handlePrimary();
};