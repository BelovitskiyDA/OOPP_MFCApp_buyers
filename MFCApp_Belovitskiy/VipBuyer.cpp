#include "pch.h"
#include "VipBuyer.h"
#include "utils.h"

VipBuyer::VipBuyer() {}
VipBuyer::~VipBuyer() {}

void VipBuyer::input()
{
	Buyer::input();
	std::cout << "points: ";
	points = input_number(0, 100000);
}

void VipBuyer::print() const
{
	Buyer::print();
	std::cout << "points: " << points << std::endl;
}

void VipBuyer::Serialize(CArchive& ar)
{
	Buyer::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << points;
	}
	else
	{

		{
			if (ar.GetObjectSchema() > 0)
			{
				ar >> points;
			}
		}
	}
}

IMPLEMENT_SERIAL(VipBuyer, Buyer, VERSIONABLE_SCHEMA | 1)