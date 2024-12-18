#pragma

#include <iostream>
#include <string>

class ClassType {
private:
  /* data */
public:
  ClassType(/* args */);
  ~ClassType();

  virtual void draw() { std::cout << "Drawing shape" << std::endl; }
};

ClassType::ClassType(/* args */) {}

ClassType::~ClassType() {}

class Circle : public ClassType {
private:
  /* data */
  void draw() override { std::cout << "Drawing Circle" << std::endl; }

public:
  Circle(/* args */);
  ~Circle();
};

Circle::Circle(/* args */) {}

Circle::~Circle() {}
