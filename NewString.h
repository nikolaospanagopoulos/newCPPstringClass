#ifndef _NEWSTRING_
#define _NEWSTRING_

#include <iostream>
class NewString {

  friend std::ostream &operator<<(std::ostream &os, const NewString &rhs);
  friend std::istream &operator>>(std::istream &in, NewString &rhs);

private:
  char *str;

public:
  // constructor
  NewString();

  NewString(const char *s);

  NewString(const NewString &source);

  NewString(NewString &&source);

  ~NewString();

  // overload assignment operator = to copy

  NewString &operator=(const NewString &rhs);

  NewString &operator=(NewString &&rhs);
  void display() const;

  int getLength() const;

  const char *getStr() const;
};

#endif
