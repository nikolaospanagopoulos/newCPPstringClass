#include "NewString.h"
#include <iostream>
#include <vector>

int main() {

  // empty constructor called
  NewString firstStringEmpty;

  // overloaded constructor called
  NewString nameString{"Nikos"};

  // copy constructor called
  NewString copiedString{nameString};

  std::vector<NewString> NewStringVector{};

  // move constructor called
  NewStringVector.push_back(NewString{"nikolis"});

  nameString.display();

  // show string length
  std::cout << "the length of the string " << nameString.getStr() << " is "
            << nameString.getLength() << std::endl;

  // test copy overloaded =

  NewString surnameString;
  surnameString = nameString;

  // test move assignment

  nameString = NewString{"new for empty"};

  // test new << operator

  std::cout << nameString << std::endl;

  // test new >> operator

  NewString myWholeName;

  std::cout << "type your name" << std::endl;
  std::cin >> myWholeName;
  std::cout << myWholeName << std::endl;
  return 0;
}
