#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <iostream>
#include <vector>
#include "3__SpreadsheetCell.h"

class Spreadsheet
{
public:
    Spreadsheet();
    Spreadsheet(int new_row, int new_col);

public:


private:
    int m_row;
    int m_col;
    std::vector<std::vector<SpreadsheetCell>> m_arr;
};

#endif //SPREADSHEET_H