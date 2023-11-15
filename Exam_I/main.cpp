#define  _CRT_SECURE_NO_WARNINGS
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<string>
#include<algorithm>
#include<vector>
#include"Card.h"
#include"Expenses.h"
#include <fstream>
#include<Windows.h>
#include <regex>
#include"Data.h"
#include<map>
#include"Function.h"
#include"menu.h"
using namespace std;
vector<int> GetDigitDate(const string Date)
{
	regex Rx("^(\\d{1,2}).(\\d{1,2}).(\\d{2}|\\d{4})$");
	smatch Match;
	if (!(regex_match(Date, Match, Rx) && (Match.size() == 4)))
		throw runtime_error("");
	return {stoi(Match[1]),stoi(Match[2]),stoi(Match[3]) };
}
void Show_card_hoder(vector<Card>Card_holder)
{
	int r = 1;
	for (int i = 0; i < Card_holder.size(); i++)
	{
		cout << "\n" << r << ". " << Card_holder[i];
		r++;
	}
}

int main()
{
	system("chcp 1251>nul");
	srand(time(NULL));
	int keys = 1, menu_order = 1, exit = 1;
	vector<Card>Card_holder;
	vector<Expenses>Expenses_Array, Expenses_Array1;
	Card q;
	vector<string> cat;
	string temp,temp1;
	Expenses exp,exp1, exp2;
	multimap< string, pair<string, double>, compare > rep, rep1, reps, reps1;
	multimap< string, pair<string, double> >::iterator itm, itm1;
	date data1, data2;

    exit1:
		show_menu(menu_order);
	
		while (exit)
		{
	
			switch ((keys = _getch()))
			{
	
			case KEY_UP:
				if (menu_order == 0)
				{
					menu_order = 1;
				}
				if (menu_order == 1)
				{
					menu_order = 10;
				}
				else menu_order--;
				show_menu(menu_order);
				break;
			case KEY_DOWN:
				if (menu_order == 10)
				{
					menu_order = 1;
				}
				else
					menu_order++;
				show_menu(menu_order);
				break;
			case KEY_ENTER:
				system("CLS");
				switch (menu_order)
	
				{
					case 1:
						{
						ifstream fin("Card_holder_binary.txt", ios::binary);
						if (fin)
						{
							size_t s2;
							fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
							Card_holder.resize(s2);
							for (int i = 0; i < s2; i++)
							{
								fin >> Card_holder[i];
							}
							fin.close();
						}
						else
						{
							cout << "\nEror read from the file" << endl;
						}
						Show_card_hoder(Card_holder);
						}
						_getch();
						goto exit1;
						
					    case 2:
					    {
							ifstream fin("Card_holder_binary.txt", ios::binary);
							if (fin)
							{
								size_t s2;
								fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
								Card_holder.resize(s2);
								for (int i = 0; i < s2; i++)
								{
									fin >> Card_holder[i];
								}
								fin.close();
							}
							else
							{
								cout << "\nEror read from the file" << endl;
							}
							Show_card_hoder(Card_holder);
					   exit:
						cin >> q;
						cin.get();
						if (Card_holder.size())
						{
							for (int i = 0; i < Card_holder.size(); i++)
							{
								if (Card_holder[i] == q)
								{
									cout << "\nThis card exists! Enter another card number!!!";
									goto exit;
								}
							}

							Card_holder.push_back(q);
						}
						else
						{

							Card_holder.push_back(q);
						}
						system("CLS");
						Show_card_hoder(Card_holder);
						_getch();
						
						ofstream fout("Card_holder_binary.txt", ios::binary);
						if (fout)
						{
							size_t s = Card_holder.size();
							fout.write(reinterpret_cast<char*>(&s), sizeof(s));
							for (const auto x : Card_holder)
							{
								fout << x;
							}
							fout.close();
						}
						else
						{
							cout << "\nEror write in the file" << endl;
						}
					    }											
						goto exit1;

					case 3:
					{
						ifstream fin("Card_holder_binary.txt", ios::binary);
						if (fin)
						{
							size_t s2;
							fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
							Card_holder.resize(s2);
							for (int i = 0; i < s2; i++)
							{
								fin >> Card_holder[i];
							}
							fin.close();
						}
						else
						{
							cout << "\nEror read from the file" << endl;
						}
						system("CLS");
						Show_card_hoder(Card_holder);
						cout << "\nEnter pozition of the Card you want to change"<<endl;
						
					exit_1:
						int t;
						cin >> t;
						cin.get();
						if (t<1 || t>Card_holder.size())
						{
							cout << "\nYou entered wrong number of the Card pozition";
							goto exit_1;
						}
						else
						{
							cout << "\nEnter new Card number you choose" << endl;
							getline(cin, temp);
							cin.get();
							Card_holder[t - 1].Modify_card_by_poz(temp);
						}
						system("CLS");
						Show_card_hoder(Card_holder);
					    _getch();
						ofstream fout("Card_holder_binary.txt", ios::binary);
						if (fout)
						{
							size_t s = Card_holder.size();
							fout.write(reinterpret_cast<char*>(&s), sizeof(s));
							for (const auto x : Card_holder)
							{
								fout << x;
							}
							fout.close();
						}
						else
						{
							cout << "\nEror write in the file" << endl;
						}
					}

					goto exit1;
					case 4:
					{
						ifstream fin("Card_holder_binary.txt", ios::binary);
						if (fin)
						{
							size_t s2;
							fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
							Card_holder.resize(s2);
							for (int i = 0; i < s2; i++)
							{
								fin >> Card_holder[i];
							}
							fin.close();
						}
						else
						{
							cout << "\nEror read from the file" << endl;
						}
						system("CLS");
						Show_card_hoder(Card_holder);
						cout << "\nEnter pozition of the Card you want to delete" << endl;
					exit_11:
						int t;
						cin >> t;
						cin.get();
						if (t<1 || t>Card_holder.size())
						{
							cout << "\nYou entered wrong number of the Card pozition";
							goto exit_11;
						}
						else
						{
							Card_holder.erase(Card_holder.begin() + (t - 1));
						
						}
						system("CLS");
						Show_card_hoder(Card_holder);
						_getch();
						ofstream fout("Card_holder_binary.txt", ios::binary);
						if (fout)
						{
							size_t s = Card_holder.size();
							fout.write(reinterpret_cast<char*>(&s), sizeof(s));
							for (const auto x : Card_holder)
							{
								fout << x;
							}
							fout.close();
						}
						else
						{
							cout << "\nEror write in the file" << endl;
						}
					}

					goto exit1;
	
					case 5:
					{
						ifstream fin("Card_holder_binary.txt", ios::binary);
						if (fin)
						{
							size_t s2;
							fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
							Card_holder.resize(s2);
							for (int i = 0; i < s2; i++)
							{
								fin >> Card_holder[i];
							}
							fin.close();
						}
						else
						{
							cout << "\nEror read from the file" << endl;
						}
					exit11:
						Show_card_hoder(Card_holder);
						cout << "\nÑhoose the card you want to top up with money. Enter number of the card pozition";
						int t;					
						cin >> t;
						cin.get();
						if (t<1 || t>Card_holder.size())
						{
							cout << "\nYou entered wrong number of the card pozition";
							_getch();
							goto exit11;
						
						}
						else
						{
							double t1;
							cout << "\nEnter amount of money we want to top up the card" << endl;
							cin >> t1;
							if (t1 <= 0)
							{
								cout << "\nYou entered wrong amount of money. It must be bigger then 0!!!";
							}
							else
							{
								Card_holder[t - 1].Add_money(t1);
							}
						}
						system("CLS");
						Show_card_hoder(Card_holder);
						_getch();
						ofstream fout("Card_holder_binary.txt", ios::binary);
						if (fout)
						{
							size_t s = Card_holder.size();
							fout.write(reinterpret_cast<char*>(&s), sizeof(s));
							for (const auto x : Card_holder)
							{
								fout << x;
							}
							fout.close();
						}
						else
						{
							cout << "\nEror write in the file" << endl;
						}
					}
						_getch();
						goto exit1;
	
					case 6:
					    
					exit2:
						show_menu1(menu_order);
						while (exit)
						{

							switch ((keys = _getch()))
							{

							case KEY_UP:
								if (menu_order == 0)
								{
									menu_order = 1;
								}
								if (menu_order == 1)
								{
									menu_order = 5;
								}
								else menu_order--;
								show_menu1(menu_order);
								break;
							case KEY_DOWN:
								if (menu_order == 5)
								{
									menu_order = 1;
								}
								else
									menu_order++;
								show_menu1(menu_order);
								break;
							case KEY_ENTER:
								system("CLS");
								switch (menu_order)
								{


								case 1:
								{
									
									ifstream fin("List_categories_binary.txt", ios::binary);
									if (fin)
									{
										exp1.Delete_category();
										exp1.read_category_file(fin);
										fin.close();
									}
									else
									{
										cout << "\nEror read from the file" << endl;
									}
									exp1.Show_List_Category();
									ofstream fout("List_categories_binary.txt", ios::binary);
									if (fout)
									{
										exp1.save_category_file(fout);
										fout.close();
									}
									else
									{
										cout << "\nEror write in the file" << endl;
									}
								}
									_getch();
									goto exit2;
								case 2:
								{
									ifstream fin("List_categories_binary.txt", ios::binary);
									if (fin)
									{
										exp1.Delete_category();
										exp1.read_category_file(fin);
										fin.close();
									}
									else
									{
										cout << "\nEror read from the file" << endl;
									}
									exp1.Show_List_Category();
									cout << "\nEnter category of expensies you want to add in the list" << endl;
									getline(cin, temp);
									exp1.Add_category(temp);

									ofstream fout("List_categories_binary.txt", ios::binary);
									if (fout)
									{
										exp1.save_category_file(fout);
										fout.close();
									}
									else
									{
										cout << "\nEror write in the file" << endl;
									}
									system("CLS");
									exp1.Show_List_Category();
								}
									_getch();

									goto exit2;

								case 3:
									{
									ifstream fin("List_categories_binary.txt", ios::binary);
									if (fin)
									{
										exp1.Delete_category();
										exp1.read_category_file(fin);
										fin.close();
									}
									else
									{
										cout << "\nEror read from the file" << endl;
									}
								exit11_1:
									system("CLS");
									exp1.Show_List_Category();
									cout << "\nEnter number of the category of expensies you want to modify in the list" << endl;
								
									int t;
									cin >> t;
									cin.get();
									if (t<1 || t>exp1.category_size())
									{
										cout << "\nYou entered wrong number of the category pozition";
										_getch();
										goto exit11_1;
									}
									else
									{										
										cout << "\nEnter new category name you choose" << endl;
										cin >> temp;
										cin.get();
										exp1.Modify_category_by_poz(t,temp);																		

									}													

									ofstream fout("List_categories_binary.txt", ios::binary);
									if (fout)
									{
										exp1.save_category_file(fout);
										fout.close();
									}
									else
									{
										cout << "\nEror write in the file" << endl;
									}
									system("CLS");
									exp1.Show_List_Category();
								}
									_getch();

									goto exit2;


								case 4:
								{
									ifstream fin("List_categories_binary.txt", ios::binary);
									if (fin)
									{
										exp1.Delete_category();
										exp1.read_category_file(fin);
										fin.close();
									}
									else
									{
										cout << "\nEror read from the file" << endl;
									}
								exit11_2:
									system("CLS");
									exp1.Show_List_Category();
									cout << "\nEnter number of the category of expensies you want to delete from the list" << endl;
									int t;
									cin >> t;
									cin.get();
									if (t<1 || t>exp1.category_size())
									{
										cout << "\nYou entered wrong number of the category pozition";
										_getch();
										goto exit11_2;
									}
									else
									{
										exp1.Delete_category_by_poz(t);

									}

									ofstream fout("List_categories_binary.txt", ios::binary);
									if (fout)
									{
										exp1.save_category_file(fout);
										fout.close();
									}
									else
									{
										cout << "\nEror write in the file" << endl;
									}
									system("CLS");
									exp1.Show_List_Category();
								}
								_getch();

								goto exit2;
								

								case 5:
									goto exit1;

								}
							}
						}
					case 7:
					{  ifstream fin("Card_holder_binary.txt", ios::binary);
						if (fin)
						{
							size_t s2;
							fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
							Card_holder.resize(s2);
							for (int i = 0; i < s2; i++)
							{
								fin >> Card_holder[i];
							}
							fin.close();
						}
						else
						{
							cout << "\nEror read from the file" << endl;
						}
					}
					{  
					exit111:
					system("CLS");
					Show_card_hoder(Card_holder);
					cout << "\nÑhoose the card reflect expenses. Enter number of the card pozition"<<endl;
					int t;
    				cin >> t;
					cin.get();
					if (t<1 || t>Card_holder.size())
					{
						cout << "\nYou entered wrong number of the card pozition";
						_getch();
						goto exit111;
					}
					else
					{
						double t1;
						cout << "\nEnter expenses you want to introduce" << endl;
						ifstream fin("List_categories_binary.txt", ios::binary);
						if (fin)
						{
							exp1.Delete_category();
							exp1.read_category_file(fin);
							fin.close();
						}
						else
						{
							cout << "\nEror read from the file" << endl;
						}

						{  ifstream fin("Expenses_Array_binary.txt", ios::binary);
						if (fin)
						{
							size_t s2;
							fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
							Expenses_Array.resize(s2);
							for (int i = 0; i < s2; i++)
							{
								fin >> Expenses_Array[i];
							}
							fin.close();
						}
						else
						{
							cout << "\nEror read from the file" << endl;
						}
						}

						for (const auto x : Expenses_Array)
						{
							cout << x;
						}
						
						cin >> exp1;
						Expenses_Array.push_back(exp1);
						t1 = exp1.get_suma();
						Card_holder[t - 1].Expenses(t1);
						for (const auto x : Expenses_Array)
						{
							cout << x;
						}

						ofstream fout("Expenses_Array_binary.txt", ios::binary);
						if (fout)
						{
							size_t s = Expenses_Array.size();
							fout.write(reinterpret_cast<char*>(&s), sizeof(s));
							for (const auto x : Expenses_Array)
							{
								fout << x;
							}
							cout << "\nWritten successfully" << endl;
							fout.close();
						}
						else
						{
							cout << "\nEror write in the file" << endl;
						}
						for (const auto x : Expenses_Array)
						{
							cout << x;
						}
						system("CLS");
						Show_card_hoder(Card_holder);
						_getch();
						{   ofstream fout("Card_holder_binary.txt", ios::binary);
							if (fout)
							{
								size_t s = Card_holder.size();
								fout.write(reinterpret_cast<char*>(&s), sizeof(s));
								for (const auto x : Card_holder)
								{
									fout << x;
								}
								
								fout.close();
							}
							else
							{
								cout << "\nEror write in the file" << endl;
							}
						}
					}
					}
						_getch();
						goto exit1;
					case 8:
					exit22:
						show_menu2(menu_order);
						while (exit)
						{

							switch ((keys = _getch()))
							{

							case KEY_UP:
								if (menu_order == 0)
								{
									menu_order = 1;
								}
								if (menu_order == 1)
								{
									menu_order = 4;
								}
								else menu_order--;
								show_menu2(menu_order);
								break;
							case KEY_DOWN:
								if (menu_order == 4)
								{
									menu_order = 1;
								}
								else
									menu_order++;
								show_menu2(menu_order);
								break;
							case KEY_ENTER:
								system("CLS");
								switch (menu_order)
								{
								case 1:
								{date data, data1, data2, dtemp;
								int day, month, year;
								bool tt = false;

								cout << "\nEnter the data" << endl;
								cin >> data;
								Expenses_Array1.clear();
								{
									ifstream fin("Expenses_Array_binary.txt", ios::binary);
									if (fin)
									{
										size_t s2;
										fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
										for (int i = 0; i < s2; i++)
										{
											fin >> exp1;
											{	ifstream fin("List_categories_binary.txt", ios::binary);
											if (fin)
											{

												exp1.Delete_category();
												exp1.read_category_file(fin);
												fin.close();
											}
											else
											{
												cout << "\nEror read from the file" << endl;
											}
											}
										
											Expenses_Array1.push_back(exp1);

										}

										fin.close();
									}
								}
								rep.clear();
								for (const auto x : Expenses_Array1)
								{

									vector<int> T = GetDigitDate(x.get_data());
									day = T[0];
									month = T[1];
									year = T[2];
									if (data.get_day() == day && data.get_month() == month && data.get_year() == year)
									{
										string t;
										int k, k1;
										double s = 0, s1 = 0;
										bool w = false, v = false;
										t = x.get_data();
										k = x.get_poz();
										s = x.get_suma();
										temp1 = x.get_category(k);
										if (!rep.size())
										{
											rep.emplace(t, pair<string, double>(temp1, s));
										}
										else
										{

											for (auto it = rep.begin(); it != rep.end(); it++)
											{
												if (it->first == t)
												{
													if (it->second.first == temp1)
													{
														s1 = it->second.second + s;
														it->second.second = s1;
														v = true;
													}
													w = true;
												}
											}

											if (!w)
											{
												rep.emplace(t, pair<string, double>(temp1, s));
											}
											if (!v)
											{
												rep.emplace(t, pair<string, double>(temp1, s));
											}

										}

										tt = true;
									}
								}
								if (!tt)
								{
									cout << "\nNo Expenses at the introduced DAY!!!" << endl;
									rep.clear();
								}
								if (rep.size())
								{
									cout << endl << endl;
									cout << setw(15) << left << "Data" << setw(35) << "Category" << setw(35) << "Suma" << endl << endl;
									for (const auto x : rep)
									{
										cout << setw(15) << left << x.first;
										cout << setw(35) << left << x.second.first;
										cout << setw(35) << left << x.second.second << endl;
									}

									FILE* file;
									errno_t err;

									err = fopen_s(&file, "Raport_day_txt.txt", "w");
									if (!err)
									{
										for (const auto x : rep)
										{
											fprintf(file, "\nData                        :  %s", x.first.c_str());
											fprintf(file, "\nCategory                    :  %s", x.second.first.c_str());
											fprintf(file, "\nSumma                       :  %f", x.second.second);
											fprintf(file, "\n================================================================");

										}
										printf("\nReport is written in the Raport_day_txt.txt file successfully\n\n");
										fclose(file);
									}
									else
									{
										printf("\nEror writting in the file");
									}
								}
								}
								_getch();
								goto exit22;
								case 2:									
								{date data, data1, data2, dtemp;
								int day, month, year;
								bool tt = false;
								cout << "\nEnter the period of dates" << endl;
								cin >> data1 >> data2;
								Expenses_Array1.clear();
								{
									ifstream fin("Expenses_Array_binary.txt", ios::binary);
									if (fin)
									{
										size_t s2;
										fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
										for (int i = 0; i < s2; i++)
										{
											fin >> exp1;
											{	ifstream fin("List_categories_binary.txt", ios::binary);
											if (fin)
											{

												exp1.Delete_category();
												exp1.read_category_file(fin);
												fin.close();
											}
											else
											{
												cout << "\nEror read from the file" << endl;
											}
											}

											Expenses_Array1.push_back(exp1);

										}

										fin.close();
									}
								}
							  
								if (data2 < data1)
								{
									dtemp = data2;
									data2 = data1;
									data1 = dtemp;
									rep.clear();
									for (const auto x : Expenses_Array1)
									{
										vector<int> T = GetDigitDate(x.get_data());
										day = T[0];
										month = T[1];
										year = T[2];
										date dtemp1(day, month, year);
										if (dtemp1 >= data1 && dtemp1 <= data2)
										{
											string t;
											int k, k1;
											double s = 0, s1 = 0;
											bool v = false;
											t = x.get_data();
											k = x.get_poz();
											s = x.get_suma();
											temp1 = x.get_category(k);
											if (!rep.size())
											{
												rep.emplace(t, pair<string, double>(temp1, s));
											}
											else
											{

												for (auto it = rep.begin(); it != rep.end(); it++)
												{
													if (it->first == t)
													{
														if (it->second.first == temp1)
														{
															s1 = it->second.second + s;
															it->second.second = s1;
															v = true;
														}
													
													}
												}
																							
												if (!v)
												{
													rep.emplace(t, pair<string, double>(temp1, s));
												}

											}

											tt = true;
										}
									}
									if (!tt)
									{
										cout << "\nNo Expenses at the introduced PERIOD!!!" << endl;
										rep.clear();
									}
									cout << endl << endl;
									if (rep.size())
									{
										cout << setw(15) << left << "Data" << setw(35) << "Category" << setw(35) << "Suma" << endl << endl;
										for (const auto x : rep)
										{
											
											cout << setw(15) << left << x.first;
											cout << setw(35) << left << x.second.first;
											cout << setw(35) << left << x.second.second << endl;
										}
										FILE* file;
										errno_t err;

										err = fopen_s(&file, "Raport_period_txt.txt", "w");
										if (!err)
										{
											for (const auto x : rep)
											{
												fprintf(file, "\nData                        :  %s", x.first.c_str());
												fprintf(file, "\nCategory                    :  %s", x.second.first.c_str());
												fprintf(file, "\nSumma                       :  %f", x.second.second);
												fprintf(file, "\n================================================================");

											}
											printf("\nReport is written in the Raport_period_txt.txt file successfully\n\n");
											fclose(file);
										}
										else
										{
											printf("\nEror writting in the file");
										}
									}
								}
								else
								{
									rep.clear();
									for (const auto x : Expenses_Array1)
									{

										vector<int> T = GetDigitDate(x.get_data());
										day = T[0];
										month = T[1];
										year = T[2];
										date dtemp1(day, month, year);
										if (dtemp1 >= data1 && dtemp1 <= data2)
										{
											string t;
											int k, k1;
											double s = 0, s1 = 0;
											bool v = false;
											t = x.get_data();
											k = x.get_poz();
											s = x.get_suma();
											temp1 = x.get_category(k);
											if (!rep.size())
											{
												rep.emplace(t, pair<string, double>(temp1, s));
											}
											else
											{

												for (auto it = rep.begin(); it != rep.end(); it++)
												{
													if (it->first == t)
													{
														if (it->second.first == temp1)
														{
															s1 = it->second.second + s;
															it->second.second = s1;
															v = true;
															break;
														}													
													}
													
												}

												if (!v)
												{
													rep.emplace(t, pair<string, double>(temp1, s));
												}

											}

											tt = true;
										}
									}
									if (!tt)
									{
										cout << "\nNo Expenses at the introduced PERIOD!!!" << endl;
										rep.clear();
									}
									cout << endl << endl;
									if (rep.size())
									{
										cout << setw(15) << left << "Data" << setw(35) << "Category" << setw(35) << "Suma" << endl << endl;
										for (const auto x : rep)
										{
											cout << setw(15) << left << x.first;
											cout << setw(35) << left << x.second.first;
											cout << setw(35) << left << x.second.second << endl;
										}
										FILE* file;
										errno_t err;

										err = fopen_s(&file, "Raport_period_txt.txt", "w");
										if (!err)
										{
											for (const auto x : rep)
											{
												fprintf(file, "\nData                        :  %s", x.first.c_str());
												fprintf(file, "\nCategory                    :  %s", x.second.first.c_str());
												fprintf(file, "\nSumma                       :  %f", x.second.second);
												fprintf(file, "\n================================================================");

											}
											printf("\nReport is written in the Raport_period_txt.txt file successfully\n\n");
											fclose(file);
										}
										else
										{
											printf("\nEror writting in the file");
										}
									}
								}

								}
								_getch();
								goto exit22;
								case 3:
								{date data, data1, data2, dtemp;
								int day, month, year;
								bool tt = false;
								Expenses_Array1.clear();
								{
									ifstream fin("Expenses_Array_binary.txt", ios::binary);
									if (fin)
									{
										size_t s2;
										fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
										for (int i = 0; i < s2; i++)
										{
											fin >> exp1;
											{	ifstream fin("List_categories_binary.txt", ios::binary);
											if (fin)
											{

												exp1.Delete_category();
												exp1.read_category_file(fin);
												fin.close();
											}
											else
											{
												cout << "\nEror read from the file" << endl;
											}
											}

											Expenses_Array1.push_back(exp1);

										}

										fin.close();
									}
								}
								cout << "\nEnter the month" << endl;
								data.init_month();
								rep.clear();
								for (const auto x : Expenses_Array1)
								{

									vector<int> T = GetDigitDate(x.get_data());
									day = T[0];
									month = T[1];
									year = T[2];
									if (data.get_month() == month)
									{
										string t;
										int k, k1;
										double s = 0, s1 = 0;
										bool  v = false;
										t = x.get_data();
										k = x.get_poz();
										s = x.get_suma();
										temp1 = x.get_category(k);
										if (!rep.size())
										{
											rep.emplace(t, pair<string, double>(temp1, s));
										}
										else
										{

											for (auto it = rep.begin(); it != rep.end(); it++)
											{
												if (it->first == t)
												{
													if (it->second.first == temp1)
													{
														s1 = it->second.second + s;
														it->second.second = s1;
														v = true;
														break;
													}
												
												}
											}

										
											if (!v)
											{
												rep.emplace(t, pair<string, double>(temp1, s));
											}

										}

										tt = true;
									}
								}
								if (!tt)
								{
									cout << "\nNo Expenses at the introduced MONTH!!!" << endl;
									rep.clear();
								}
								cout << endl << endl;
								if (rep.size())
								{
									cout << setw(15) << left << "Data" << setw(35) << "Category" << setw(35) << "Suma" << endl << endl;
									for (const auto x : rep)
									{
										cout << setw(15) << left << x.first;
										cout << setw(35) << left << x.second.first;
										cout << setw(35) << left << x.second.second << endl;
									}
									FILE* file;
									errno_t err;

									err = fopen_s(&file, "Raport_month_txt.txt", "w");
									if (!err)
									{
										for (const auto x : rep)
										{
											fprintf(file, "\nData                        :  %s", x.first.c_str());
											fprintf(file, "\nCategory                    :  %s", x.second.first.c_str());
											fprintf(file, "\nSumma                       :  %f", x.second.second);
											fprintf(file, "\n================================================================");

										}
										printf("\nReport is written in the Raport_month_txt.txt file successfully\n\n");
										fclose(file);
									}
									else
									{
										printf("\nEror writting in the file");
									}
								}
								}
									_getch();
									goto exit22;
								case 4:
								goto exit1;

								}
							}
						}

						
					case 9:
					exit222:
						show_menu3(menu_order);
						while (exit)
						{

							switch ((keys = _getch()))
							{

							case KEY_UP:
								if (menu_order == 0)
								{
									menu_order = 1;
								}
								if (menu_order == 1)
								{
									menu_order = 3;
								}
								else menu_order--;
								show_menu3(menu_order);
								break;
							case KEY_DOWN:
								if (menu_order == 3)
								{
									menu_order = 1;
								}
								else
									menu_order++;
								show_menu3(menu_order);
								break;
							case KEY_ENTER:
								system("CLS");
								switch (menu_order)
								{


								case 1:
								exit2222:
									show_menu4(menu_order);
									while (exit)
									{

										switch ((keys = _getch()))
										{

										case KEY_UP:
											if (menu_order == 0)
											{
												menu_order = 1;
											}
											if (menu_order == 1)
											{
												menu_order = 3;
											}
											else menu_order--;
											show_menu4(menu_order);
											break;
										case KEY_DOWN:
											if (menu_order == 3)
											{
												menu_order = 1;
											}
											else
												menu_order++;
											show_menu4(menu_order);
											break;
										case KEY_ENTER:
											system("CLS");
											switch (menu_order)
											{


											case 1:
												{date data, data1, data2, dtemp;
												int day, month, year;
												bool tt = false;
												Expenses_Array1.clear();
												{
													ifstream fin("Expenses_Array_binary.txt", ios::binary);
													if (fin)
													{
														size_t s2;
														fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
														for (int i = 0; i < s2; i++)
														{
															fin >> exp1;
															{	ifstream fin("List_categories_binary.txt", ios::binary);
															if (fin)
															{

																exp1.Delete_category();
																exp1.read_category_file(fin);
																fin.close();
															}
															else
															{
																cout << "\nEror read from the file" << endl;
															}
															}

															Expenses_Array1.push_back(exp1);

														}

														fin.close();
													}
												}
												cout << "\nEnter the period of dates" << endl;
												cin >> data1 >> data2;
												reps.clear();
												reps1.clear();
												if (data2 < data1)
												{
													dtemp = data2;
													data2 = data1;
													data1 = dtemp;

													if (Expenses_Array1.size())
													{
														for (const auto x : Expenses_Array1)
														{

															vector<int> T = GetDigitDate(x.get_data());
															day = T[0];
															month = T[1];
															year = T[2];
															date dtemp1(day, month, year);
															if (dtemp1 >= data1 && dtemp1 <= data2)
															{
																string t;
																int k, k1;
																double s = 0, s1 = 0;
																bool w=false, v = false;
																t = x.get_data();
																k = x.get_poz();
																s = x.get_suma();
																temp1 = x.get_category(k);
																reps.emplace(t, pair<string, double>(temp1, s));

															}
														}
													}
													else
													{
														cout << "\nNo Expenses at the introduced PERIOD!!!" << endl;
													}
													cout << endl << endl;
													if (reps.size())
													{
														if (reps.size() <= 3)
														{
													
															for (const auto x : reps)
															{
																reps1.emplace(x);
															}
															
														}
														else
														{
															double min = INT_MAX;
															int k = 0;
															bool u = false;

															for (itm = reps.begin(); k != 3; ++itm)
															{

																reps1.emplace(*itm);
																k++;

															}
															for (const auto x : reps1)
															{

																if (x.second.second < min)
																{
																	min = x.second.second;
																}
															}
															itm = reps.begin();
															for (advance(itm, 3); itm != reps.end(); ++itm)
															{
																if (u)
																{
																	for (const auto x : reps1)
																	{

																		if (x.second.second < min)
																		{
																			min = x.second.second;
																		}
																	}
																	u = false;
																}
																if (itm->second.second > min)
																{
																	for (itm1 = reps1.begin(); itm1 != reps1.end(); ++itm1)
																	{
																		if (itm1->second.second == min)
																		{
																			reps1.erase(itm1);
																			reps1.emplace(*itm);
																			min = INT_MAX;
																			u = true;
																			break;
																		}
																	}

																}
															}


														}

														cout << "\tTop 3 Expenses are :  " << endl;
														cout << setw(15) << left << "Data" << setw(35) << "Category" << setw(35) << "Suma" << endl << endl;
														for (const auto x : reps1)
														{

															cout << setw(15) << left << x.first;
															cout << setw(35) << left << x.second.first;
															cout << setw(35) << left << x.second.second << endl;
														}
													}


												}
												else
												{
													if (Expenses_Array1.size())
													{

														for (const auto x : Expenses_Array1)
														{

															vector<int> T = GetDigitDate(x.get_data());
															day = T[0];
															month = T[1];
															year = T[2];
															date dtemp1(day, month, year);
															if (dtemp1 >= data1 && dtemp1 <= data2)
															{
																string t;
																int k, k1;
																double s = 0, s1 = 0;
																bool w = false, v = false;
																t = x.get_data();
																k = x.get_poz();
																s = x.get_suma();
																temp1 = x.get_category(k);
																reps.emplace(t, pair<string, double>(temp1, s));
															}
														}
													}
													else
													{
														cout << "\nNo Expenses at the introduced PERIOD!!!" << endl;
													}
													if (reps.size())
													{
														if (reps.size() <= 3)
														{
															
															for (const auto x : reps)
															{
																reps1.emplace(x);
															}
														
														}
														else
														{
															double min = INT_MAX;
															int k = 0;
															bool u = false;

															for (itm = reps.begin(); k != 3; ++itm)
															{

																reps1.emplace(*itm);
																k++;

															}
															for (const auto x : reps1)
															{

																if (x.second.second < min)
																{
																	min = x.second.second;
																}
															}
															itm = reps.begin();
															for (advance(itm, 3); itm != reps.end(); ++itm)
															{
																if (u)
																{
																	for (const auto x : reps1)
																	{

																		if (x.second.second < min)
																		{
																			min = x.second.second;
																		}
																	}
																	u = false;
																}
																if (itm->second.second > min)
																{
																	for (itm1 = reps1.begin(); itm1 != reps1.end(); ++itm1)
																	{
																		if (itm1->second.second == min)
																		{
																			reps1.erase(itm1);
																			reps1.emplace(*itm);
																			min = INT_MAX;
																			u = true;
																			break;
																		}
																	}

																}
															}


														}


														cout << "\tTop 3 Expenses are :  " << endl;
														cout << setw(15) << left << "Data" << setw(35) << "Category" << setw(35) << "Suma" << endl << endl;
														for (const auto x : reps1)
														{

															cout << setw(15) << left << x.first;
															cout << setw(35) << left << x.second.first;
															cout << setw(35) << left << x.second.second << endl;
														}
													}
												}
												FILE* file;
												errno_t err;

												err = fopen_s(&file, "Raport_3Expenses(period).txt", "w");
												if (!err)
												{
													for (const auto x : reps1)
													{
														fprintf(file, "\nData                        :  %s", x.first.c_str());
														fprintf(file, "\nCategory                    :  %s", x.second.first.c_str());
														fprintf(file, "\nSumma                       :  %f", x.second.second);
														fprintf(file, "\n================================================================");

													}
													printf("\nReport is written in the txt file successfully\n\n");
													fclose(file);
												}
												else
												{
													printf("\nEror writting in the file");
												}
											}
												_getch();
												goto exit2222;
											case 2:

											{date data, data1, data2, dtemp;
											int day, month, year;
											bool tt = false;
											Expenses_Array1.clear();
											{
												ifstream fin("Expenses_Array_binary.txt", ios::binary);
												if (fin)
												{
													size_t s2;
													fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
													for (int i = 0; i < s2; i++)
													{
														fin >> exp1;
														{	ifstream fin("List_categories_binary.txt", ios::binary);
														if (fin)
														{

															exp1.Delete_category();
															exp1.read_category_file(fin);
															fin.close();
														}
														else
														{
															cout << "\nEror read from the file" << endl;
														}
														}

														Expenses_Array1.push_back(exp1);

													}

													fin.close();
												}
											}
											month = data.init_month_int();
											year = data.get_current_year();
											reps.clear();
											reps1.clear();
											if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
											{
												int data_1 = 1, data_2 = 31;

												data1.init_date2(data_1, month, year);
												data2.init_date2(data_2, month, year);

											}
											else if (month == 4 || month == 6 || month == 9 || month == 11)
											{
												int data_1 = 1, data_2 = 30;

												data1.init_date2(data_1, month, year);
												data2.init_date2(data_2, month, year);

											}
											else
											{
												if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
												{
													int data_1 = 1, data_2 = 29;
													data1.init_date2(data_1, month, year);
													data2.init_date2(data_2, month, year);
												}
												else
												{
													int data_1 = 1, data_2 = 28;
													data1.init_date2(data_1, month, year);
													data2.init_date2(data_2, month, year);
												}
											}

											
											
											{
												if (Expenses_Array1.size())
												{

													for (const auto x : Expenses_Array1)
													{

														vector<int> T = GetDigitDate(x.get_data());
														day = T[0];
														month = T[1];
														year = T[2];
														date dtemp1(day, month, year);
														if (dtemp1 >= data1 && dtemp1 <= data2)
														{
															string t;
															int k, k1;
															double s = 0, s1 = 0;
															bool w = false, v = false;
															t = x.get_data();
															k = x.get_poz();
															s = x.get_suma();
															temp1 = x.get_category(k);
															reps.emplace(t, pair<string, double>(temp1, s));
														}
													}
												}
												else
												{
													cout << "\nNo Expenses at the introduced PERIOD!!!" << endl;
												}
												if (reps.size())
												{
													if (reps.size() <= 3)
													{
														
														for (const auto x : reps)
														{
															reps1.emplace(x);
														}
													
													}
													else
													{
														double min = INT_MAX;
														int k = 0;
														bool u = false;

														for (itm = reps.begin(); k != 3; ++itm)
														{

															reps1.emplace(*itm);
															k++;

														}
														for (const auto x : reps1)
														{

															if (x.second.second < min)
															{
																min = x.second.second;
															}
														}
														itm = reps.begin();
														for (advance(itm, 3); itm != reps.end(); ++itm)
														{
															if (u)
															{
																for (const auto x : reps1)
																{

																	if (x.second.second < min)
																	{
																		min = x.second.second;
																	}
																}
																u = false;
															}
															if (itm->second.second > min)
															{
																for (itm1 = reps1.begin(); itm1 != reps1.end(); ++itm1)
																{
																	if (itm1->second.second == min)
																	{
																		reps1.erase(itm1);
																		reps1.emplace(*itm);
																		min = INT_MAX;
																		u = true;
																		break;
																	}
																}

															}
														}


													}

													cout << "\tTop 3 Expenses are :  " << endl;

													cout << setw(15) << left << "Data" << setw(35) << "Category" << setw(35) << "Suma" << endl << endl;
													for (const auto x : reps1)
													{

														cout << setw(15) << left << x.first;
														cout << setw(35) << left << x.second.first;
														cout << setw(35) << left << x.second.second << endl;
													}
												}
											}
											FILE* file;
											errno_t err;

											err = fopen_s(&file, "Raport_3Expenses(month).txt", "w");
											if (!err)
											{
												for (const auto x : reps1)
												{
													fprintf(file, "\nData                        :  %s", x.first.c_str());
													fprintf(file, "\nCategory                    :  %s", x.second.first.c_str());
													fprintf(file, "\nSumma                       :  %f", x.second.second);
													fprintf(file, "\n================================================================");

												}
												printf("\nReport is written in the txt file successfully\n\n");
												fclose(file);
											}
											else
											{
												printf("\nEror writting in the file");
											}
											}
											_getch();
											goto exit2222;

											
											case 3:
												goto exit222;

											}
										}
									}
							
								case 2:
								exit22222:
									show_menu4(menu_order);
									while (exit)
									{

										switch ((keys = _getch()))
										{

										case KEY_UP:
											if (menu_order == 0)
											{
												menu_order = 1;
											}
											if (menu_order == 1)
											{
												menu_order = 3;
											}
											else menu_order--;
											show_menu4(menu_order);
											break;
										case KEY_DOWN:
											if (menu_order == 3)
											{
												menu_order = 1;
											}
											else
												menu_order++;
											show_menu4(menu_order);
											break;
										case KEY_ENTER:
											system("CLS");
											switch (menu_order)
											{


											case 1:
											{date data, data1, data2, dtemp;
											int day, month, year;
											bool tt = false;
											Expenses_Array1.clear();
											{
												ifstream fin("Expenses_Array_binary.txt", ios::binary);
												if (fin)
												{
													size_t s2;
													fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
													for (int i = 0; i < s2; i++)
													{
														fin >> exp1;
														{	ifstream fin("List_categories_binary.txt", ios::binary);
														if (fin)
														{

															exp1.Delete_category();
															exp1.read_category_file(fin);
															fin.close();
														}
														else
														{
															cout << "\nEror read from the file" << endl;
														}
														}

														Expenses_Array1.push_back(exp1);

													}

													fin.close();
												}
											}
											cout << "\nEnter the period of dates" << endl;
											cin >> data1 >> data2;
											rep.clear();
											rep1.clear();
											if (data2 < data1)
											{
												dtemp = data2;
												data2 = data1;
												data1 = dtemp;
												cout << data1 << data2;
												for (const auto x : Expenses_Array1)
												{

													vector<int> T = GetDigitDate(x.get_data());
													day = T[0];
													month = T[1];
													year = T[2];
													date dtemp1(day, month, year);
													if (dtemp1 >= data1 && dtemp1 <= data2)
													{
														string t;
														int k, k1;
														double s = 0, s1 = 0;
														bool v = false;
														t = x.get_data();
														k = x.get_poz();
														s = x.get_suma();
														temp1 = x.get_category(k);
														if (!rep.size())
														{
															rep.emplace(t, pair<string, double>(temp1, s));
														}
														else
														{

															for (auto it = rep.begin(); it != rep.end(); it++)
															{
																if (it->first == t)
																{
																	if (it->second.first == temp1)
																	{
																		s1 = it->second.second + s;
																		it->second.second = s1;
																		v = true;
																		break;
																	}
																
																}
															}
																														
															if (!v)
															{
																rep.emplace(t, pair<string, double>(temp1, s));
															}

														}

														tt = true;
													}
												}
												if (!tt)
												{
													cout << "\nNo Expenses at the introduced PERIOD!!!" << endl;
													rep.clear();
												}
												cout << endl << endl;
												if (rep.size() <= 3)
												{
													
													rep1.clear();
													for (const auto x : rep)
													{
														bool t = false;
														for (const auto y : rep1)
														{
															if (x.second.first == y.second.first)
															{
																t = true;
															}
														}
														if (!t)
														{
															rep1.emplace(x);
														}
													}
										
												}
												else
												{
													double min = INT_MAX;
													int k = 0;
													bool u = false, t = false, l = false;
													for (itm = rep.begin(); itm != rep.end(); ++itm)
													{
														for (const auto y : rep1)
														{
															if (itm->second.first == y.second.first)
															{
																t = true;
															}
														}
														if (!t)
														{
															rep1.emplace(*itm);
															k++;
															t = false;
														}

														if (k == 3)
														{
															break;
														}

													}
													for (const auto x : rep1)
													{

														if (x.second.second < min)
														{
															min = x.second.second;
														}
													}

													for (rep.begin(); itm != rep.end(); ++itm)
													{
														if (u)
														{
															for (const auto x : rep1)
															{

																if (x.second.second < min)
																{
																	min = x.second.second;
																}
															}
															u = false;
														}
														if (itm->second.second > min)
														{
															l = false;
															for (itm1 = rep1.begin(); itm1 != rep1.end(); ++itm1)
															{
																if (itm1->second.first == itm->second.first)
																{
																	l = true;
																	break;
																}
															}
															if (!l)
															{
																for (itm1 = rep1.begin(); itm1 != rep1.end(); ++itm1)
																{
																	if (itm1->second.second == min)
																	{
																		rep1.erase(itm1);
																		rep1.emplace(*itm);
																		min = INT_MAX;
																		u = true;
																		break;
																	}
																}
															}

														}
													}
												}
												cout << "\tTop 3 Categories are :  " << endl;

												for (const auto x : rep1)
												{
													cout << setw(15) << left << x.first;
													cout << setw(35) << left << x.second.first;
													cout << setw(35) << left << x.second.second << endl;
												}

											}
											else
											{

												for (const auto x : Expenses_Array1)
												{

													vector<int> T = GetDigitDate(x.get_data());
													day = T[0];
													month = T[1];
													year = T[2];
													date dtemp1(day, month, year);
													if (dtemp1 >= data1 && dtemp1 <= data2)
													{
														string t;
														int k, k1;
														double s = 0, s1 = 0;
														bool  v = false;
														t = x.get_data();
														k = x.get_poz();
														s = x.get_suma();
														temp1 = x.get_category(k);
														if (!rep.size())
														{
															rep.emplace(t, pair<string, double>(temp1, s));
														}
														else
														{

															for (auto it = rep.begin(); it != rep.end(); it++)
															{
																if (it->first == t)
																{
																	if (it->second.first == temp1)
																	{
																		s1 = it->second.second + s;
																		it->second.second = s1;
																		v = true;
																		break;
																	}
																
																}
															}
														
															if (!v)
															{
																rep.emplace(t, pair<string, double>(temp1, s));
															}

														}

														tt = true;
													}
												}
												if (!tt)
												{
													cout << "\nNo Expenses at the introduced PERIOD!!!" << endl;
												}
												cout << endl << endl;
												if (rep.size() <= 3)
												{
													
													for (const auto x : rep)
													{
														bool t = false;
														for (const auto y : rep1)
														{
															if (x.second.first == y.second.first)
															{
																t = true;
															}
														}
														if (!t)
														{
															rep1.emplace(x);
														}
													}
										
												}
												else
												{
													double min = INT_MAX;
													int k = 0;
													bool u = false, t = false, l = false;
													for (itm = rep.begin(); itm != rep.end(); ++itm)
													{
														for (const auto y : rep1)
														{
															if (itm->second.first == y.second.first)
															{
																t = true;
															}
														}
														if (!t)
														{
															rep1.emplace(*itm);
															k++;
															t = false;
														}

														if (k == 3)
														{
															break;
														}

													}
													for (const auto x : rep1)
													{

														if (x.second.second < min)
														{
															min = x.second.second;
														}
													}

													for (rep.begin(); itm != rep.end(); ++itm)
													{
														if (u)
														{
															for (const auto x : rep1)
															{

																if (x.second.second < min)
																{
																	min = x.second.second;
																}
															}
															u = false;
														}
														if (itm->second.second > min)
														{
															l = false;
															for (itm1 = rep1.begin(); itm1 != rep1.end(); ++itm1)
															{
																if (itm1->second.first == itm->second.first)
																{
																	l = true;
																	break;
																}
															}
															if (!l)
															{
																for (itm1 = rep1.begin(); itm1 != rep1.end(); ++itm1)
																{
																	if (itm1->second.second == min)
																	{
																		rep1.erase(itm1);
																		rep1.emplace(*itm);
																		min = INT_MAX;
																		u = true;
																		break;
																	}
																}
															}

														}
													}
												}
												cout << "\tTop 3 Categories are :  " << endl;

												for (const auto x : rep1)
												{
													cout << setw(15) << left << x.first;
													cout << setw(35) << left << x.second.first;
													cout << setw(35) << left << x.second.second << endl;
												}
											}
											FILE* file;
											errno_t err;

											err = fopen_s(&file, "Raport_3Categories(period).txt", "w");
											if (!err)
											{
												for (const auto x : reps1)
												{
													fprintf(file, "\nData                        :  %s", x.first.c_str());
													fprintf(file, "\nCategory                    :  %s", x.second.first.c_str());
													fprintf(file, "\nSumma                       :  %f", x.second.second);
													fprintf(file, "\n================================================================");

												}
												printf("\nReport is written in the txt file successfully\n\n");
												fclose(file);
											}
											else
											{
												printf("\nEror writting in the file");
											}


											_getch();
											goto exit22222;
											}
											case 2:
											{
												{date data, data1, data2, dtemp, data11;
												int day, month, year;
												bool tt = false;
												Expenses_Array1.clear();
												{
													ifstream fin("Expenses_Array_binary.txt", ios::binary);
													if (fin)
													{
														size_t s2;
														fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
														for (int i = 0; i < s2; i++)
														{
															fin >> exp1;
															{	ifstream fin("List_categories_binary.txt", ios::binary);
															if (fin)
															{

																exp1.Delete_category();
																exp1.read_category_file(fin);
																fin.close();
															}
															else
															{
																cout << "\nEror read from the file" << endl;
															}
															}

															Expenses_Array1.push_back(exp1);

														}

														fin.close();
													}
												}
											
												month=data.init_month_int();
												year = data.get_current_year();
												rep.clear();
												rep1.clear();
												if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
												{
													int data_1 = 1, data_2=31;

													data1.init_date2(data_1, month, year);
													data2.init_date2(data_2, month, year);
													
												}
												else if (month == 4 || month == 6 || month == 9 || month == 11)
												{
													int data_1 = 1, data_2 = 30;

													data1.init_date2(data_1, month, year);
													data2.init_date2(data_2, month, year);

												}
												else
												{
													if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
													{
														int data_1 = 1, data_2 = 29;
														data1.init_date2(data_1, month, year);
														data2.init_date2(data_2, month, year);
													}
													else
													{													
															int data_1 = 1, data_2 = 28;
															data1.init_date2(data_1, month, year);
															data2.init_date2(data_2, month, year);													
													}
												}

											
											
												
												for (const auto x : Expenses_Array1)
													{

														vector<int> T = GetDigitDate(x.get_data());
														day = T[0];
														month = T[1];
														year = T[2];
														date dtemp1(day, month, year);												
														if (dtemp1 >= data1 && dtemp1 <= data2)
														{
															string t;
															int k, k1;
															double s = 0, s1 = 0;
															bool v = false;
															t = x.get_data();
															k = x.get_poz();
															s = x.get_suma();
															temp1 = x.get_category(k);
															if (!rep.size())
															{
																rep.emplace(t, pair<string, double>(temp1, s));
															}
															else
															{

																for (auto it = rep.begin(); it != rep.end(); it++)
																{
																	if (it->first == t)
																	{
																		if (it->second.first == temp1)
																		{
																			s1 = it->second.second + s;
																			it->second.second = s1;
																			v = true;
																			break;
																		}
																		
																	}
																}

															
																if (!v)
																{
																	rep.emplace(t, pair<string, double>(temp1, s));
																}

															}

															tt = true;
														}
													}
													if (!tt)
													{
														cout << "\nNo Expenses at the introduced PERIOD!!!" << endl;
														rep.clear();
													}
													cout << endl << endl;
													if (rep.size() <= 3)
													{
														
														rep1.clear();
														for (const auto x : rep)
														{
															bool t = false;
															for (const auto y : rep1)
															{
																if (x.second.first == y.second.first)
																{
																	t = true;
																}
															}
															if (!t)
															{
																rep1.emplace(x);
															}
														}
											
													}
													else
													{
														double min = INT_MAX;
														int k = 0;
														bool u = false, t = false, l = false;
														for (itm = rep.begin(); itm != rep.end(); ++itm)
														{
															for (const auto y : rep1)
															{
																if (itm->second.first == y.second.first)
																{
																	t = true;
																}
															}
															if (!t)
															{
																rep1.emplace(*itm);
																k++;
																t = false;
															}

															if (k == 3)
															{
																break;
															}

														}
														for (const auto x : rep1)
														{

															if (x.second.second < min)
															{
																min = x.second.second;
															}
														}

														for (rep.begin(); itm != rep.end(); ++itm)
														{
															if (u)
															{
																for (const auto x : rep1)
																{

																	if (x.second.second < min)
																	{
																		min = x.second.second;
																	}
																}
																u = false;
															}
															if (itm->second.second > min)
															{
																l = false;
																for (itm1 = rep1.begin(); itm1 != rep1.end(); ++itm1)
																{
																	if (itm1->second.first == itm->second.first)
																	{
																		l = true;
																		break;
																	}
																}
																if (!l)
																{
																	for (itm1 = rep1.begin(); itm1 != rep1.end(); ++itm1)
																	{
																		if (itm1->second.second == min)
																		{
																			rep1.erase(itm1);
																			rep1.emplace(*itm);
																			min = INT_MAX;
																			u = true;
																			break;
																		}
																	}
																}

															}
														}
													}
													cout << "\tTop 3 Categories are :  " << endl;

													for (const auto x : rep1)
													{
														cout << setw(15) << left << x.first;
														cout << setw(35) << left << x.second.first;
														cout << setw(35) << left << x.second.second << endl;
													
													}
													_getch();
												
												}
											}
											FILE* file;
											errno_t err;

											err = fopen_s(&file, "Raport_3Categories(month).txt", "w");
											if (!err)
											{
												for (const auto x : reps1)
												{
													fprintf(file, "\nData                        :  %s", x.first.c_str());
													fprintf(file, "\nCategory                    :  %s", x.second.first.c_str());
													fprintf(file, "\nSumma                       :  %f", x.second.second);
													fprintf(file, "\n================================================================");

												}
												printf("\nReport is written in the txt file successfully\n\n");
												fclose(file);
											}
											else
											{
												printf("\nEror writting in the file");
											}
											case 3:
												goto exit222;

											}
										}
									}
							
								case 3:
									goto exit1;

								}
							}
						}
					case 10:
					
						system("CLS");
						exit = 0;
						break;
					
				}
			}
		}





	







	_getch();
	return 0; 
}