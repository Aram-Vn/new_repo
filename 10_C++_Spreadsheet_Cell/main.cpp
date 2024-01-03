#include <iostream>
#include "1__Spreadsheet.h"
#include "3__SpreadsheetCell.h"
#include <sstream>  

int main() {

    SpreadsheetCell obj("555");

    obj--;

    std::cout << obj;

}