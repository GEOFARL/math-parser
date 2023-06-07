#include "FileReader.hpp"

FileReader::FileReader(fs::path path) : filepath{path}
{
}

std::string FileReader::readFile()
{
  std::ifstream infile(filepath);
  if (!infile)
  {
    // TO DO: Custom exception
    throw std::runtime_error("Error opening " + std::string(filepath.c_str()));
  }

  std::string fileContent{};
  std::string line{};

  while (std::getline(infile, line))
  {
    fileContent += line + '\n';
  }

  infile.close();

  return fileContent;
}
