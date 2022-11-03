#include "pch.h"
#include <iostream>
#include <string>
#include "utils.h"

void paint_delimiter()
{
	std::cout << "................................" << std::endl;
}

void clear_stream(std::istream& in)
{
	in.clear();
	in.ignore(10000, '\n');
}

std::string input_name(std::string prompt)
{
	std::string name;
	std::cout << prompt << ": ";
	std::cin >> std::ws;
	std::getline(std::cin, name);

	return name;
}

CString str2cstr(std::string text)
{
	CString c_string(text.c_str());
	return c_string;
}

std::string cstr2str(CString text)
{
	std::string std_string(text);
	return std_string;
}

CArchive& operator<<(CArchive& ar, std::string& text)
{
	CString c_string(text.c_str());
	ar << c_string;
	return ar;
}

CArchive& operator>>(CArchive& ar, std::string& text)
{
	CString c_string;
	ar >> c_string;
	std::string std_string(c_string);
	text = std_string;
	return ar;
}