#include <iostream>
#include <string>

auto main() -> int {
    std::string input;

    // 获取用户输入的字符串
    std::cout << "请输入一个字符串: ";
    std::getline(std::cin, input);

    // 计算字符串长度
    size_t const length = input.length();

    // 反转字符串
    for (size_t i = 0; i < length / 2; ++i) {
        std::swap(input[i], input[length - i - 1]);
    }

    // 输出反转后的字符串
    std::cout << "反转后的字符串: " << input << std::endl;

    return 0;
}
