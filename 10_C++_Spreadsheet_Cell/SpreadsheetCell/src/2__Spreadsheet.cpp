#include "1__Spreadsheet.h"
#include "3__SpreadsheetCell.h"
#include "algorithm"
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <string>

//----------------------------_Default_Constructor_---------------------------//
Spreadsheet::Spreadsheet() : m_col(0), m_row(0), m_col_cap(0), m_row_cap(0), m_arr(nullptr)
{
}

//----------------------------_Parameterized_Constructor-------------------------//
Spreadsheet::Spreadsheet(int new_row, int new_col)
    : m_row(new_row), m_col(new_col), m_row_cap(2 * m_row), m_col_cap(2 * m_col), m_arr(nullptr)
{
    m_arr = new SpreadsheetCell*[m_row_cap];

    for (int i = 0; i < m_row_cap; ++i)
    {
        m_arr[i] = new SpreadsheetCell[m_col_cap];
    }
}

//-------------------------------_Destructor_------------------------------------//
Spreadsheet::~Spreadsheet()
{
    for (int i = 0; i < m_row_cap; ++i)
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

//-----------------------_Copy_Assignment_Operator_--------------------------//
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& other)
{
    if (this != &other)
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

//---------------------_Move_Assignment_Operator_----------------------//
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& other) noexcept
{
    if (this != &other)
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

//------------------------_Subscript_Operator_--------------------------//
SpreadsheetCell* Spreadsheet::operator[](int row) const
{
    return m_arr[row];
}

std::string Spreadsheet::operator()(int row, int col) const
{
    return m_arr[row][col].getStringValue();
}

//------------------------_geters_---------------------------------//
int Spreadsheet::get_row() const
{
    return m_row;
}

int Spreadsheet::get_col() const
{
    return m_col;
}

const SpreadsheetCell& Spreadsheet::getCell(int row, int col) const
{
    return m_arr[row][col];
}

//----------------------------_setters_----------------------------------//
void Spreadsheet::setCell(int row, int col, const char* str)
{
    m_arr[row][col].setStringValue(str);
}

//------------------------_addRow_---------------------------------------//
void Spreadsheet::addRow(int row_amount)
{
    if (m_row + row_amount >= m_row_cap)
    {
        if (m_row + row_amount > 2 * m_row_cap)
        {
            realoc_row(m_row + row_amount + 10);
        }
        else
        {
            realoc_row();
        }
    }

    for (int i = m_row; i < m_row + row_amount; ++i)
    {
        for (int j = 0; j < m_col; ++j) {
            m_arr[i][j].setStringValue("");
        }
    }

    m_row += row_amount;
}

//-------------------------_addColumn_----------------------------------//
void Spreadsheet::addColumn(int collimn_ammount)
{
    if (m_col + collimn_ammount >= m_col_cap)
    {
        if (m_col + collimn_ammount > 2 * m_col_cap)
        {
            realoc_col(m_row + collimn_ammount + 10);
        }
        else
        {
            realoc_col();
        }
    }

    for (int i = 0; i < m_row; ++i)
    {
        for (int j = m_col; j < m_col + collimn_ammount; ++j)
        {
            m_arr[i][j].setStringValue("");
        }
    }

    m_col += collimn_ammount;
}

//---------------------------_removeRow_-------------------------------//
void Spreadsheet::removeRow(int row_amount)
{
    if (m_row < row_amount)
    {
        std::cout << "for removeRow\ncan't remowe\nrow_amount > m_row" << std::endl;
        return;
    }

    m_row -= row_amount;
}

//---------------------------_removeColumn_-----------------------------//
void Spreadsheet::removeColumn(int collumn_ammount)
{
    if (m_col < collumn_ammount)
    {
        std::cout << "for removeColumn\ncan't remowe\n collumn_ammount > m_col" << std::endl;
        return;
    }

    m_col -= collumn_ammount;
}

//---------------------------_Output_operator_-------------------------//
std::ostream& operator<<(std::ostream& os, const Spreadsheet& obj)
{
    for (int i = 0; i < obj.get_row(); ++i)
    {
        for (int j = 0; j < obj.get_col(); ++j)
        {
            os << obj[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return os;
}

// private helper functions for reallocating memory by doubling
//------------------------_realocators_------------------------------------//
void Spreadsheet::realoc_row(int ammount)
{
    if (ammount == 0)
    {
        m_row_cap = (m_row_cap) ? 2 * m_row_cap : 1;
    }
    else
    {
        m_row_cap = ammount;
    }

    SpreadsheetCell** tmp_arr = new SpreadsheetCell*[m_row_cap];
    for (int i = 0; i < m_row_cap; ++i)
    {
        tmp_arr[i] = new SpreadsheetCell[m_col_cap];
    }

    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < m_col; ++j)
        {
            tmp_arr[i][j] = m_arr[i][j];
        }
    }

    for (int i = 0; i < m_row; ++i)
    {
        delete[] m_arr[i];
    }

    delete[] m_arr;

    m_arr = tmp_arr;
}

void Spreadsheet::realoc_col(int ammount)
{
    if (ammount == 0)
    {
        m_col_cap = (m_col_cap) ? 2 * m_col_cap : 1;
    }
    else
    {
        m_col_cap = ammount;
    }

    SpreadsheetCell** tmp_arr = new SpreadsheetCell*[m_row_cap];
    for (int i = 0; i < m_row_cap; ++i)
    {
        tmp_arr[i] = new SpreadsheetCell[m_col_cap];
    }

    for (int i = 0; i < m_row_cap; ++i)
    {
        for (int j = 0; j < m_col; ++j)
        {
            tmp_arr[i][j] = m_arr[i][j];
        }
    }

    for (int i = 0; i < m_row_cap; ++i)
    {
        delete[] m_arr[i];
    }
    delete[] m_arr;

    m_arr = tmp_arr;
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
