#include "pch.h"
#include "Buyer.h"
#include "utils.h"

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
