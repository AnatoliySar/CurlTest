#pragma once
#define CURL_STATICLIB
#include "curl/curl.h"
#include <fstream>

using namespace std;

#ifdef _DEBUG
#pragma comment (lib, "curl/libcurl_a_debug.lib")
#else
#pragma comment (lib, "curl/libcurl_a.lib")
#endif

#pragma comment (lib, "Normaliz.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "Crypt32.lib")
#pragma comment (lib, "advapi32.lib")



string Utf8_to_cp1251(const char* str);
string** toData(string r, size_t& pos);
size_t my_write(void* buffer, size_t size, size_t nmemb, void* param);