#include <iostream>
#include <vector>

auto IsPeak(const std::vector<int> &arr, int index) -> bool {
  size_t const array_size = arr.size();

  // 判断 index 是否为峰值的条件
  return index >= 0 && index < array_size &&
         (index == 0 || arr[index] > arr[index - 1]) &&
         (index == array_size - 1 || arr[index] > arr[index + 1]);
}

auto IsSinglePeakSequence(const std::vector<int> &arr) -> bool {
  size_t const array_size = arr.size();

  // 找到峰值的位置
  int peak_index = -1;
  for (int i = 0; i < array_size; ++i) {
    if (IsPeak(arr, i)) {
      peak_index = i;
      break;
    }
  }

  // 如果没有找到峰值，或者峰值不唯一，则不是单峰数列
  if (peak_index == -1 || !IsPeak(arr, peak_index)) {
    return false;
  }

  // 检查峰值左右两边是否符合单峰数列的定义
  for (int i = 0; i < peak_index; ++i) {
    if (arr[i] >= arr[i + 1]) {
      return false;
    }
  }

  for (int i = peak_index + 1; i < array_size - 1; ++i) {
    if (arr[i] <= arr[i + 1]) {
      return false;
    }
  }

  return true;
}

auto main() -> int {
  // 示例：判断数列是否为单峰数列
  std::vector<int> const sequence = {1, 2, 3, 4, 5, 4, 3, 2, 1};

  if (IsSinglePeakSequence(sequence)) {
    std::cout << "是单峰数列" << std::endl;
  } else {
    std::cout << "不是单峰数列" << std::endl;
  }

  return 0;
}