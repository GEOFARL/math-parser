#include "Exceptions.hpp"

FileOpenException::FileOpenException(const std::string &message) : message{message}
{
}

const char *FileOpenException::what() const noexcept
{
  return message.c_str();
}

UnexpectedTokenException::UnexpectedTokenException(const std::string &message) : message{message}
{
}

const char *UnexpectedTokenException::what() const noexcept
{
  return message.c_str();
}
