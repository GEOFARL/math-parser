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
    std::string error_message{"Error opening " + std::string(filepath.filename().c_str()) + "\n"};
    error_message += "File path " + std::string((fs::current_path() /= filepath).c_str()) + " does not exist";
    throw std::runtime_error(error_message);
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
