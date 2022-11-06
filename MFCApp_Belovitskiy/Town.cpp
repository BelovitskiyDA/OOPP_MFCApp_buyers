#include "pch.h"
#include "Town.h"
#include "utils.h"
#include "Buyer.h"
#include "VipBuyer.h"
#include <atlstr.h>
#include <vector>
#include <algorithm>
#include <functional>

Town::Town() 
{
	index = 0;
	name = "";
	country = "";
	utc = 0;
}

void Town::input()
{
	std::cout << "New town" << std::endl;
	std::cout << "index: ";
	index = input_number(0, 1000);
	std::cout << "name: ";
	std::cin >> name;
	std::cout << "country: ";
	std::cin >> country;
	std::cout << "utc: ";
	utc = input_number(-12, 14);
}

void Town::print() const
{
	paint_delimiter();
	std::cout << "Town" << std::endl
		<< "index: " << index << std::endl
		<< "name: " << name << std::endl
		<< "country: " << country << std::endl
		<< "utc: " << utc << std::endl;
	for (const auto iter : buyers)
	{
		iter->print();
	}
}

void Town::add_buyer()
{
	auto new_buyer = std::make_shared<Buyer>();
	new_buyer->input();
	buyers.push_back(new_buyer);
}

void Town::add_vip_buyer()
{
	auto new_buyer = std::make_shared<VipBuyer>();
	new_buyer->input();
	buyers.push_back(new_buyer);
}

void Town::load_buyer()
{
	std::string fname = input_name("input name of file");
	std::string filename = fname + ".dat";
	if (!std::fstream(filename))
	{
		std::cout << "error load from file: " << filename << std::endl;
		return;
	}
	CString cfilename = str2cstr(filename);
	CFile f(cfilename, CFile::modeRead);
	CArchive ar(&f, CArchive::load);

	Buyer* new_buyer;
	//new_buyer->Serialize(ar);
	ar >> new_buyer;
	std::shared_ptr<Buyer> new_buyer_ptr(new_buyer);
	buyers.push_back(new_buyer_ptr);
}


void Town::load_file(CArchive& ar)
{
	/*
	std::string filename = std::to_string(indexfile) + ".dat";
	CString cfilename = str2cstr(filename);
	CFile f(cfilename, CFile::modeRead);
	CArchive ar(&f, CArchive::load);
	*/

	if (buyers.size())
	{
		/*
		for (auto buyer : buyers)
		{
			delete buyer;
		}
		*/
		buyers.clear();
	}

	ar >> index;
	ar >> name;
	ar >> country;
	ar >> utc;

	int n = 0;
	ar >> n;
	for (int i = 0; i < n; ++i)
	{
		Buyer* new_buyer;
		ar >> new_buyer;
		std::shared_ptr<Buyer> new_buyer_ptr(new_buyer);
		buyers.push_back(new_buyer_ptr);
	}

}

void Town::save_file(CArchive& ar)
{
	/*
	std::string filename = std::to_string(index) + ".dat";
	CString cfilename = str2cstr(filename);
	CFile f(cfilename, CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&f, CArchive::store);
	*/
	
	ar << index;
	ar << name;
	ar << country; 
	ar << utc;

	int n = buyers.size();
	ar << n;
	for (int i = 0; i < n; ++i)
	{
		//buyers[i]->Serialize(ar);
		ar << buyers[i].get();
	}
}

int Town::get_index() const
{
	return index;
}

std::string Town::get_name() const
{
	return name;
}

std::shared_ptr<Buyer> Town::get_n(int n)
{
	if (n+1 > buyers.size())
	{
		return *buyers.begin();
	}
	else
	{
		auto p = buyers[n];
		return p;
	}
}

CSize Town::draw(CDC* pDC)
{
	int xstart = 0;
	int tabx = 0;
	int ystart = 0;
	CSize sz(xstart, ystart);
	std::vector<CString> vtext{"    Town","index: ","name: ","country: ","utc: "};

	vtext[1] += str2cstr(std::to_string(index));
	vtext[2] += str2cstr(name);
	vtext[3] += str2cstr(country);
	vtext[4] += str2cstr(std::to_string(utc));

	int max_x = 0;
	CSize size_element(0, 0);
	for (auto text : vtext)
	{
		pDC->TextOutA(tabx, sz.cy, text);
		size_element = pDC->GetOutputTextExtent(text);
		sz.cy += size_element.cy;
		if (max_x < size_element.cx)
			sz.cx = size_element.cx;
	}

	std::for_each(buyers.begin(), buyers.end(), std::bind(&Buyer::draw, std::placeholders::_1, pDC,std::ref(sz),tabx));

	/*
	pDC->TextOutA(sz.cx,sz.cy,"Town\n");
	sz += pDC->GetOutputTextExtent("Town\n");
	pDC->TextOutA(xstart, sz.cy, "index");
	sz += pDC->GetOutputTextExtent("index");
	
	std::cout << "Town" << std::endl
		<< "index: " << index << std::endl
		<< "name: " << name << std::endl
		<< "country: " << country << std::endl
		<< "utc: " << utc << std::endl;
	for (const auto iter : buyers)
	{
		iter->print();
	}
	*/
	return sz;
}

Town::~Town()
{
	/*
	for (auto buyer : buyers)
	{
		delete buyer;
	}
	*/
}

void Town::clear_town()
{
	if (buyers.size())
	{
		/*
		for (auto buyer : buyers)
		{
			delete buyer;
		}
		*/
		buyers.clear();
	}
}

auto Town::choose_buyer()
{
	int count = 0;
	for (auto buyer : buyers)
	{
		std::cout << ++count << std::endl;
		buyer->print();
		paint_delimiter();
	}
	std::cout << "choose number of buyer: ";
	int number;
	number = input_number(1, (int)buyers.size());
	auto iter = buyers.begin() + number - 1;
	return iter;
}

void Town::save_buyer()
{
	if (!buyers.size())
	{
		std::cout << "Not buyers.Please create or load" << std::endl;
		return;
	}
	auto iter = choose_buyer();
	if (iter != buyers.end())
	{
		std::string fname = input_name("input name of file");
		std::string filename = fname + ".dat";
		CString cfilename = str2cstr(filename);
		CFile f(cfilename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&f, CArchive::store);

		ar << (*iter).get();

	}
	else
	{
		std::cout << "no existing this buyer" << std::endl;
	}
}

void Town::delete_buyer()
{
	auto iter = choose_buyer();
	if (iter != buyers.end())
	{
		//delete (*iter);
		buyers.erase(iter);
	}
	else
	{
		std::cout << "no existing this buyer" << std::endl;
	}
}

void Town::delete_buyer(int n)
{
	if (n+1 > buyers.size())
	{
		return;
	}
	else
	{
		buyers.erase(buyers.begin() + n);
	}
}


void Town::printList(CListBox& list)
{
	//for_each and lambda function
	for_each(buyers.begin(), buyers.end(), [&list](auto p){list.AddString(str2cstr(p->get_surname() + " " + p->get_name()));});
	list.SetCurSel(0);
}