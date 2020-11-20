#include "Curl.h"
#include "Data.h"

int main()
{
    string result;
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    string s = "http://pogoda-service.ru/archive_gsod_res.php?country=AS&station=948955&datepicker_beg=24.05.2014&datepicker_end=22.02.2017&bsubmit=%D0%9F%D0%BE%D1%81%D0%BC%D0%BE%D1%82%D1%80%D0%B5%D1%82%D1%8C";
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, s.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (CURLE_OK != res) {
            cerr << "CURL error: " << res << '\n';
        }
    }
    curl_global_cleanup();
    ofstream fout("pogoda.txt");
    result = Utf8_to_cp1251(result.c_str());
    fout << result;
    fout.close();

    int length;
    char* buffer;
    ifstream is;
    is.open("pogoda.txt", ios::binary);
    is.seekg(0, ios::end);
    length = is.tellg();
    is.seekg(0, ios::beg);
    buffer = new char[length];
    is.read(buffer, length);
    is.close();
    delete[] buffer;

    size_t pos = 0;
    pos = result.find("Эффективная <br>температура", pos);
    if (pos != std::string::npos)
        std::cout << "Found at pos = " << pos << "\n";
    else
        std::cout << "Not found\n";
    string** data = toData(result, pos);
    vector<Data>d(pos);
    Data a;
    for (int i = 0; i < pos; i++)
    {
        a.DataChange(data[i]);
        d[i] = a;
        d[i].DataPrint();
    }

    ofstream f("pogoda2.csv");
    for (int i = 0; i < d.size(); i++)
    {
        f << d[i].DataToCSVString();
        f << '\r';
    }
    f.close();
}