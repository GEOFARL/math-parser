#include "MathInterpreter.hpp"

MathInterpreter::MathInterpreter(const char *filepath)
    : reader{fs::path{std::string{filepath}}}
{
}

double MathInterpreter::interpret()
{
  std::string content = reader.readFile();
  Tokenization::Tokenizer tokenizer(content);
  std::cout << tokenizer.getNextToken() << std::endl;
  std::cout << tokenizer.getNextToken() << std::endl;
  return 0;
}