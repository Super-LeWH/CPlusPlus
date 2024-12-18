#include <ModulesType.h>

void ModulesType::riskyFunction() {
  throw std::runtime_error(
      "Something went wrong!"); // 抛出 std::runtime_error类型的异常
}