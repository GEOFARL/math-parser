#pragma once

#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class FileReader
{
  fs::path filepath;

public:
  std::string readFile();
};