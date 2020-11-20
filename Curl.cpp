#include "Curl.h"

   string Utf8_to_cp1251(const char* str)
{
    string res;
    int result_u, result_c;

    result_u = MultiByteToWideChar(CP_UTF8, 0, str, -1, 0, 0);

    if (!result_u)
        return 0;

    wchar_t* ures = new wchar_t[result_u];

    if (!MultiByteToWideChar(CP_UTF8, 0, str, -1, ures, result_u))
    {
        delete[] ures;
        return 0;
    }

    result_c = WideCharToMultiByte(1251, 0, ures, -1, 0, 0, 0, 0);

    if (!result_c)
    {
        delete[] ures;
        return 0;
    }

    char* cres = new char[result_c];

    if (!WideCharToMultiByte(1251, 0, ures, -1, cres, result_c, 0, 0))
    {
        delete[] cres;
        return 0;
    }
    delete[] ures;
    res.append(cres);
    delete[] cres;
    return res;
}
string** toData(string r, size_t& pos)
{
    const char* rc = r.c_str();
    string dataHeap = "";
    int counter = 0;
    while (1)
    {
        counter++;
        pos = r.find("rgb", pos);
        dataHeap += '_';
        if (pos > r.length())
        {
            pos = counter - 1;
            //return dataHeap;
            break;
        }
        pos = r.find(">", pos);
        pos++;
        if (rc[pos] == '<')
        {
            dataHeap += ' ';
        }
        else
        {
            do
            {
                dataHeap += rc[pos];
                pos++;
            } while (rc[pos] != '<');
        }
    }
    counter--;
    int width = 8;
    int height = counter / 8;
    counter = dataHeap.length() - 1;
    string** data = new string * [height];
    for (int i = 0; i < height; i++)
        data[i] = new string[width];
    int pos_ = 1;
    int c = 0;
    int d = 0;
    do
    {
        if (dataHeap[pos_] == '_')
        {
            if (d == (width - 1))
            {
                c++;
                d = 0;
            }
            else
                d++;
        }
        else
            data[c][d] += dataHeap[pos_];
        pos_++;
        counter--;
    } while (counter != 0);
    pos = height;
    return data;
}
size_t my_write(void* buffer, size_t size, size_t nmemb, void* param)
{
    string& text = *static_cast<string*>(param);
    size_t totalsize = size * nmemb;
    text.append(static_cast<char*>(buffer), totalsize);
    return totalsize;
}