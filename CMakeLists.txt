cmake_minimum_required(VERSION 3.23)
project(algos_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(algos_cpp merge_sort.cpp Treap.cpp segment_tree.cpp line-crossing.cpp k_st_bor.cpp strongly-connected.cpp vec-rotation.cpp sqare_polygon.cpp ray-shooting.cpp segment-crossing.cpp djkstra.cpp segment_tree_it.cpp)
