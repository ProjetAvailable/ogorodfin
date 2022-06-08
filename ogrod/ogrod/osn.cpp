#include <iostream>
#include <windows.h>
#include <string> 
#include <sstream>
using namespace std;
#include "Header.h"
#include <string> 
#include <fstream>
#include <thread>
#include <chrono>


string privetpoka(string c) {
	return "poka";
}
string privetpoka(int c) {
	return "privet";
}
class User {
protected:
	string Name;
	string GameNickname;
	string Path = "SAVE.txt";

public:
	User() {

	}

	User(string _Name, string _GameNickname) {
		Name = _Name;
		GameNickname = _GameNickname;
	}

	void Display() {
		cout << "���: " << Name << ". ������� �������: " << GameNickname << endl;
	}
};

class UserSave : User {
protected:
	int mon;
	string N;
	string GN;

public:
	UserSave() {

	}

	UserSave(int Rec, string S, string G) {
		mon = Rec;
		N = S;
		GN = G;
	}

	void Save() {
		ofstream SAV;
		SAV.open(Path, ofstream::app);

		if (!SAV.is_open()) {
			cout << "������ �����" << endl;
		}
		else {
			SAV << "��� ������: " << N << ". ������� ������� ������: " << GN << "MONEY: " << mon << endl;
		}
		SAV.close();
	}
};

using namespace N;

int main() {
	int a = 1;
	string b = "1";
	cout << privetpoka(a) << endl;
	cout << privetpoka(b);
	setlocale(LC_ALL, "rus");
	string nickk;
	cout << "\n����� ��� ���" << endl;
	cin >> nickk;
	string gnickk;
	cout << "����� ��� ������� ���" << endl;
	cin >> gnickk;
	setlocale(LC_ALL, "rus");
	User US(nickk, gnickk);
	US.Display();
	std::string s = "������ " + gnickk;
	s=s+"\n������� �� ������ ������ � �����";
	for (auto& x : s) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		std::cout << x;
	}
	std::cout << "\n";
	models memme;
	memme.ambar();
	//
	int sost[4][3];
	int posajeno[4][3] = {
		{-1,-1,-1},
		{-1,-1,-1},
		{-1,-1,-1},
		{-1,-1,-1}
	};
	int tim[4][3];
	int resursi[3]={0,0,0};
	//
	int pol[3];
	int whereyouare[2] = { 2,2 };
	int sostoianie = 0;
	int money = 175;
	
	string mapinfo[4][3] = {
		{"������ ����� x=1 y=1","������ ����� x=2 y=1","������ ����� x=3 y=1"},
		{"������ ����� x=1 y=2","����� x=2 y=2       ","������ ����� x=3 y=2"},
		{"������ ����� x=1 y=3","������ ����� x=2 y=3","������ ����� x=3 y=3"},
		{"����        x=1 y=4","������ ����� x=2 y=4","������ ����� x=3 y=4"}
	};
	int map[4][3] = {
		{0,0,0},
		{0,1,0},
		{0,0,0},
		{2,0,0}
	};

	
	while (true)
	{
		cout << endl << endl << "***MONEY***" << endl << endl << "   " << money;
		cout << endl << endl << "\t\t\t***MAP***" << endl << endl;
		for (int b = 0; b < 4; b++) {
			for (int i = 0; i < 3; i++) {
				cout << mapinfo[b][i] << "\t";
			}
			cout << endl;
		}
		if (sostoianie == 0) {
			cout << endl << endl << "����� ��������� x ";
			cin >> whereyouare[0];
			while (whereyouare[0] > 3 || whereyouare[0] < 1) {
				cout << endl << "�������� ��� ���";
				cout << endl << "����� ��������� x ";
				cin >> whereyouare[0];
			}


			cout << endl << "����� ��������� y ";
			cin >> whereyouare[1];
			while (whereyouare[1] > 4 || whereyouare[1] < 1) {
				cout << endl << "�������� ��� ���";
				cout << endl << "����� ��������� y " ;
				cin >> whereyouare[1];
			}
		}
		else {

		}
			
		ClearScreen();  // ������� �������
		cout << endl << endl;
		int s = map[whereyouare[1] - 1][whereyouare[0] - 1];
		cout << s;
		switch (s)
		{
		case 1:
			memme.ambar();
			break;
		case 2:
			memme.magaz();
			break;
		case 3:
			memme.melniza();
			break;
		case 4:
			memme.rostok();
			break;
		case 5:
			memme.zerno();
			break;

		case 6:
			memme.svinarnik();
			break;
		case 0:
			memme.zabor();
			break;
		}
		
		if (map[whereyouare[1] - 1][whereyouare[0] - 1] == 1) {
			cout <<endl<< "������ ����� �� ��������� ����� 0" << endl;
			int deistvie = 0;
			cin >> deistvie;
			if (deistvie == 0) {
				UserSave UU(money, nickk, gnickk);
				UU.Save();
				break;
			}
			cout << endl<<"1 ������� " << resursi[0] << endl << "2 ��������� " << resursi[1] << endl << "3 ���� " << resursi[2] << endl;
			Sleep(5000);
		}
		else if (map[whereyouare[1] - 1][whereyouare[0] - 1] == 2) {
			cout << endl << endl << "\t\t\t��� ������ �������?" << endl << endl;

			cout << "1 �������" << endl<<"����� 0 �����" << endl << "������ ����� �����" << endl;

			int deistvie = 0;
			cin >> deistvie;
			if (deistvie == 0) {
				UserSave UU(money, nickk, gnickk);
				UU.Save();
				break;
			}
			if (deistvie == 1) {
				cout << "��� ������ �������?" << endl << "���� ���������:" << endl;
				cout << "1 ������� " << resursi[0] << endl << "2 ��������� " << resursi[1] << endl << "3 ���� " << resursi[2] << endl << "������ ����� �����" << endl;
				cin >> deistvie;
				if (deistvie == 1) {
					cout << endl << "������� �� ������ �������" << endl;
					cin >> deistvie;
					if (deistvie > resursi[0]) {
						cout << endl << "��� ������� ��" << endl;
						Sleep(2000);
					}
					else {
						money = money + (5 * deistvie);
						resursi[0] = resursi[0] - deistvie;
						cout << endl << "�������" << endl;
						Sleep(2000);
					}
				}
				else if (deistvie == 2) {
					cout << endl << "������� �� ������ �������" << endl;
					cin >> deistvie;
					if (deistvie > resursi[1]) {
						cout << endl << "��� ������� ��" << endl;
						Sleep(2000);
					}
					else {
						money = money + (10 * deistvie);
						resursi[1] = resursi[1] - deistvie;
						cout << endl << "�������" << endl;
						Sleep(2000);
					}
				}
				else if (deistvie == 3) {
					cout << endl << "������� �� ������ �������" << endl;
					cin >> deistvie;
					if (deistvie > resursi[2]) {
						cout << endl << "��� ������� ��" << endl;
						Sleep(2000);
					}
					else {
						money = money + (15 * deistvie);
						resursi[2] = resursi[2] - deistvie;
						cout << endl << "�������" << endl;
						Sleep(2000);
					}
				}
				else {

				}
			}
			else {

			}
		}
		else {


			cout << endl << endl << "\t\t\t��� ������ �������?" << endl << endl;

			cout << "1 ������ ��� �� (���� ��� �� ����� ���� �� ���� �� ������ ������ :) )" << endl << "2 ������� �������" << endl << "3 ������ ������������ ��������" << endl << "����� 0 �����"<<endl<<"������ ����� �����" << endl;
			int deistvie = 0;
			cin >> deistvie;
			if (deistvie == 0) {
				UserSave UU(money, nickk, gnickk);
				UU.Save();
				break;
			}
			if (deistvie == 1) {
				cout << "��� ������ ������?" << endl << "1 ����" << endl << "2 ��������" << endl << "3 ���������" << endl << "������ ����� �����" << endl;
				cin >> deistvie;
				if (deistvie == 1) {

					if (money > 25) {
						map[whereyouare[1] - 1][whereyouare[0] - 1] = 5;
						int xx = whereyouare[0];
						int yy = whereyouare[1];
						string koord = "���� x=" + to_string(xx);
						koord = koord + " y=" + to_string(yy);
						mapinfo[whereyouare[1] - 1][whereyouare[0] - 1] = koord + "\t";
						money = money - 25;
						posajeno[whereyouare[1] - 1][whereyouare[0] - 1] = 0;
						cout << endl << "�������";
						Sleep(2000);
					}
					else {
						cout << endl << "���� �����";
						Sleep(2000);
					}

				}
				else if (deistvie == 2) {
					if (money > 50) {
						map[whereyouare[1] - 1][whereyouare[0] - 1] = 3;
						int xx = whereyouare[0];
						int yy = whereyouare[1];
						string koord = "�������� x=" + to_string(xx);
						koord = koord + " y=" + to_string(yy);
						mapinfo[whereyouare[1] - 1][whereyouare[0] - 1] = koord;
						money = money - 50;
						posajeno[whereyouare[1] - 1][whereyouare[0] - 1] = 0;
						cout << endl << "�������";
						Sleep(2000);
					}
					else {
						cout << endl << "���� �����";
						Sleep(2000);
					}
				}
				else if (deistvie == 3) {
					if (money > 100) {
						map[whereyouare[1] - 1][whereyouare[0] - 1] = 6;
						int xx = whereyouare[0];
						int yy = whereyouare[1];
						string koord = "��������� x=" + to_string(xx);
						koord = koord + " y=" + to_string(yy);
						mapinfo[whereyouare[1] - 1][whereyouare[0] - 1] = koord;
						money = money - 100;
						posajeno[whereyouare[1] - 1][whereyouare[0] - 1] = 0;
						cout << endl << "�������";
						Sleep(2000);
					}
					else {
						cout << endl << "���� �����";
						Sleep(2000);
					}
					cout << endl << "�������" << endl;
					Sleep(2000);
				}
				else {

				}
			}
			else if (deistvie == 2) {
				if (posajeno[whereyouare[1] - 1][whereyouare[0] - 1] == 1) {
					if (tim[whereyouare[1] - 1][whereyouare[0] - 1] >14) {
						if (map[whereyouare[1] - 1][whereyouare[0] - 1] = 3) {
							resursi[1]++;
							
						}
						else if (map[whereyouare[1] - 1][whereyouare[0] - 1] = 5) {
							resursi[0]++;
							map[whereyouare[1] - 1][whereyouare[0] - 1] = 5;
							cout << "q";
						}
						else if (map[whereyouare[1] - 1][whereyouare[0] - 1] = 6) {
							resursi[2]++;
						}
						posajeno[whereyouare[1] - 1][whereyouare[0] - 1] = 0;
						
						cout << endl << "�������" << endl;
						Sleep(2000);
					}
					else {
						cout << endl << "��� �� �������" << endl;
						Sleep(2000);
					}
				}
				else {
					cout <<endl<< "������ �� ��������"<<endl;
					Sleep(2000);
				}
			}
			else if (deistvie == 3) {
				if (posajeno[whereyouare[1] - 1][whereyouare[0] - 1] == 0) {
					if (map[whereyouare[1] - 1][whereyouare[0] - 1] = 4) {
						posajeno[whereyouare[1] - 1][whereyouare[0] - 1] = 1;
						tim[whereyouare[1] - 1][whereyouare[0] - 1] = 0;
						cout << endl << "������" << endl;
						Sleep(2000);
					}
					else if (map[whereyouare[1] - 1][whereyouare[0] - 1] = 3) {
						if (resursi[0] < 1) {
							cout << endl << "�� ������� �������� �������";
						}
						else {
							resursi[0]--;
							posajeno[whereyouare[1] - 1][whereyouare[0] - 1] = 1;
							tim[whereyouare[1] - 1][whereyouare[0] - 1] = 0;
							cout << endl << "������" << endl;
							Sleep(2000);
						}
					}
					else if (map[whereyouare[1] - 1][whereyouare[0] - 1] = 6) {
						if (resursi[1] < 1) {
							cout << endl << "�� ������� �������� ���������";
						}
						else {
							resursi[1]--;
							posajeno[whereyouare[1] - 1][whereyouare[0] - 1] = 1;
							tim[whereyouare[1] - 1][whereyouare[0] - 1] = 0;
							cout << endl << "������" << endl;
							Sleep(2000);
						}
						
					}
					
				}
				else if(posajeno[whereyouare[1] - 1][whereyouare[0] - 1] == -1) {
					cout << endl << "����" << endl;
					Sleep(2000);
				}
				else {
					cout << endl << "��� ��������" << endl;
					Sleep(2000);
				}
			}
			else {

			}
		}
		for (int i = 0; i < 4; i++) {
			for (int y = 0; y < 3; y++)
				tim[i][y]++;
		}
		for (int i = 0; i < 4; i++) {
			for (int y = 0; y < 3; y++)
				if (map[i][y] == 4 && tim[i][y] > 14 && posajeno[i][y] == 1) {
					
					map[i][y] == 5;
				}
		}
		ClearScreen();  // ������� �������

		
	}

	
	

	
	
}