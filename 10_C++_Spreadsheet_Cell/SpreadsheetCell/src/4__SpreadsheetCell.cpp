#include "3__SpreadsheetCell.h"
#include <algorithm>
#include <sstream>
#include <string>

SpreadsheetCell::SpreadsheetCell() : m_cell("")
{
}

SpreadsheetCell::SpreadsheetCell(const std::string& new_str) : m_cell(new_str)
{
}

SpreadsheetCell::SpreadsheetCell(const int new_val)
{
    m_cell = std::to_string(new_val);
}

SpreadsheetCell::SpreadsheetCell(const double new_val)
{
    m_cell = std::to_string(new_val);
}

void SpreadsheetCell::setStringValue(const char* new_val)
{
    m_cell = new_val;
}

std::string SpreadsheetCell::getStringValue() const
{
    return m_cell;
}

const int SpreadsheetCell::getIntValue() const
{
    int num;

    std::stringstream ss(m_cell);
    ss >> num;

    if (ss.fail())
    {
        std::cout << "for getIntValue\nConversion failed: invalid format" << std::endl;
        return -1;
    }

    return num;
}

const double SpreadsheetCell::getDoubleValue() const
{
    double num;

    std::stringstream ss(m_cell);
    ss >> num;

    if (ss.fail())
    {
        throw std::runtime_error("for getDoubleValue\nConversion failed: invalid format");
    }

    return num;
}

SpreadsheetCell::operator int()
{
    return getIntValue();
}

SpreadsheetCell::operator double()
{
    try
    {
        double res = getDoubleValue();
        return res;
    }
    catch (std::exception& err)
    {
        std::cout << "for" << m_cell << std::endl;
        std::cout << err.what() << std::endl;
        exit(0);
    }
}

SpreadsheetCell& SpreadsheetCell::operator++()
{
    if (m_cell.find('.') != std::string::npos)
    {
        double d_num;
        std::stringstream ss(m_cell);
        ss >> d_num;

        if (!ss.fail())
        {
            ++d_num;
            m_cell = std::to_string(d_num);
            return *this;
        }
    }

    int i_num;
    std::stringstream ss(m_cell);
    ss >> i_num;

    if (!ss.fail())
    {
        ++i_num;
        m_cell = std::to_string(i_num);
        return *this;
    }

    std::cout << "can't ++" << std::endl;
    return *this;
}

SpreadsheetCell SpreadsheetCell::operator++(int)
{
    SpreadsheetCell tmp = *this;

    if (m_cell.find('.') != std::string::npos)
    {
        double d_num;
        std::stringstream ss(m_cell);
        ss >> d_num;

        if (!ss.fail())
        {
            ++d_num;
            m_cell = std::to_string(d_num);
            return tmp;
        }
    }

    int i_num;
    std::stringstream ss(m_cell);
    ss >> i_num;

    if (!ss.fail())
    {
        ++i_num;
        m_cell = std::to_string(i_num);
        return tmp;
    }

    std::cout << "can't ++" << std::endl;
    return *this;
}

SpreadsheetCell& SpreadsheetCell::operator--()
{
    if (m_cell.find('.') != m_cell.npos)
    {
        double d_num;
        std::stringstream ss(m_cell);
        ss >> d_num;

        if (!ss.fail())
        {
            --d_num;
            m_cell = std::to_string(d_num);
            return *this;
        }
    }

    int i_num;
    std::stringstream ss(m_cell);
    ss >> i_num;

    if (!ss.fail())
    {
        --i_num;
        m_cell = std::to_string(i_num);
        return *this;
    }

    std::cout << "SpreadsheetCell\ncan't --" << std::endl;
    return *this;
}

SpreadsheetCell SpreadsheetCell::operator--(int)
{
    SpreadsheetCell tmp = *this;

    if (m_cell.find('.') != m_cell.npos)
    {
        double d_num;
        std::stringstream ss(m_cell);
        ss >> d_num;

        if (!ss.fail())
        {
            --d_num;
            m_cell = std::to_string(d_num);
            return tmp;
        }
    }

    int i_num;
    std::stringstream ss(m_cell);
    ss >> i_num;

    if (!ss.fail())
    {
        --i_num;
        m_cell = std::to_string(i_num);
        return tmp;
    }

    std::cout << "SpreadsheetCell\ncan't ++" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SpreadsheetCell& obj)
{
    std::string val = obj.getStringValue();

    os << val;

    return os;
}