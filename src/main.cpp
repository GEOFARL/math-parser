#include <iostream>
#include <string>

#include "MathInterpreter.hpp"

namespace fs = std::filesystem;

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <filepath>" << endl;
    return 1;
  }
  try
  {
    MathInterpreter interpreter{argv[1]};
    double result = interpreter.interpret();
    cout << "result: " << result << endl;
  }
  catch (const exception &e)
  {
    cerr << e.what() << endl;
  }
  return 0;
}