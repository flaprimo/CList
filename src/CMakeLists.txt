add_executable(CList main.c)

add_subdirectory(helper)

target_link_libraries (CList helper)