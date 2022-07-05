cmake_minimum_required(VERSION 3.20)
project(introduction-to-algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(main "main.cpp")

add_executable(insertion_sort "ch2-getting-started/insertion_sort.cpp")
add_executable(merge_sort "ch2-getting-started/merge_sort.cpp")
add_executable(max_subarray_sum "ch4-devide-and-conquer/max_subarray_sum.cpp")
add_executable(heapsort "ch6-heapsort/heapsort.cpp")
add_executable(quicksort "ch7-quicksort/quicksort.cpp")
add_executable(rod_cutting "ch15-dynamic-programming/rod_cutting.cpp")
add_executable(bfs "ch22-elementary-graph-algorithms/bfs.cpp")
add_executable(dfs "ch22-elementary-graph-algorithms/dfs.cpp")