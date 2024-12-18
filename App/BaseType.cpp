#pragma

#include "BaseType.h"
#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

static int globalVar = 0; // 仅在当前文件可见

void BaseType::ShowData() {
  Person p1;
  p1.age = 89;
  // p1.name = "uoadhsvf";
  Color colorMe = Blue;
  std::cout << p1.name << std::endl;

  for (int i = 0; i < 5; i++) {
    std::cout << i << "";
  }

  int i = 0;
  while (i < 5) {
    std::cout << i << "";
    i++;
  }

  int j = 0;
  do {
    std::cout << j << "";
    j++;
  } while (j < 5);

  if (p1.age > 100) {
    std::cout << "NIU" << std::endl;
  }

  if (a > 0) {

  } else {
  }

  if (a > 0) {

  } else if (a > 1) {

  } else if (a > 2) {

  } else {
  }

  switch (colorMe) {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    std::cout << "No Result" << std::endl;
  }
}

void BaseType::STLType() {
  std::vector<int> someNumber = {1, 2, 3, 4, 5};
  std::cout << someNumber[0] << std::endl;
  someNumber.push_back(10);
  for (auto item : someNumber) {
    std::cout << item << std::endl;
  }

  std::deque<int> deq = {1, 2, 3};
  deq.push_front(0);
  deq.push_back(4);
  deq.pop_back();

  std::list<int> lst = {1, 2, 3, 4}; // 初始化
  lst.push_front(0);                 // 在前面添加元素
  lst.push_back(5);                  // 在后面添加元素
  std::cout << "List elements: ";
  for (auto n : lst) {
    std::cout << n << " "; // 输出: 0 1 2 3 4 5
  }

  // std::array<int, 10> arr1 = {1, 2, 3, 4, 5}; // 初始化
  std::array<int, 3> a = {1, 2, 3};

  std::string str = "srgvwerg";
  str += "advsrgb";

  std::shared_ptr<int> sharedPtr =
      std::make_shared<int>(30); // 创建一个shared_ptr
  std::weak_ptr<int> weakPtr =
      sharedPtr; // 创建一个 weak_ptr，指向 shared_ptr管理的对象
  std::cout << "sharedPtr use_count: " << sharedPtr.use_count() << std::endl;
  // 输出：sharedPtr use_count: 1
  // weak_ptr 不增加引用计数
  /*
  为什么需要 lock()？
由于 weak_ptr
本身不拥有对象（它只是观察者，不影响对象的引用计数），不能直接访问对象；通过
lock()，可以安全地检查对象是否仍然有效，并在需要时获取对对象的临时所有权。
  */
  if (auto tempPtr = weakPtr.lock()) { // weak_ptr.lock() 返回 shared_ptr
    std::cout << "weakPtr is valid: " << *tempPtr
              << std::endl; // 输出：weakPtr is valid : 30
  } else {
    std::cout << "weakPtr is invalid." << std::endl;
  }
}
