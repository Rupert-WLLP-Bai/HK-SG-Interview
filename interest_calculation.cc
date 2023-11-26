#include <cmath>
#include <iostream>


auto main() -> int {
  // 给定的数据
  double const principal = 10000.0;         // 本金
  double const annual_interest_rate = 0.04; // 年利率
  int const number_of_years = 10;           // 年数

  // 单利
  double const simple_interest =
      principal * (1 + annual_interest_rate * number_of_years);

  // 复利，假设每年复利一次
  double const compound_interest =
      principal * std::pow(1 + annual_interest_rate, number_of_years);

  // 月复利，假设每月复利一次
  double const monthly_compound_interest =
      principal * std::pow(1 + annual_interest_rate / 12, 12 * number_of_years);

  // 输出结果
  std::cout << "单利十年后总金额：" << simple_interest << std::endl;
  std::cout << "复利十年后总金额：" << compound_interest << std::endl;
  std::cout << "月复利十年后总金额：" << monthly_compound_interest << std::endl;

  return 0;
}
