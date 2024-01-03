#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <iostream>
#include <vector>
#include "3__SpreadsheetCell.h"

class Spreadsheet
{
public:
    Spreadsheet();
    ~ Spreadsheet();
    Spreadsheet(int new_row, int new_col);

    Spreadsheet& operator= (const Spreadsheet& other);
    Spreadsheet& operator= (Spreadsheet&& other) noexcept;

    Spreadsheet operator+ (const Spreadsheet& other);
    Spreadsheet* operator[] (int row); // ??
    Spreadsheet& operator[] (const SpreadsheetCell& obj); // ??
    
public:
    void addRow(int row_amount);
    void addColumn(int collimn_ammount);
    void removeRow(int row_ind);
    void removeColumn(int Column_ind);
    const SpreadsheetCell& getCell(int row, int col);
    void setCell (int row, int col, std::string str);
    void print();

private:
    void realoc(int ammount = 0);

private:
    int m_row;
    int m_col;
    int m_row_cap;
    int m_col_cap;
    SpreadsheetCell** m_arr;
};

std::ostream& operator<<(std::ostream& os, const Spreadsheet& obj);

#endif //SPREADSHEET_H