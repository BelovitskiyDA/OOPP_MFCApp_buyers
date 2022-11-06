#pragma once
#include "Buyer.h"
class VipBuyer :
    public Buyer
{
    int points;
public:
	DECLARE_SERIAL(VipBuyer);
	VipBuyer();
	void input();
	void print() const;
	void Serialize(CArchive& ar);
	void draw(CDC* pDC, CSize& sz, int tabx);
	int get_points();
	~VipBuyer();
};

