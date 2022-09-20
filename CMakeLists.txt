cmake_minimum_required(VERSION 3.21)
project(Bucket_Sort C)

set(CMAKE_C_STANDARD 99)

add_executable(Bucket_Sort main.c bucket_sort.c bucket_sort.h)
