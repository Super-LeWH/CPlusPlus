#include <iostream>

#include "CreateError.h"
#include "STLModule.h"

int main() {
  std::cout << "STLModule" << std::endl;
  STLModule sTLModule;
  sTLModule.InlineAdd();
  std::cout << "STLModule" << std::endl;

  std::cout << "CreateError" << std::endl;
  CreateError createError;
  createError._myDenominator = 0;
  createError.funcA();
  std::cout << "CreateError" << std::endl;

  return 0;
}