cmake_minimum_required(VERSION 3.12)

project(HK_SG_Interview)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 添加可执行文件并指定源代码
add_executable(interest_calculation interest_calculation.cc)
add_executable(peak_sequence peak_sequence.cc)
add_executable(pointer_example pointer_example.cc)
add_executable(reverse_string reverse_string.cc)
add_executable(is_special is_special.cc)