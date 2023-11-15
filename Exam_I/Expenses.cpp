#define _CRT_SECURE_NO_WARNINGS
#include "Expenses.h"
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include <chrono>
#include<Windows.h>
using namespace std;


Expenses::Expenses()
{
	this->data = "No data";
	this->comment = "No comment";
	this->sum = 0.0;
	this->poz = 0;
}
Expenses::Expenses(const vector<string>& category, int poz, double sum, string data, string comment)
{
	this->category = category;
	this->poz = poz;
	this->sum = sum;
	this->data = data;
	this->comment = comment;
	
}
void Expenses::Add_category(string s)
{
	
	if (this->category.size())
	{
		int t = 0;
		for (auto& x : this->category)
		{

			if (x == s)
			{
				t++;
			}
		}
		if (t)
		{
			cout << "\nSuch category exists!!! Enter another category!!!";
			
		}
		else
		{
			this->category.emplace_back(s);
		}
	}
	else
	{
		this->category.emplace_back(s);
	}

}
void Expenses::Delete_category()
{
	if (this->category.size())
	{
		this->category.clear();
	}
	else
	{
		//cout << "\nThe list is empty" << endl;
	}

}
void Expenses::Delete_category_by_poz(int p)
{
	if (this->category.size())
	{
		this->category.erase(this->category.begin() + (p - 1));
	}
	else
	{
		//cout << "\nThe list is empty" << endl;
	}

}


	void Expenses::Show_List_Category()const
	{
		cout << "\nList of cost categories" << endl<<endl<<endl;
		int t = 1;
		if (this->category.size())
		{
		    
			for (const auto& x : category)
			{
			
				cout <<t<< "  :  " << x<<endl;
				t++;
			}
		
		}
		else
		{
			//cout << "\nList of Categories is empty!!!" << endl;
		}

	}
	void Expenses::save_category_file(ofstream& f)const
	{

		size_t size;
		size = this->category.size();
		f.write(reinterpret_cast<const char*>(&size), sizeof(size));
		for (const auto& v : this->category)
		{
			size = v.length();
			f.write(reinterpret_cast<const char*>(&size), sizeof(size));
			f.write(v.data(), size);

		}

	}

	void Expenses::read_category_file(ifstream& f)
	{
		size_t size2;
		string dat;
		f.read(reinterpret_cast<char*>(&size2), sizeof(size2));
		for (int i = 0; i < size2; i++)
		{
			int len;
			f.read(reinterpret_cast<char*>(&len), sizeof(len));
			dat.resize(len);
			f.read(const_cast<char*>(dat.c_str()), len);
			this->category.push_back(dat);
		
		}

	}



	ostream& operator << (ostream& out, const Expenses& aut)
	{
		out << "\nCategory of expensies            :  ";
		if (aut.poz)
		{
			out << aut.category[aut.poz - 1];			
		}
		out << "\nDate of expensies                :  ";
		out << aut.data;
		out << "\nSum of expensies                 :  ";
		out << aut.sum;
		out << "\nComment of expensies             :  ";
		out << aut.comment;
		cout << endl;
		cout << "=======================================================" << endl;
		return out;
	}

	istream& operator >> (istream& in, Expenses& aut)
	{
		cout << endl;
		string temp;
		char buf[256];
		aut.Show_List_Category();
	    exit1:
		cout << "\nÑhoose the Category of expensies. Enter number of the Category" << endl;
		int t;
		cin >> t;
		if (t<1 || t>aut.category.size())
		{
			cout << "\nYou entered wrong number of the Category pozition";
			goto exit1;
		}
		else
		{
			double t1;
			cout << "\nEnter amount of expensies" << endl;
			cin >> t1;
			if (t1 <= 0)
			{
				cout << "\nYou entered wrong amount of money. It must be bigger then 0!!!";
			}
			else
			{
				aut.sum = t1;
				aut.poz = t;
			}
		}
		cout << "\nEnter comment about expensies" << endl;
		cin.ignore();
		getline(cin,temp);
		aut.comment = temp;
		const time_t tm = time(nullptr);
		strftime(buf, size(buf), "%d.%m.%Y", localtime(&tm));
		aut.data = buf;
		return in;
	}

	ofstream& operator << (ofstream& fout, const Expenses& aut)
	{
		size_t size;
		size = aut.category.size();
		fout.write(reinterpret_cast<const char*>(&size), sizeof(size));
		for (const auto& v : aut.category)
		{
			size = v.length();
			fout.write(reinterpret_cast<const char*>(&size), sizeof(size));
			fout.write(v.data(), size);

		}
		int k = aut.poz;
		fout.write(reinterpret_cast<const char*>(&k), sizeof(k));
		double p = aut.sum;
		fout.write(reinterpret_cast<const char*>(&p), sizeof(p));
		size = aut.data.size();
		fout.write(reinterpret_cast<const char*>(&size), sizeof(size));
		fout.write(aut.data.c_str(), size);
		size = aut.comment.size();
		fout.write(reinterpret_cast<const char*>(&size), sizeof(size));
		fout.write(aut.comment.c_str(), size);
		return fout;
	}


	ifstream& operator >> (ifstream& fin, Expenses& aut)
	{
		size_t size2;
		string dat;
		double p;
		int k;
		fin.read(reinterpret_cast<char*>(&size2), sizeof(size2));
		for (int i = 0; i < size2; i++)
		{
			int len;
			fin.read(reinterpret_cast<char*>(&len), sizeof(len));
			dat.resize(len);
			fin.read(const_cast<char*>(dat.c_str()), len);
			aut.category.push_back(dat);

		}

		fin.read(reinterpret_cast<char*>(&k), sizeof(k));
		aut.poz = k;
	
		fin.read(reinterpret_cast<char*>(&p), sizeof(p));
		aut.sum = p;
		fin.read(reinterpret_cast<char*>(&size2), sizeof(size2));
		aut.data.resize(size2);
		fin.read(const_cast<char*>(aut.data.c_str()), size2);
		fin.read(reinterpret_cast<char*>(&size2), sizeof(size2));
		aut.comment.resize(size2);
		fin.read(const_cast<char*>(aut.comment.c_str()), size2);
		return fin;
	}


	string Expenses::get_category(int p) const
	{
		return this->category[p - 1];
	}

	void Expenses::Modify_category_by_poz(int p, string temp)
	{
		this->category[p - 1] = temp;
	}