#include <iostream>
#include "1__Spreadsheet.h"
#include "3__SpreadsheetCell.h"
#include <sstream>  

int main() {

    SpreadsheetCell obj("5.55");

    ++obj;

    std::cout << obj;

}