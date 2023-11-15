#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<list>
#include <chrono>
using namespace std;


class Card
{
	string card_number;
	double summa;
	int card_type;
public:
	Card();
	Card(const string& card_number, double& summa, int card_type);
	string Get_card_number() const { return card_number; }
	void Show()const;
	void Add_money(double s);
	void Expenses(double s);

	void Delete_card_by_poz(int p);

	void Modify_card_by_poz(string temp);

	bool operator==(const Card& obj)const;

	friend ostream& operator << (ostream& out, const Card& aut);

	friend istream& operator >> (istream& in, Card& aut);

	friend ofstream& operator << (ofstream& fout, const Card& aut);

	friend ifstream& operator >> (ifstream& fin, Card& aut);
	
};










