#pragma once

#include <string>
#include <fstream>
#include <iostream>


class Buyer: public CObject
{
protected:
	std::string name, surname, address;
	int age;
	long long phone_number;
public:
	DECLARE_SERIAL(Buyer);
	Buyer();
	virtual void input();
	virtual void print() const;
	virtual void Serialize(CArchive& ar);
	virtual void draw(CDC* pDC,CSize& sz,int tabx);
	std::string get_name();
	std::string get_surname();
	std::string get_address();
	int get_age();
	long long get_phone_number();
	virtual ~Buyer();
};

