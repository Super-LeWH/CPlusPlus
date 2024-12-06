#pragma

#include <iostream>
class CreateError {
private:
  /* data */

public:
  int _myDenominator;

public:
  CreateError(/* args */);
  ~CreateError();

  void funcA() { funcB(); }

  void funcB() { funcC(); }

  void funcC() {
    int x = 10 / _myDenominator; // 这里发生了除零错误
  }
};

CreateError::CreateError(/* args */) {}

CreateError::~CreateError() {}
