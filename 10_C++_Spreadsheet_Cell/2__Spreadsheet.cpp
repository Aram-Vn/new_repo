#include "1__Spreadsheet.h"
#include "3__SpreadsheetCell.h"
#include "algorithm"
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <string>

Spreadsheet::Spreadsheet() : m_col(0), m_row(0), m_col_cap(0), m_row_cap(0), m_arr(nullptr)
{
}

Spreadsheet::Spreadsheet(int new_row, int new_col)
    : m_row(new_row), m_col(new_col), m_row_cap(2 * m_row), m_col_cap(2 * m_col), m_arr(nullptr)
{
    m_arr = new SpreadsheetCell*[m_row_cap];

    for (int i = 0; i < m_row_cap; ++i)
    {
        m_arr[i] = new SpreadsheetCell[m_col_cap];
    }
}

Spreadsheet::~Spreadsheet()
{
    for (int i = 0; i < m_col_cap; ++i)
    {
        delete[] m_arr[i];
    }

    delete[] m_arr;
    m_arr = nullptr;
    m_row = 0;
    m_row_cap = 0;
    m_col = 0;
    m_col_cap = 0;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& other)
{
    if (this != &other) {
        for(int i = 0; i < this->m_row_cap; ++i)
        {
            delete [] this->m_arr[i];
        }
        delete [] this->m_arr;

        this->m_row = other.m_row;
        this->m_col = other.m_col;
        this->m_row_cap = other.m_row_cap;
        this->m_col_cap = other.m_col_cap;

        this->m_arr = new SpreadsheetCell*[this->m_row_cap];

        for (int i = 0; i < this->m_row_cap; ++i)
        {
            this->m_arr[i] = new SpreadsheetCell[this->m_col_cap];
        }

        for (int i = 0; i < m_row; ++i)
        {
            for (int j = 0; j < m_col; ++j)
            {
                m_arr[i][j] = other.m_arr[i][j];
            }
        }
    }

    return *this;
}

Spreadsheet& Spreadsheet::operator= (Spreadsheet&& other) noexcept
{
    if(this != &other)
    {
        for (int i = 0; i < this->m_row_cap; ++i)
        {
            delete[] this->m_arr[i];
        }
        delete[] this->m_arr;

        this->m_row = other.m_row;
        this->m_col = other.m_col;
        this->m_row_cap = other.m_row_cap;
        this->m_col_cap = other.m_col_cap;
        this->m_arr = other.m_arr;

        other.m_row = 0;
        other.m_col = 0;
        other.m_row_cap = 0;
        other.m_col_cap = 0;
        other.m_arr = nullptr;
    }

    return *this;
}

std::string Spreadsheet::operator[] (int row)
{
    return m_arr[row]->getStringValue();
}

std::string Spreadsheet::operator()(int row, int col)
{
   return m_arr[row][col].getStringValue(); 
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
