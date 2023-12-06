#include <cmath>
#include <iostream>

auto IsPerfect(int num) -> bool {
    int sum = 1; // Start with 1 as a factor

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }

    return sum == num;
}

auto FindKthPerfectNumber(int k) -> long long {
    int count = 0;
    long long num = 2; // Start with the first even perfect number

    while (count < k) {
        if (IsPerfect(num)) {
            ++count;
        }

        if (count < k) {
            num += 2; // Move to the next even number
        }
    }

    return num;
}

auto main() -> int {
    int k;
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    if (k <= 0) {
        std::cout << "Invalid input. Please enter a positive integer."
                  << std::endl;
    } else {
        long long result = FindKthPerfectNumber(k);
        std::cout << "The " << k << "th perfect number is: " << result
                  << std::endl;
    }

    return 0;
}
