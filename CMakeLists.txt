cmake_minimum_required(VERSION 3.20)
project(CLRS-III)

set(CMAKE_CXX_STANDARD 14)

add_executable(main "main.cpp")

add_executable(insertion_sort "src/ch2-getting-started/insertion_sort.cpp")
add_executable(merge_sort "src/ch2-getting-started/merge_sort.cpp")
add_executable(max_subarray_sum "src/ch4-divide-and-conquer/max_subarray_sum.cpp")
add_executable(heapsort "src/ch6-heapsort/heapsort.cpp")
add_executable(quicksort "src/ch7-quicksort/quicksort.cpp")
add_executable(rod_cutting "src/ch15-dynamic-programming/rod_cutting.cpp")
add_executable(bfs "src/ch22-elementary-graph-algorithms/bfs.cpp")
add_executable(dfs "src/ch22-elementary-graph-algorithms/dfs.cpp")

