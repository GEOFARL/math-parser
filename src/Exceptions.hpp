#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class FileOpenException : public std::exception
{
  std::string message;

public:
  FileOpenException(const std::string &);
  const char *what() const noexcept override;
};

class UnexpectedTokenException : public std::exception
{
  std::string message;

public:
  UnexpectedTokenException(const std::string &);
  const char *what() const noexcept override;
};
