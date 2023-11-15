
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Data_time.h"


using namespace std;
date::date()
{
	minute = 0;
	hour = 0;
	day = 0;
	month = 0;
	year = 0;
}
date::date(int min, int h,int d, int m, int y)
{
	    this->minute = min;
		this->hour = h;
		this->day = d;
		this->month = m;
		this->year = y;

	if (this->check_date_time())
	{
		//cout << "\tYou entered all corect" << endl;
		
	}
	else
	{
		cout << "\tYou entered wrong Date" << endl;
	}
}
bool date::check_date_time()
{
	int max_days;
	bool leap_year = false, t = false, y = true;
	if (this->minute >= 0 && this->minute <= 59)
	{
		if (this->hour >= 0 && this->hour <= 23)
		{
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
		else
		{
			//cout << "\tYou entered wrong hours" << endl;

			return false;


		}
	}
	else
	{
		//cout << "\tYou entered wrong minutes" << endl;

		return false;

	}

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

int date::date_cmp(date d1, date d2)
{
	if (d1.minute == d2.minute && d1.hour == d2.hour && d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
	{
		return 0;
	}

	else if (d1.year > d2.year || d1.year == d2.year && d1.month > d2.month || d1.year == d2.year && d1.month == d2.month && d1.day > d2.day ||

		d1.year == d2.year && d1.month == d2.month && d1.day == d2.day && d1.hour > d2.hour ||

		d1.year == d2.year && d1.month == d2.month && d1.day == d2.day && d1.hour == d2.hour && d1.minute > d2.minute)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

bool date::operator<(const date& obj)const
{
	return (this->year < obj.year || this->year == obj.year && this->month < obj.month || this->year == obj.year && this->month == obj.month && this->day < obj.day ||

		this->year == obj.year && this->month == obj.month && this->day == obj.day && this->hour < obj.hour ||

		this->year == obj.year && this->month == obj.month && this->day == obj.day && this->hour == obj.hour && this->minute < obj.minute);
}

ostream& operator<<(ostream& out, const date& a)
{
	out<<a.year;out << "-";
	((a.month >= 1 && a.month <= 9) ? (out << "0" << a.month) : (out << a.month)) << "-";
	((a.day >= 1 && a.day <= 9) ? (out << "0" << a.day) : out << (a.day)); out << " ";
	if (!a.hour)
	{
		out << "00"; out << ":";
	}
	else
	{
		((a.hour >= 1 && a.hour <= 9) ? (out << "0" << a.hour) : (out << a.hour)); out << ":";
	}
	if (!a.minute)
	{
		out << "00";
	}
	else
	{
		((a.minute >= 1 && a.minute <= 9) ? (out << "0" << a.minute) : (out << a.minute));
	}
	
	
	
	return out;
}
istream& operator>>(istream& in, date& a)
{
	while (!a.check_date_time())
	{
		cout << "\tEnter day" << endl;
		in >> a.day;
		cout << "\tEnter month" << endl;
		in >> a.month;
		cout << "\tEnter year" << endl;
		in >> a.year;
		cout << "\tEnter minute" << endl;
		in >> a.minute;
		cout << "\tEnter hour" << endl;
		in >> a.hour;
	}
	return in;
}


ofstream& operator<<(ofstream& fout, const date& d)
{
	fout.write(reinterpret_cast<const char*>(&d.minute), sizeof(d.minute));
	fout.write(reinterpret_cast<const char*>(&d.hour), sizeof(d.hour));
	fout.write(reinterpret_cast<const char*>(&d.day), sizeof(d.day));
	fout.write(reinterpret_cast<const char*>(&d.month), sizeof(d.month));
	fout.write(reinterpret_cast<const char*>(&d.year), sizeof(d.year));

	return fout;

}

ifstream& operator>>(ifstream& fin, date& d)
{
	fin.read(reinterpret_cast<char*>(&d.minute), sizeof(d.minute));
	fin.read(reinterpret_cast<char*>(&d.hour), sizeof(d.hour));
	fin.read(reinterpret_cast<char*>(&d.day), sizeof(d.day));
	fin.read(reinterpret_cast<char*>(&d.month), sizeof(d.month));
	fin.read(reinterpret_cast<char*>(&d.year), sizeof(d.year));
	return fin;

}

		
