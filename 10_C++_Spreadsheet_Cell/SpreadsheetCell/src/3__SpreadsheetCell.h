#ifndef SPREADSHEETCELL_H
#define SPREADSHEETCELL_H

#include <exception>
#include <iostream>

class SpreadsheetCell
{
public:

    ~SpreadsheetCell() = default;
    SpreadsheetCell();                           //
    SpreadsheetCell(const std::string& new_str); //
    SpreadsheetCell(const int new_val);          //
    SpreadsheetCell(const double new_val);       //

    operator int();    //
    operator double(); //

    SpreadsheetCell& operator++();
    SpreadsheetCell operator++(int);

    SpreadsheetCell& operator--();
    SpreadsheetCell operator--(int);

public:
    void setStringValue(const char* new_val); //
    std::string getStringValue() const;       //

    const int getIntValue() const;       //
    const double getDoubleValue() const; //

private:
    std::string m_cell;
};

std::ostream& operator<<(std::ostream& os, const SpreadsheetCell& obj);

#endif // SPREADSHEETCELL_H