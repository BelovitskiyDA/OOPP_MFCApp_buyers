#include "pch.h"
#include "Buyer.h"
#include "utils.h"
#include <vector>

Buyer::Buyer() {}
Buyer::~Buyer() {}


void Buyer::input()
{	
	std::cout << "New buyer" << std::endl << "name: ";
	std::cin >> name;
	std::cout << "surname: ";
	std::cin >> surname;
	std::cout << "address: ";
	clear_stream();
	std::getline(std::cin, address);
	std::cout << "age: ";
	age = input_number(14,120);
	std::cout << "phone number: ";
	phone_number = input_number(80000000000, 89999999999);
}

void Buyer::print() const
{
	paint_delimiter();
	std::cout << "Buyer" << std::endl
		<< "name: " << name << std::endl
		<< "surname: " << surname << std::endl
		<< "address: " << address << std::endl
		<< "age: " << age << std::endl
		<< "phone number: " << phone_number << std::endl;
}

void Buyer::draw(CDC* pDC, CSize& sz, int tabx)
{
	std::vector<CString> vtext{ "    Buyer","name: ","surname: ","address: ","age: ","phone number: "};

	vtext[1] += str2cstr(name);
	vtext[2] += str2cstr(surname);
	vtext[3] += str2cstr(address);
	vtext[4] += str2cstr(std::to_string(age));
	vtext[5] += str2cstr(std::to_string(phone_number));

	int max_x = sz.cx;
	CSize size_element(0, 0);
	for (auto text : vtext)
	{
		pDC->TextOutA(tabx, sz.cy, text);
		size_element = pDC->GetOutputTextExtent(text);
		sz.cy += size_element.cy;
		if (max_x < size_element.cx)
			sz.cx = size_element.cx;
	}
}

std::string Buyer::get_name()
{
	return name;
}

std::string Buyer::get_surname()
{
	return surname;
}

std::string Buyer::get_address()
{
	return address;
}

int Buyer::get_age()
{
	return age;
}

long long Buyer::get_phone_number()
{
	return phone_number;
}

void Buyer::set_name(std::string text)
{
	name = text;
}

void Buyer::set_surname(std::string text)
{
	surname = text;
}

void Buyer::set_address(std::string text)
{
	address = text;
}

void Buyer::set_age(int number)
{
	age = number;
}

void Buyer::set_phone_number(long long number)
{
	phone_number = number;
}


void Buyer::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << name;
		ar << surname;
		ar << address;
		ar << age;
		ar << phone_number;
	}
	else
	{

		{
			if (ar.GetObjectSchema() > 0)
			{
				ar >> name;
				ar >> surname;
				ar >> address;
				ar >> age;
				ar >> phone_number;
			}
		}
	}
}

IMPLEMENT_SERIAL(Buyer, CObject, 1)
