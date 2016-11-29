cmake_minimum_required(VERSION 3.6)
project(CList)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror") # -Wall -Werror

add_subdirectory(src)
#add_subdirectory(test)