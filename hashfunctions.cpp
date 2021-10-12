include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

string tabliza[2000];
int s4[2000] = { NULL };

void burnfile(string tab[2000]);

//���-�������
int h(char key[7])
{
	double adress = 0;
	int h = 0;
	double a = 0;
	for (int i = 0; i<6; i++)
		adress = adress + ((int)key[i] * pow(3, i));
	h = int(adress - 16055);
	while (h > 1999)
		h = h % 2000;
	return h;
};

//���� ����� � ����������
void input(char key[7])
{
	char tmp[256];
	bool alright = false;
	do
	{
		cin >> tmp;
		if (tmp[6] != NULL)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�������� ����, ��������� � ������� ������ :" << endl;
			continue;
		}
		else
		{
			for (int i = 0; i < 6; i++)
				key[i] = tmp[i];
			for (int i = 0; i < 6; i++)
			{
				if (i > 0 && i < 4)
				{
					if (((int)key[i] < 48) || ((int)key[i] > 57))
						alright = true;
				}
				else if (((int)key[i] < 65) || ((int)key[i] > 90))
					alright = true;


			};
			if (alright != false)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�������� ����, ��������� � ������� ������ :" << endl;
				continue;

			};
		};
	} while (alright);
};

//���������� ����� � ������� �������
void add(string tab[2000])
{
	int ad, k;
	char keis[7] = { NULL };
	cout << "������� ���� ������ :";
	input(keis);
	ad = h(keis);
	for (int i = 0; i < 2000; i++)
	{
		if (tab[i] == keis)
		{
			cout << "����� ���� ���� � �������" << endl;
			return;
		};
	};
	k = 0;
	do
	{
		if (tab[ad] != "")
		{
			k++;
			ad = ad + 2;
		}
		else
		{
			tab[ad] = keis;
			cout << "������� ��������" << endl;
			burnfile(tab);
			return;
		}
	} while (k<10);
	cout << "����� ������� ��������.. �� �����" << endl;
	return;
};

//������ � ���� (������������ ����� ������� ��������� �������
void burnfile(string tab[2000])
{
	ofstream file1;
	file1.open("table.txt");

	for (int i = 0; i < 2000; i++)
	{
		file1 << tab[i] << '\n';

	};
	file1.close();
};

//������� ��� �������� ������������ ���-�������, �� ������ ����������� ��������� ���������
void chekf()
{
	char key[7] = { NULL };
	int ad = 0;
	int i, j, k;
	srand((unsigned)time(0));
	for (i = 0; i < 2000; i++)
	{
		k = 1;
		for (j = 0; j < 6; j++)
		{
			if (j > 0 && j < 4)
				key[j] = (char)(rand() % 10 + 48);
			else
				key[j] = (char)(rand() % 26 + 65);
		};
		ad = h(key);
		s4[ad]++;
		
	};
	ofstream file1;
	file1.open("checkf.txt");

	for (int i = 0; i < 2000; i++)
	{
		file1 << s4[i] << '\n';

	};
	file1.close();
};

void table(int x)
{
	char key[7] = { NULL };
	int ad = 0;
	int i, j, k;
	
	srand((unsigned)time(0));
	for (i = 0; i < x; i++)
	{
		k = 0;
		for (j = 0; j < 6; j++)
		{
			if (j > 0 && j < 4)
				key[j] = (char)(rand() % 10 + 48);
			else
				key[j] = (char)(rand() % 26 + 65);
		};
		ad = h(key);
		while (k != 10)
		{
			if (tabliza[ad] != "")
			{
				k++;
				ad += 2;
			}
			else
			{
				tabliza[ad] = key;
				break;
			};
		};
	};
	burnfile(tabliza);
};

void find(string tab[2000])
{
	char key[7] = { NULL };
	cout << "������� ���� ������� ������ ����� :";
	input(key);
	for (int i = 0; i < 2000; i++)
	{
		if (tab[i] == key)
		{
			cout << "������� ������� :" << tab[i] << " ��� ������� :" << i << endl;
			return;
		};
	};
	cout << "���������� �������� ���" << endl;
	return;
};

void del(string tab[2000])
{
	char key[7] = { NULL };
	cout << "������� ���� ������� ������ ������� :";
	input(key);
	for (int i = 0; i < 2000; i++)
	{
		if (tab[i] == key)
		{
			tab[i] = "������� ������";
			cout << "������� ������" << endl;
			burnfile(tab);
			return;
		};
	};
	cout << "���������� �������� ���" << endl;
	return;
};

void out(string tab[200])
{
	for (int i = 0; i < 2000; i++)
		cout << i + 1 << '.' << tab[i] << endl;
	return;
};


int main()
{
	setlocale(LC_ALL, "rus");
	int i, menu, x;
	for (i = 0; i < 2000; i++)
	{
		s4[i] = 0;
		tabliza[i] = "";
	};
	chekf();
	do
	{
		cout << "���� :" << endl << "1.��������� ������������� ���-n������" << endl << "2. ���������� ��������" << endl << "3. ����� ��������" << endl << "4. �������� ��������" << endl << "5.����� �� �����" << endl << "6. ����� �� ���������" << endl;
		cin >> menu;
		
		switch (menu)
		{
		case 1: {
			cout << "������� ���������� ������ ��� ������������� :";
			cin >> x;
			table(x);
			break;
			};
		case 2: {add(tabliza); break; };
		case 3: {find(tabliza); break; };
		case 4: {del(tabliza); break; };
		case 5: {out(tabliza); break; };
		case 6: break;
		default: { cout << "������� ���������� ��������" << endl; break; };
				 break;
		};
	} while (menu != 5);
	system("pause");
	return 0;
};


#hash-function
int h(char key[7])
{
	double adress = 0;
	int h = 0;
	double a = 0;
	for (int i = 0; i<6; i++)
		adress = adress + ((int)key[i] * pow(3, i));
	h = int(adress - 16055);
	while (h > 1999)
		h = h % 2000;
	return h;
};
