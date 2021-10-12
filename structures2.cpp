#include <iostream>
using namespace std;

struct line
{
	int task;
	line* next;
};

void out(line* first)
{
	line* el = NULL;
	int i;
	int b[3];
	for (i = 0; i < 3; i++)
		b[i] = 0;
	int p[3];
	for (i = 0; i < 3; i++)
		p[i] = 0;
	int time = 2;
	int stek[50];
	int top = 0;
	stek[top] = 11;
	el = first;
	int n;
	while (el != NULL)
	{
		for (i = 0; i < 3; i++)
		{
			if (p[i] == 1)
				b[i]++;
		};
		for (i = 0; i <= 2; i++)
	                   cout << "время исполнения на процессоре  после последнего действия " << i + 1 << " составляет :" << b[i] << endl;
		i = el->task;
		if (stek[top] != 11)
		{
			n = stek[top];
			if (p[n - 1] != 1)
			{
				p[n - 1] = 1;
				top--;
			};
		};
		if (p[i - 1] != 1)
		{
			p[i - 1] = 1;
			first = el->next;
			delete el;
			el = first;
		}
		else
		{
			top++;
			stek[top] = el->task;
			first = el->next;
			delete el;
			el = first;
		};
		for (i = 0; i < 3; i++)
		{
			if (b[i] == time)
			{
				p[i] = 0;
				b[i] = 0;
			};
		};
		
		cout << "состояние процессоров " << endl;
		for (i = 0; i <= 2; i++)
			cout << i << " :" << p[i] << endl;
		if (top != 11)
		{
			cout << "очередь процессов :" << endl;
			for (i = 1; i <= top; i++)
				cout << stek[i] << ", ";
		};
	};
};
int main()
{
	setlocale(LC_ALL, "rus");
	line* first = NULL;
	line* pre = NULL;
	line* el = NULL;
	int a=0;
	while (a != 666)
	{
		cout << "введите номер процесса (1, 2 или 3) или 666 для конца ввода: ";
		cin >> a;
		if (a == 666)
			break;
		while (a != 1 && a != 2 && a != 3 || cin.fail())
		{
			cout << "заново введите номер процесса (1, 2 или 3) или 666 для конца ввода: ";
			cin >> a;
		};
		el = new line;
		el->task = a;
		el->next = NULL;
		if (first == NULL)
			first = el;
		else
			pre->next = el;
		pre = el;
	};
	out(first);
	system("pause");
	return 0;
};
