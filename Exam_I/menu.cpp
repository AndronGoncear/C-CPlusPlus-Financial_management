#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <conio.h>
#include <iomanip>
#include "menu.h"
#include<Windows.h>



using namespace std;
void SetColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

void SetColor(int textColor, int backgroundColor)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (WORD)((backgroundColor << 4) | textColor));
}

void show_menu(int key)
{
	key--;
	system("CLS");
	cout << endl << endl;
	const int size = 10;
	char menu[size][250] = { "Cards available in the wallet......","Adding cards to the wallet.........","Change cards in the wallet.........","Delete cards from wallet...........","Replenishment of cards with money..","List of cost categories............", "Entering costs.....................", "Reports............................","Ratings............................","Exit from the Menu................"};

	for (int i = 0; i < size; i++) {
		SetColor(15, 0);
		if (i == key) SetColor(0, 14);
		cout << "\t " << i + 1 << ". " << menu[i];
		if (i == key) cout << " --->  ";
		cout << endl << endl;
		SetColor(7, 0);
	}
	cout << "\t=============================================" << endl;
	SetColor(8);
	cout << "\tNavigation: UP key, DOWN key, ENTER to select" << endl;
	SetColor(7);
}

void show_menu1(int key)
{
	key--;
	system("CLS");
	cout << endl << endl;
	const int size = 5;
	char menu[size][250] = { "Show list of categories.......","Add new category..............","Edit the exists category......", "Delete the exists category....", "Exit from the Menu............" };

	for (int i = 0; i < size; i++) {
		SetColor(15, 0);
		if (i == key) SetColor(0, 14);
		cout << "\t " << i + 1 << ". " << menu[i];
		if (i == key) cout << " --->  ";
		cout << endl << endl;
		SetColor(7, 0);
	}
	cout << "\t================================================================" << endl;
	SetColor(8);
	cout << "\tNavigation: UP key, DOWN key, ENTER to select" << endl;
	SetColor(7);
}
void show_menu2(int key)
{
	key--;
	system("CLS");
	cout << endl << endl;
	const int size = 4;
	char menu[size][250] = { "Day......................","Period of time...........","Month....................", "Exit from the Menu......." };

	for (int i = 0; i < size; i++) {
		SetColor(15, 0);
		if (i == key) SetColor(0, 14);
		cout << "\t " << i + 1 << ". " << menu[i];
		if (i == key) cout << " --->  ";
		cout << endl << endl;
		SetColor(7, 0);
	}
	cout << "\t================================================================" << endl;
	SetColor(8);
	cout << "\tNavigation: UP key, DOWN key, ENTER to select" << endl;
	SetColor(7);
}

void show_menu3(int key)
{
	key--;
	system("CLS");
	cout << endl << endl;
	const int size = 3;
	char menu[size][250] = { "Top 3 Expenses...........","Top 3 Categories.........", "Exit from the Menu......." };

	for (int i = 0; i < size; i++) {
		SetColor(15, 0);
		if (i == key) SetColor(0, 14);
		cout << "\t " << i + 1 << ". " << menu[i];
		if (i == key) cout << " --->  ";
		cout << endl << endl;
		SetColor(7, 0);
	}
	cout << "\t================================================================" << endl;
	SetColor(8);
	cout << "\tNavigation: UP key, DOWN key, ENTER to select" << endl;
	SetColor(7);
}
void show_menu4(int key)
{
	key--;
	system("CLS");
	cout << endl << endl;
	const int size = 3;
	char menu[size][250] = {"Period of time...........","Month....................", "Exit from the Menu......." };

	for (int i = 0; i < size; i++) {
		SetColor(15, 0);
		if (i == key) SetColor(0, 14);
		cout << "\t " << i + 1 << ". " << menu[i];
		if (i == key) cout << " --->  ";
		cout << endl << endl;
		SetColor(7, 0);
	}
	cout << "\t================================================================" << endl;
	SetColor(8);
	cout << "\tNavigation: UP key, DOWN key, ENTER to select" << endl;
	SetColor(7);
}