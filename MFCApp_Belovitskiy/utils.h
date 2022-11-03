#pragma once
#include <iostream>
#include <string>
#include <fstream>

void paint_delimiter();
void clear_stream(std::istream& in = std::cin);
std::string input_name(std::string prompt);

CString str2cstr(std::string text);
std::string cstr2str(CString text);

CArchive& operator<<(CArchive& ar, std::string& text);
CArchive& operator>>(CArchive& ar, std::string& text);

template <typename T>
T input_number(T min, T max)
{
	T x = 0;
	while (true)
	{
		std::cin >> x;
		if (!std::cin.fail() && std::cin.peek() == '\n' && (min <= x && x <= max))
		{
			return x;
		}
		else
		{
			std::cout << "not correct number " << std::endl
				<< "try again: ";
			clear_stream();
		}
	}
}