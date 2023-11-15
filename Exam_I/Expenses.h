#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include <chrono>
using namespace std;


class Expenses
{	
	vector<string> category;
	int poz;
	double sum;
	string data;
	string comment;

public:
	Expenses();
	Expenses(const vector<string>& category,int poz, double sum, string data, string comment);
	
	void Add_category(string s);
	
	void Delete_category_by_poz( int p);

	void Delete_category();

	void Modify_category_by_poz(int p, string temp);

	void Show_List_Category()const;

	void save_category_file(ofstream& f)const;

	void read_category_file(ifstream &f);


	string get_data() const { return data; }

	string get_category(int p) const;

	double get_suma() const { return sum; }

	int get_poz() const { return poz; }

	int category_size() const { return this->category.size(); }


	
	friend ostream& operator << (ostream& out, const Expenses& aut);

	friend istream& operator >> (istream& in, Expenses& aut);

	friend ofstream& operator << (ofstream& fout, const Expenses& aut);

	friend ifstream& operator >> (ifstream& fin, Expenses& aut);


};










