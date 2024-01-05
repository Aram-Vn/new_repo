cmake_minimum_required(VERSION 3.10)
project(SpreadsheetCell)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# SpreadsheetCell sources
file(GLOB_RECURSE SRC_FILES
    "SpreadsheetCell/src/*.h"
    "SpreadsheetCell/src/*.cpp"
)

# Create the executable
add_executable(spreadsheet_app ${SRC_FILES})