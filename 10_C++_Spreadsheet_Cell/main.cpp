#include <iostream>
#include "1__Spreadsheet.h"
#include "3__SpreadsheetCell.h"
#include <sstream>  

int main() {

    Spreadsheet s(5, 5);

    s[1][5] = 5;

    std::cout << s[1][5] << std::endl;

}