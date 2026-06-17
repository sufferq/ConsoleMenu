cmake_minimum_required(VERSION 3.10)
project(ConsoleLib)

set(CMAKE_CXX_STANDARD 11)

# Библиотека
add_library(console_menu STATIC console_menu.cpp)

# Тесты
add_executable(tests test.cpp)
target_link_libraries(tests console_menu)

# Главная программа
add_executable(main main.cpp)
target_link_libraries(main console_menu)