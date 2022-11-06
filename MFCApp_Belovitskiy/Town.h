#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "Buyer.h"
//class Buyer;

class Town: public CObject
{
	std::string name, country;
	int index, utc;
	//std::vector <Buyer*> buyers;
	std::vector <std::shared_ptr<Buyer>> buyers;
public:
	Town();
	void input();
	void print() const;
	void add_buyer();
	void add_vip_buyer();
	auto choose_buyer();
	void save_buyer();
	void load_buyer();
	void delete_buyer();
	void delete_buyer(int n);
	void load_file(CArchive& ar);
	void save_file(CArchive& ar);
	void clear_town();
	int get_index() const;
	std::string get_name() const;
	std::shared_ptr<Buyer> get_n(int n);
	CSize draw(CDC* pDC);
	void printList(CListBox& list);
	~Town();
};

