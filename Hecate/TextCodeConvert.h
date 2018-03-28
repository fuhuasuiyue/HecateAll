#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h> 
#include <stdio.h>
#include <locale.h>


class TextCodeConvert
{
public:
	TextCodeConvert();
	~TextCodeConvert();
	static std::string GBKToUTF8(const std::string& strGBK);
	static std::string UTF8ToGBK(const std::string& strUTF8);
	static wchar_t * ANSIToUnicode(const char* str);
	static char * UnicodeToANSI(const wchar_t* str);
	static wchar_t * UTF8ToUnicode(const char* str);
	static char * UnicodeToUTF8(const wchar_t* str);
	static char* w2m(const wchar_t* wcs);
	static wchar_t* m2w(const char* mbs);
	static char* ANSIToUTF8(const char* str);
	static char* UTF8ToANSI(const char* str);
};

