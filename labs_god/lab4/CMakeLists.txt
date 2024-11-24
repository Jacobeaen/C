cmake_minimum_required(VERSION 3.10) 
project(Sorts) 

set(CMAKE_C_STANDARD 11)

set (main main.c)
set (general_funcs general_functions/general_funcs.c)
set (merge_funcs merge_sort/merge_funcs.c)
set (choice_funcs choice_sort/choice_funcs.c)
set (shell_funcs shell_sort/shell_funcs.c)

include_directories(lab4 /general_functions /merge_sort /choice_sort)
add_executable(Sorts ${main} ${general_funcs} ${merge_funcs} ${choice_funcs} ${shell_funcs})