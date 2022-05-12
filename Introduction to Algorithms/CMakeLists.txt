cmake_minimum_required(VERSION 3.20)
project(Introduction_to_Algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(Introduction_to_Algorithms main.cpp)

add_executable(InsertionSort "Ch2 Getting Started/InsertionSort.cpp")
add_executable(MergeSort "Ch2 Getting Started/MergeSort.cpp")
add_executable(MaxSubArraySum "Ch4 Devide-and-Conquer/MaxSubArraySum.cpp")
add_executable(HeapSort "Ch6 Heapsort/HeapSort.cpp")
add_executable(QuickSort "Ch7 Quicksort/QuickSort.cpp")