#include "TextCodeConvert.h"

using namespace std;

TextCodeConvert::TextCodeConvert()
{
}


TextCodeConvert::~TextCodeConvert()
{
}

std::string TextCodeConvert::GBKToUTF8(const std::string& strGBK)
{
	string strOutUTF8 = "";
	WCHAR * str1;
	int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
	str1 = new WCHAR[n];
	MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
	n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
	char * str2 = new char[n];
	WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
	strOutUTF8 = str2;
	delete[]str1;
	str1 = NULL;
	delete[]str2;
	str2 = NULL;
	return strOutUTF8;

}

std::string TextCodeConvert::UTF8ToGBK(const std::string & strUTF8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, NULL, 0);
	unsigned short * wszGBK = new unsigned short[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, (LPCCH)strUTF8.c_str(), -1, (WCHAR*)(wszGBK), len);

	len = WideCharToMultiByte(CP_ACP, 0, (WCHAR*)wszGBK, -1, NULL, 0, NULL, NULL);
	char *szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, (WCHAR*)wszGBK, -1, szGBK, len, NULL, NULL);
	//strUTF8 = szGBK;
	std::string strTemp(szGBK);
	delete[]szGBK;
	delete[]wszGBK;
	return strTemp;
}

wchar_t * TextCodeConvert::ANSIToUnicode(const char * str)
{
	int textlen;
	wchar_t * result;
	textlen = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	result = (wchar_t *)malloc((textlen + 1) * sizeof(wchar_t));
	memset(result, 0, (textlen + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, 0, str, -1, (LPWSTR)result, textlen);
	return result;
}

char * TextCodeConvert::UnicodeToANSI(const wchar_t * str)
{
	char* result;
	int textlen;
	textlen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	result = (char *)malloc((textlen + 1) * sizeof(char));
	memset(result, 0, sizeof(char) * (textlen + 1));
	WideCharToMultiByte(CP_ACP, 0, str, -1, result, textlen, NULL, NULL);
	return result;
}

wchar_t * TextCodeConvert::UTF8ToUnicode(const char * str)
{
	int textlen;
	wchar_t * result;
	textlen = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	result = (wchar_t *)malloc((textlen + 1) * sizeof(wchar_t));
	memset(result, 0, (textlen + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_UTF8, 0, str, -1, (LPWSTR)result, textlen);
	return result;
}

char * TextCodeConvert::UnicodeToUTF8(const wchar_t * str)
{
	char* result;
	int textlen;
	textlen = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
	result = (char *)malloc((textlen + 1) * sizeof(char));
	memset(result, 0, sizeof(char) * (textlen + 1));
	WideCharToMultiByte(CP_UTF8, 0, str, -1, result, textlen, NULL, NULL);
	return result;
}

char * TextCodeConvert::w2m(const wchar_t * wcs)
{
	int len;
	char* buf;
	len = wcstombs(NULL, wcs, 0);
	if (len == 0)
		return NULL;
	buf = (char *)malloc(sizeof(char)*(len + 1));
	memset(buf, 0, sizeof(char) *(len + 1));
	len = wcstombs(buf, wcs, len + 1);
	return buf;
}

wchar_t * TextCodeConvert::m2w(const char * mbs)
{
	int len;
	wchar_t* buf;
	len = mbstowcs(NULL, mbs, 0);
	if (len == 0)
		return NULL;
	buf = (wchar_t *)malloc(sizeof(wchar_t)*(len + 1));
	memset(buf, 0, sizeof(wchar_t) *(len + 1));
	len = mbstowcs(buf, mbs, len + 1);
	return buf;
}

char * TextCodeConvert::ANSIToUTF8(const char * str)
{
	wchar_t * buf = ANSIToUnicode(str);
	char * ret = UnicodeToUTF8(buf);
	free(buf);
	return ret;
}

char * TextCodeConvert::UTF8ToANSI(const char * str)
{
	wchar_t * buf = UTF8ToUnicode(str);
	char * ret = UnicodeToANSI(buf);
	free(buf);
	return ret;
}
