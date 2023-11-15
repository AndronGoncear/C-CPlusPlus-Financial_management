#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Data.h"

using namespace std;
date::date()
{
	day = 0;
	month = 0;
	year = 0;
}
date::date(int d, int m, int y)
{
		this->day = d;
		this->month = m;
		this->year = y;

	if (this->check_date())
	{
		//cout << "\tYou entered all corect" << endl;
		
	}
	else
	{
		cout << "\tYou entered wrong Date" << endl;
	}
}
bool date::check_month()
{

	if (this->month >= 1 && this->month <= 12)
	{
		return true;
	}
	else //cout << "\tYou entered wrong month" << endl;
		return false;

}
bool date::check_date()
{
	int max_days;
	bool leap_year = false, t = false, y = true;
	if (this->year >= 1000 && this->year <= 9999)
	{
		if (this->month >= 1 && this->month <= 12)
		{
			if (this->day > 0) {
				switch (this->month)
				{
				case 1:case 3:case 5:case 7:case 8:case 10:case 12: max_days = 31; break;
				case 4:case 6:case 9:case 11: max_days = 30; break;
				case 2:
					if (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0)
						leap_year = true;
					max_days = (leap_year == true ? 29 : 28);
					break;
				}
				if (this->day > max_days)
				{
					//cout << "You entered wrong number of the day" << endl;
						
				}
				else
				{
					t = true;
				}
				if (t)
				{
					return true;

				}
				else
					return false;
			}
			else //cout << "\tYou entered wrong day" << endl;
			return false;

		}
		else //cout << "\tYou entered wrong month" << endl;
		return false;

	}
	else
	{
		//cout << "\tYou entered wrong year" << endl;

		return false;

	}
}
void date::init_date()
{
	while (!this->check_date())
	{
		cout << "Enter day" << " ";
		cin >> this->day;
		cout << "\tEnter month" << " ";
		cin >> this->month;
		cout << "\tEnter year" << endl;
		cin >> this->year;
	}


}

date& date::init_date2(int d, int m, int y)
{
	while (!this->check_date())
	{
		this->day = d;
		this->month = m;
		this->year = y;
	}
	return *this;

}
void date::init_month()
{
	while (!this->check_month())
	{
		cout << "\tEnter month" << " ";
		cin >> this->month;
		
	}

}

int date::init_month_int()
{
	while (!this->check_month())
	{
		cout << "\tEnter month" << " ";
		cin >> this->month;
		return this->month;

	}
}

char* date:: month_word(int a)
{
	static char name[][20] = { "No_name","January","February","March","April","May","June","July","August","September","Octomber","November","December" };

	return ((a >= 1 && a <= 12) ? name[a] : name[0]);
}
void date::show_date(bool p)
{

	if (!p)
	{
		((this->day >= 1 && this->day <= 9) ? (cout << "0" << this->day) : cout << this->day); cout << "/"; ((this->month >= 1 && this->month <= 9) ? (cout << "0" << this->month ) : (cout << this->month)) << "/" << this->year << endl;
	}
	else
	{
		((this->day >= 1 && this->day <= 9) ? (cout << "0" << this->day) : cout << this->day) << "/" << month_word(this->month) << "/" << this->year << endl;
	}


}

date& date::operator=(const date& a)

{
	if (this == &a)
	{
		return *this;
	}
	this->day = a.day;
	this->month = a.month;
	this->year = a.year;
	return *this;
}
date& date::operator()(const date& a)
{
	if (this == &a)
	{
		return *this;
	}
	this->day = a.day;
	this->month = a.month;
	this->year = a.year;
	return *this;
}

ostream& operator<<(ostream& out, const date& a)
{
	((a.day >= 1 && a.day <= 9) ? (cout << "0" << a.day) : cout << a.day); cout << "/";
	((a.month >= 1 && a.month <= 9) ? (cout << "0" << a.month) : (cout << a.month)) << "/" << a.year << endl;
	return out;
}
istream& operator>>(istream& in, date& a)
{
	while (!a.check_date())
	{
		cout << "\tEnter day" << endl;
		in >> a.day;
		cout << "\tEnter month" << endl;
		in >> a.month;
		cout << "\tEnter year" << endl;
		in >> a.year;
	}
	return in;
}

bool date::operator<(const date& obj)const
{
	return (this->year < obj.year || this->year == obj.year && this->month < obj.month
		|| this->year == obj.year && this->month == obj.month && this->day < obj.day);

}
bool date::operator<=(const date& obj)const
{
	return (this->year < obj.year || this->year == obj.year && this->month < obj.month
		|| this->year == obj.year && this->month == obj.month && this->day < obj.day
		|| this->year == obj.year && this->month == obj.month && this->day == obj.day);

}


bool date::operator>(const date& obj)const
{
	return (this->year > obj.year || this->year == obj.year && this->month > obj.month
		|| this->year == obj.year && this->month == obj.month && this->day > obj.day);
}
bool date::operator>=(const date& obj)const
{
	return (this->year > obj.year || this->year == obj.year && this->month > obj.month
		|| this->year == obj.year && this->month == obj.month && this->day > obj.day
		|| this->year == obj.year && this->month == obj.month && this->day == obj.day);
}

bool date::operator==(const date& obj)const
{
	return (this->year == obj.year && this->month == obj.month && this->day == obj.day);
}

int date::date_cmp(date d1, date d2)
{
	if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
	{
		return 0;
	}

	else if (d1.year > d2.year || d1.year == d2.year && d1.month > d2.month || d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
		
int date::get_current_year()
{

	time_t currentTime = time(nullptr);

	
	tm* localTime = localtime(&currentTime);

	
	int currentYear = localTime->tm_year + 1900;

	return currentYear;

}