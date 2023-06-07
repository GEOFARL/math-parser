#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class FileOpenException : public std::exception
{
public:
  FileOpenException(std::string);
  const char *what() const noexcept override;
};
