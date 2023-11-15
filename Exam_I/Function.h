#pragma once
#include <iostream>
#include <conio.h>
#include <map>
#include <iomanip>
#include<vector>
#include<fstream>
#include<string>



using namespace std;

//bool compare_by_category(string a, string b)
//{
//	return a > b;
//}
//bool compare_by_suma(double a, double b)
//{
//	return a > b;
//}
//
//struct compare_by_category
//{
//	bool operator()(const string& a, const string& b)const
//	{
//		return a > b;
//	}
//};
//
//struct compare_by_suma
//{
//	bool operator()(const double& a, const double& b)const
//	{
//		return a > b;
//	}
//};


struct compare
{
	bool operator()(const string& a, const string& b)const
	{
		return a > b;
	}
};


