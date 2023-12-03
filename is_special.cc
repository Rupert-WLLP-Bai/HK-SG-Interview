#include <iostream>
#include <vector>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<std::pair<int, int>> find_prime_pairs(int num) {
    std::vector<std::pair<int, int>> prime_pairs;

    if (num < 4) {
        return prime_pairs;  // 2和3是最小的两个质数，小于4的数不满足条件
    }

    for (int f = 2; f * (f + 2) <= num; ++f) {
        if (is_prime(f) && is_prime(f + 2)) {
            if (num % f == 0 && num % (f + 2) == 0) {
                prime_pairs.push_back(std::make_pair(f, f + 2));
            }
        }
    }

    return prime_pairs;
}

int main() {
    const int lower_limit = 0;
    const int upper_limit = 5000;

    std::cout << "在范围 [" << lower_limit << ", " << upper_limit << "] 内满足条件的质数对：" << std::endl;

    for (int num_to_check = lower_limit; num_to_check <= upper_limit; ++num_to_check) {
        std::vector<std::pair<int, int>> result = find_prime_pairs(num_to_check);

        if (!result.empty()) {
            std::cout << num_to_check << ": ";
            for (const auto& pair : result) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
