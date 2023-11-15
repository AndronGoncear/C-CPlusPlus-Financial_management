#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class date
{
	int day;
	int month;
	int year;

public:
date();
date(int d, int m, int y);
void init_date();
void init_month();
date& init_date2(int d, int m, int y);
int init_month_int();
bool check_date();
bool check_month();
char* month_word(int a);
void show_date(bool p = true );
date& operator=(const date& a);
date& operator()(const date& a);
friend ostream& operator<<(ostream& out, const date& a);
friend istream& operator>>(istream& in, date& a);
int get_day()const { return day; }
int get_month()const { return month; }
int get_year()const { return year; }

int get_current_year();

int date_cmp(date d1, date d2);

bool operator<(const date& obj)const;
bool operator<=(const date& obj)const;
bool operator>(const date& obj)const;
bool operator>=(const date& obj)const;
bool operator==(const date& obj)const;
};