#include "MathInterpreter.hpp"

MathInterpreter::MathInterpreter(const char *filepath)
    : reader{fs::path{std::string{filepath}}}
{
}

double MathInterpreter::interpret()
{
  std::string content = reader.readFile();
  return 0;
}