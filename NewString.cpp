#include "NewString.h"
#include <cstring>
#include <iostream>
// no args constructor
NewString::NewString() : str{nullptr} {

  str = new char[1];
  *str = '\0';
}

NewString::~NewString() { delete[] str; }

// overloaded constructor
NewString::NewString(const char *s) : str{nullptr} {
  if (s == nullptr) {
    str = new char[1];
    *str = '\0';
  } else {

    str = new char[std::strlen(s) + 1];

    std::strcpy(str, s);
  }
  std::cout << "overloaded constructor called" << std::endl;
}

// copy constructor

NewString::NewString(const NewString &source) : str{nullptr} {

  str = new char[std::strlen(source.str) + 1];

  std::strcpy(str, source.str);

  std::cout << "Copy constructor called" << std::endl;
}

// move constructor
NewString::NewString(NewString &&source) : str{source.str} {

  source.str = nullptr;

  std::cout << "Move constructor called" << std::endl;
}

void NewString::display() const {

  std::cout << "The string has the value " << this->str << std::endl;
}

int NewString::getLength() const { return std::strlen(this->str); }

const char *NewString::getStr() const { return this->str; }

// overload assignment operator to copy

NewString &NewString::operator=(const NewString &rhs) {

  if (this == &rhs) {

    return *this;
  }

  str = new char[std::strlen(rhs.str) + 1];

  std::strcpy(str, rhs.str);

  std::cout << "copy assignment" << std::endl;
  return *this;
}

// overload assignment to move and not copy

NewString &NewString::operator=(NewString &&rhs) {

  if (this == &rhs) {

    return *this;
  }

  delete[] str;
  str = rhs.str;

  rhs.str = nullptr;

  std::cout << "move assignment used" << std::endl;
  return *this;
}

std::ostream &operator<<(std::ostream &os, const NewString &rhs) {
  os << rhs.str;

  return os;
}

std::istream &operator>>(std::istream &in, NewString &rhs) {

  // allocate memory for input stream;

  char *buff = new char[1000];

  in >> buff;

  rhs = NewString{buff};
  delete[] buff;

  return in;
}
