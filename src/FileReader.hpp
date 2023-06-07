#pragma once

#include <fstream>
#include <string>
#include <filesystem>
#include <stdexcept>

namespace fs = std::filesystem;

class FileReader
{
  fs::path filepath;

public:
  FileReader(fs::path);
  std::string readFile();
};