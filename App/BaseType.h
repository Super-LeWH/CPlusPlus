#pragma

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class BaseType {
  friend void display(BaseType &obj); // 声明友元函数
private:
  /* data */

public:
  BaseType(/* args */);
  ~BaseType();

  void ShowData();
  int add(int a, int b) { return a + b; }
  double add(double a, double b) { return a + b; }
  template <typename T> T add(T a, T b) { return a + b; }
  void STLType();

private:
  int a;
  short b;
  long c;
  long long d;
  unsigned e;
  float e1;
  double e2;
  long double e3;
  char c1;
  wchar_t c2;
  bool yesOrNo;

  // 复合数据类型
  int arr[5];
  struct Person {
    /* data */
    char *name;
    int age;
  };
  union Data {
    /* data */
    int i;
    float f;
  };
  enum Color { Red, Green, Blue };

  template <typename T> using Vec = std::vector<T>;
};

BaseType::BaseType(/* args */) {
  cout << add<int>(3, 5) << endl;        // 指定类型为 int，输出：8
  cout << add<double>(2.5, 3.8) << endl; // 指定类型为 double，输出：6.3
  Vec<int> number = {1, 2, 3, 4, 5};
}

BaseType::~BaseType() {}

void display(BaseType &obj) {
  std::cout << obj.Blue << std::endl;

  try {
    if (obj.a == 0)
      throw "Division by zero!";
  } catch (const char *msg) {
    cout << msg << endl;
  }

  enum class Color : int { Red = 1, Green = 2, Blue = 4 };
  Color myColor = Color::Red;

  // 定义 Lambda 表达式
  auto sum = [](int a, int b) { return a + b; };
  // 调用 Lambda 函数
  int result = sum(10, 20);
  // 输出结果
  cout << "Sum: " << result << endl; // 输出 30

  vector<int> nums = {4, 2, 8, 1, 5};
  // 使用 Lambda 表达式作为排序条件
  // /*std::sort
  //  * 的第三个参数定义了排序的逻辑，允许你根据具体需求自定义排序规则。如果不指定，则会使用默认的升序排序规则（基于
  //  * < 运算符）。*/
  // std::sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
  // 输出排序后的结果
  for (int num : nums) {
    cout << num << " ";
  }
  // cout << endl; // 输出：1 2 4 5 8
}
