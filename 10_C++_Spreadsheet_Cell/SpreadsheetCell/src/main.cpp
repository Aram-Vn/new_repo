#include "1__Spreadsheet.h"
#include "3__SpreadsheetCell.h"
#include <iostream>
#include <ostream>
#include <sstream>

int main()
{
    Spreadsheet s(2, 2);

    int k = 0;

    s.addRow(5);
    s.addColumn(10);

    s[2][2] = 5;

    for (int i = 0; i < s.get_row(); ++i)
    {
        for (int j = 0; j < s.get_col(); ++j)
        {
            s[i][j] = k;
            ++k;
        }
    }

    std::cout << s;
    std::cout << "*****************" << std::endl;

    s.removeRow(2);
    s.removeColumn(2);
    std::cout << s;
    std::cout << "*****************" << std::endl;
   
    s.addColumn(2);
    s.addRow(2);
    std::cout << s;
    std::cout << "*****************" << std::endl;

    s.setCell(2, 2, "8.8"); 
    std::cout << s.getCell(2, 2) << std::endl;

}