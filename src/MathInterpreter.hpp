#pragma once

#include <unordered_map>
#include <iostream>
#include <string>
#include <filesystem>

#include "FileReader.hpp"
#include "Tokenization.hpp"

namespace fs = std::filesystem;

class MathInterpreter
{
  std::unordered_map<std::string, double> variables;
  FileReader reader;

public:
  MathInterpreter(const char *);
  double interpret();
};
