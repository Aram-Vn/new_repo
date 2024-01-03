# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)

project(SpreadsheetProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    1__Spreadsheet.h
    2__Spreadsheet.cpp
    3__SpreadsheetCell.h
    4__SpreadsheetCell.cpp
    main.cpp
)

# Create an executable
add_executable(SpreadsheetExecutable ${SOURCES})

# Export compile commands for external tools
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
