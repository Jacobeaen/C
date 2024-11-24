cmake_minimum_required(VERSION 3.10) 
project(Sorts) 

set(CMAKE_C_STANDARD 11)

include_directories(lab4 /general_functions /merge_sort /choice_sort)
add_executable(Sorts main.c general_functions/general_funcs.c merge_sort/merge_funcs.c choice_sort/choice_funcs.c)