cmake_minimum_required(VERSION 3.10)

# set the project name
project(ci_analysis_tools_testing)

# add the executable
add_executable(a.out main.c)

# specify the C++ standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
