#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <iostream>
#include <vector>
#include "3__SpreadsheetCell.h"

class Spreadsheet
{
public:
    Spreadsheet(); //
    ~ Spreadsheet(); //
    Spreadsheet(int new_row, int new_col); // 

    Spreadsheet& operator= (const Spreadsheet& other); //
    Spreadsheet& operator= (Spreadsheet&& other) noexcept; //

    Spreadsheet operator+ (const Spreadsheet& other);
    SpreadsheetCell* operator[] (int row) const ; //
    std::string operator() (int row, int col) const ;   //
    

public:
    int get_row() const; //
    int get_col() const; //
    const SpreadsheetCell& getCell(int row, int col) const;//
    void setCell (int row, int col, const char* str); //
    
    void addRow(int row_amount); //
    void addColumn(int collumn_ammount); //
    void removeRow(int row_ind); //
    void removeColumn(int Column_ind); //
    void print();

private:
    void realoc_row(int ammount = 0); //
    void realoc_col(int ammount = 0); //

private:
    int m_row;
    int m_col;
    int m_row_cap;
    int m_col_cap;
    SpreadsheetCell** m_arr;
};

std::ostream& operator<<(std::ostream& os, const Spreadsheet& obj);

#endif //SPREADSHEET_H