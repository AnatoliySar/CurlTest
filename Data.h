#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
    Date();
    Date(string str);
    void DatePrint();
};
struct Data
{
    Date date;
    double tmax;
    double tmin;
    double tavg;
    double pres;
    double wind;
    double prec;
    double teff;
    Data();
    Data(string* str);
    void DataChange(string* str);
    void DataPrint();
    string DataToCSVString();
};