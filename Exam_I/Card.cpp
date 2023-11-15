#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <conio.h>
#include <iomanip>
#include "Card.h"
#include<Windows.h>
#include <fstream>



using namespace std;


	Card::Card()
	{
		this->card_number = "No number";
		this->summa = 0.0;
		this->card_type = 1;
	}

	Card::Card(const string& card_number, double& summa, int card_type)
	{
		this->card_number = card_number;
		this->summa = summa;
		this->card_type = card_type;
	}
	
	void Card::Show()const
	{
		cout << "\nCard Number         " << this->card_number;
		cout << "\nAmount on the card  " <<setprecision(2)<<fixed<< this->summa;
		if (this->card_type==1)
		{
			cout << "\nCard Type is    " << " DEBIT  ";
		}
		else if(this->card_type == 2)
		{
			cout << "\nCard Type is    " << " CREDIT ";
		}
	}
	void Card::Add_money(double s)
	{

		this->summa += s;
		
	}
	void Card::Expenses(double s)
	{
		if (this->summa >= s)
		{
			this->summa -= s;
		
		}
		else
		{
			cout << "\nNot enough money on the card!!!! Please choose another card!!!";
			_getch();
		}
	}



	ostream& operator << (ostream& out, const Card& aut)
	{
		out << "\nCard Number         :  " << aut.card_number;
		out << "\nAmount on the card  :  " << setprecision(2) << fixed << aut.summa;
		if (aut.card_type==1)
		{
		out << "\nCard Type is        :  " << "DEBIT  ";
		}
		else if (aut.card_type == 2)
		{
		out << "\nCard Type is        :  " << "CREDIT ";
		}
		out << "\n===================================="<<endl;
		return out;
	}

	istream& operator >> (istream& in, Card& aut)
	{
		string tmp;
		int t;
		cout << "\nEnter Card Number                      :  ";
		getline(in, aut.card_number);
	exit:
		cout << "\nEnter Card Type                        :  ";
		cout << "\n1. DEBIT CARD                          :  ";
		cout << "\n2. CREDIT CARD                         :  " << endl;
		cin >> t;
		if (t != 1 && t != 2)
		{
			cout << "\nYou entered wrong number. It must be from 1 to 2";
			goto exit;
		}
		aut.card_type = t;
		return in;
	}

	bool Card::operator==(const Card& obj)const
	{
		if (this == &obj)
		{
			return true;
		}

		if (this->card_number == obj.card_number && this->card_type == obj.card_type)
		{
			return true;
		}
		return false;
	}

	ofstream& operator << (ofstream& fout, const Card& aut)
	{
		size_t size;
        size = aut.card_number.size();
		fout.write(reinterpret_cast<const char*>(&size), sizeof(size));
		fout.write(aut.card_number.c_str(), size);
		double p = aut.summa;
		fout.write(reinterpret_cast<const char*>(&p), sizeof(p));
		int t = aut.card_type;
		fout.write(reinterpret_cast<const char*>(&t), sizeof(t));
		return fout;
	}

	ifstream& operator >> (ifstream& fin, Card& aut)
	{
		size_t size;
		double p;
		int t;
		fin.read(reinterpret_cast<char*>(&size), sizeof(size));
		aut.card_number.resize(size);
		fin.read(const_cast<char*>(aut.card_number.c_str()), size);
		fin.read(reinterpret_cast<char*>(&p), sizeof(p));
	    aut.summa=p;
		fin.read(reinterpret_cast<char*>(&t), sizeof(t));
	    aut.card_type=t;
		return fin;
	}


	void Card::Delete_card_by_poz(int p)
	{

	}

	void Card::Modify_card_by_poz(string temp)
	{
		this->card_number = temp;
	}