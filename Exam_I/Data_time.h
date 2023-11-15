#pragma once
#include <iostream>
#include<fstream>

using namespace std;
class date
{
	int minute;
	int hour;
	int day;
	int month;
	int year;

public:
date();
date(int min, int hour, int d, int m, int y);
int get_hour()const { return hour; }
int get_minute()const { return minute; }
int get_day()const { return day; }
int get_month()const { return month; }
int get_year()const { return year; }
void init_date();
bool check_date();
bool check_date_time();
char* month_word(int a);
void show_date(bool p = true );
date& operator=(const date& a);
friend ostream& operator<<(ostream& out, const date& a);
friend istream& operator>>(istream& in, date& a);

friend ofstream& operator<<(ofstream& fout, const date& d);

friend ifstream& operator>>(ifstream& fin, date& d);



/* compare given dates d1 and d2 */
int date_cmp(date d1, date d2);

bool operator<(const date& obj)const;
};