#pragma once

#include <locale>
#include<string>

#define ALTURA_ECRA 24

#define TAB_BIG "          "
#define TAB "   "

inline bool is_number(const std::string &str)
{
	return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}
