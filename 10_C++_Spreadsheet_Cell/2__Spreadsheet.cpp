#include <algorithm>
#include <iostream>
#include "1__Spreadsheet.h"
#include "3__SpreadsheetCell.h"
#include "algorithm"

Spreadsheet::Spreadsheet() :
    m_col(0),
    m_row(0),
    m_col_cap(0),
    m_row_cap(0),
    m_arr(nullptr)
{}

Spreadsheet::Spreadsheet(int new_row, int new_col) :
    m_row_cap(new_row),
    m_col_cap(new_col),
    m_row(m_row_cap),
    m_col(m_col_cap)
{
    m_arr = new SpreadsheetCell* [m_row_cap];

    for (int i = 0; i < m_row_cap; ++i) {
        m_arr[i] = new SpreadsheetCell [m_col_cap];
    }    
}

/*
Spreadsheet Spreadsheet::operator+(const Spreadsheet &other) 
{
    Spreadsheet tmp(this->m_row_cap + other.m_row_cap, 
    std::max(this->m_col_cap, other.m_col_cap));

    int i = 0;
    int j = 0;
    
    for (int x = 0; x < this->m_row_cap; ++x) {
        for (int y = 0; y < this->m_col_cap; ++y) {
            tmp[i++][j++] = (*this)[x][y];           
        }
    }

    for (int x = 0; x < other.m_row_cap; ++x) {
        for (int y = 0; y < other.m_col_cap; ++y) {
            if(!y) = {j = 0}
                tmp[i++][j++] = other[x][y];           
        }
    }
    return tmp;      
}*/
