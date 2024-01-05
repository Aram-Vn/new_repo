#include "1__Spreadsheet.h"
#include "3__SpreadsheetCell.h"
#include <iostream>
#include <sstream>

int main()
{
    Spreadsheet s(2, 2);

    int k = 0;

    s.addRow(2);
    s.addColumn(10);

    // int f = s.get_col();
    // int l = s.get_row();

    // s[2][2] = 5;

    for (int i = 0; i < s.get_row(); ++i)
    {
        for (int j = 0; j < s.get_col(); ++j)
        {
            s[i][j] = k;
            ++k;
            // std::cout << k << std::endl;
        }
    }

    std::cout << s << std::endl;
    
    int f = s.get_col();
    int l = s.get_row();
}