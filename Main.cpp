#include <future>
#include <iostream>
#include <thread>

#include <AllInOne.h>

// #include "BaseType.cpp"
// #include "CreateError.h"
// #include "ModulesType.h"
// #include "STLModule.h"

// void print_hello() { std::cout << "Hello from thread!" << std::endl; }
// // 线程要执行的函数，带有一个整数参数
// void print_square(int x) {
//   std::cout << "Square of " << x << " is " << x * x << std::endl;
// }
// // 线程要执行的函数，返回一个整数值
// int calculate_square(int x) { return x * x; }
// // 线程要执行的函数，打印当前线程的编号
// void print_thread_id(int id) {
//   std::cout << "Hello from thread " << id << std::endl;
// }
int shard = 0;

void incrment() { shard++; };
void derment() { shard--; };
int main() {
  std::thread t1(incrment);
  std::thread t2(derment);
  t1.join();
  t2.join();
  std::cout << "shard:" << shard << std::endl;
  // std::cout << "STLModule" << std::endl;
  // STLModule sTLModule;
  // sTLModule.InlineAdd();
  // std::cout << "STLModule" << std::endl;

  // // std::cout << std::endl;
  // // std::cout << "CreateError" << std::endl;
  // // CreateError createError;
  // // createError._myDenominator = 0;
  // // createError.funcA();
  // // std::cout << "CreateError" << std::endl;

  // std::cout << std::endl;
  // std::cout << "BaseType" << std::endl;
  // BaseType baseType;
  // baseType.ShowData();
  // std::cout << "BaseType" << std::endl;

  // std::cout << std::endl;
  // std::cout << "ModulesType" << std::endl;
  // ModulesType modulesType;

  // try {
  //   modulesType.riskyFunction();
  // } catch (const std::exception &e) {
  //   std::cout << "Exception caught: " << e.what() << std::endl; //
  //   打印异常信息
  // }

  // // 创建一个线程，执行 print_hello 函数
  // std::thread t(print_hello);
  // // 等待线程执行完毕
  // t.join();
  // // 主线程继续执行
  // std::cout << "Hello from main!" << std::endl;

  // // 创建一个线程，并传递参数 5
  // std::thread t12(print_square, 5);
  // // 等待线程执行完毕
  // t12.join();

  // // 使用 std::async 启动异步任务，返回一个 std::future
  // std::future<int> result =
  //     std::async(std::launch::async, calculate_square, 10);
  // // 获取结果
  // std::cout << "Square of 10 is: " << result.get() << std::endl;

  // // 创建多个线程
  // std::thread t1(print_thread_id, 1);
  // std::thread t2(print_thread_id, 2);
  // std::thread t3(print_thread_id, 3);
  // // 等待所有线程执行完毕
  // t1.join();
  // t2.join();
  // t3.join();

  // std::cout << "ModulesType" << std::endl;
}