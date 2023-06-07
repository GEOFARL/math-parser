#include <iostream>
#include <string>
#include <filesystem>

#include "FileReader.hpp"

namespace fs = std::filesystem;

using namespace std;

int main(int argc, char *argv[])
{
  string filename(argv[1]);
  fs::path path{filename};
  try
  {
    FileReader reader{path};
    string content = reader.readFile();
    cout << content;
  }
  catch (const exception &e)
  {
    cerr << e.what() << endl;
  }
  return 0;
}