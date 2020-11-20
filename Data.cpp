#include "data.h"

Date::Date()
{
    day = 1;
    month = 1;
    year = 1900;
}
Date::Date(string str) // конструктор структуры через строку с датой
{
    // Берутся первые 2 символа строки и преобразуются в число: разряд десятков умножается на 10, к нему добавляется разряд единиц. 
    // Предварительно вычитаются коды 0 для каждого из разрядов, чтобы привести char к int
    day = 10 * ((int)str[0] - '0') + (int)str[1] - '0';
    month = 10 * ((int)str[3] - '0') + (int)str[4] - '0';
    year = 1000 * ((int)str[6] - '0') + 100 * ((int)str[7] - '0') + 10 * ((int)str[8] - '0') + (int)str[9] - '0';
}
void Date::DatePrint()
{
    if (day > 10)
        cout << day << '.';
    else cout << '0' << day << '.';
    if (month > 10)
        cout << month << '.';
    else cout << '0' << month << '.';
    cout << year << ' ';
}

Data::Data()
{
    date = Date();
    tmax = 0;
    tmin = 0;
    tavg = 0;
    pres = 0;
    wind = 0;
    prec = 0;
    teff = 0;
}
Data::Data(string* str)
{
    date = Date(str[0]);
    if (str[1] != " ")
        tmax = stod(str[1]);
    else tmax = -273;
    if (str[2] != " ")
        tmin = stod(str[2]);
    else tmin = -273;
    if (str[3] != " ")
        tavg = stod(str[3]);
    else tavg = -273;
    if (str[4] != " ")
        pres = stod(str[4]);
    else pres = -273;
    if (str[5] != " ")
        wind = stod(str[5]);
    else wind = -273;
    if (str[6] != " ")
        prec = stod(str[6]);
    else prec = -273;
    if (str[7] != " ")
        teff = stod(str[7]);
    else teff = -273;
}
void Data::DataChange(string* str)
{
    date = Date(str[0]);
    if (str[1] != " ")
        tmax = stod(str[1]);
    else tmax = -273;
    if (str[2] != " ")
        tmin = stod(str[2]);
    else tmin = -273;
    if (str[3] != " ")
        tavg = stod(str[3]);
    else tavg = -273;
    if (str[4] != " ")
        pres = stod(str[4]);
    else pres = -273;
    if (str[5] != " ")
        wind = stod(str[5]);
    else wind = -273;
    if (str[6] != " ")
        prec = stod(str[6]);
    else prec = -273;
    if (str[7] != " ")
        teff = stod(str[7]);
    else teff = -273;
}
void Data::DataPrint()
{
    date.DatePrint();
    cout << tmax << ' ' << tmin << ' ' << tavg << ' ' << pres << ' ' << wind << ' ' << prec << ' ' << teff << endl;
}
string Data::DataToCSVString()
{
    string str;
    if (date.day > 9)
        str = to_string(date.day) + '.';
    else str = '0' + to_string(date.day) + '.';
    if (date.month > 9)
        str += to_string(date.month) + '.';
    else str += '0' + to_string(date.month) + '.';
    str += to_string(date.year) + ';';
    str += to_string(tmax) + ';';
    str += to_string(tmin) + ';';
    str += to_string(tavg) + ';';
    str += to_string(pres) + ';';
    str += to_string(wind) + ';';
    str += to_string(prec) + ';';
    str += to_string(teff) + ';';
    return str;
}