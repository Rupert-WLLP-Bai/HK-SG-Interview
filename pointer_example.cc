#include <iostream>

auto main() -> int {
  // 声明一个整数变量
  int number = 42;

  // 声明一个指向整数的指针，并初始化为整数变量的地址
  int *pointer = &number;

  // 输出整数变量的值和地址
  std::cout << "整数变量的值: " << number << std::endl;
  std::cout << "整数变量的地址: " << &number << std::endl;

  // 输出指针指向的值和地址
  std::cout << "指针指向的值: " << *pointer << std::endl;
  std::cout << "指针的地址: " << pointer << std::endl;

  // 修改指针指向的值
  *pointer = 99;

  // 再次输出整数变量的值，验证是否被修改
  std::cout << "修改后的整数变量的值: " << number << std::endl;

  return 0;
}
