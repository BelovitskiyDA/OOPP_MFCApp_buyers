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


void VipBuyer::draw(CDC* pDC, CSize& sz, int tabx)
{
	Buyer::draw(pDC, sz, tabx);

	CString points_str = "points: " + str2cstr(std::to_string(points));

	int max_x = sz.cx;
	CSize size_element(0, 0);
	
	pDC->TextOutA(tabx, sz.cy, points_str);
	size_element = pDC->GetOutputTextExtent(points_str);
	sz.cy += size_element.cy;
	if (max_x < size_element.cx)
		sz.cx = size_element.cx;
	
}

int VipBuyer::get_points()
{
	return points;
}

void VipBuyer::set_points(int number)
{
	points = number;
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