#pragma once

#include <unordered_map>
#include <string>
#include "FileReader.hpp"

class MathInterpreter
{
  std::unordered_map<std::string, double> variables;
  FileReader reader;

public:
  MathInterpreter() = default;
  double interpret(const std::string &);
};
