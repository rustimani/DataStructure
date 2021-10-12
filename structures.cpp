#include <iostream>
using namespace std;
struct my
{
	int a;
	int n;
	my *next;
};

int fuct(my* mn, int i)
{
	my* now = mn;
	while (now != NULL)
	{
		if (now->n == i)
			return now->a;
		now = now->next;
	}
	return 0;
};

int main()
{
	setlocale(LC_ALL, "rus");
	
	my* mnog1=NULL;
	my* mnog2=NULL;
	my* pre = NULL;
	my* el = NULL;
	int N,N2;
	cout << "введите степень многочлена1: ";
	cin >> N;
	while (N < 0 || cin.fail())
	{
		cout << "введите степень многочлена1: ";
		cin >> N;

	};
	int A;
	for (int i = 0; i <= N; i++)
	{
		cout << "введите коэффицент а" << i << " : ";
		cin >> A;
		if (A == 0)
			continue;
		el = new my;
		el->a = A;
		el->n = i;
		el->next = NULL;
		if (mnog1 == NULL)
			mnog1 = el;
		else
			pre->next=el;
		pre = el;
	}
	el = mnog1;
	while (el != NULL)
	{
		cout << "коэфф: " << el->a << "  степень:" << el->n << endl;
		el = el->next;
	};
	system("pause");
	cout << "введите степень многочлена2: ";
	cin >> N2;
	while (N2 < 0 || cin.fail())
	{
		cout << "введите степень многочлена1: ";
		cin >> N2;

	};
	for (int i = 0; i <= N2; i++)
	{
		cout << "введите коэффицент а" << i << " : ";
		cin >> A;
		if (A == 0)
			continue;
		el = new my;
		el->a = A;
		el->n = i;
		el->next = NULL;
		if (mnog2 == NULL)
			mnog2 = el;
		else
			pre->next = el;
		pre = el;
	}
	el = mnog2;
	while (el != NULL)
	{
		cout << "коэфф: " << el->a << "  степень:" << el->n << endl;
		el = el->next;
	};
	my* res = NULL;
	int NN = (N > N2 ? N : N2);

	for (int i = 0; i <= NN; i++)
	{
		if (fuct(mnog1, i) + fuct(mnog2, i) == 0)
			continue;
		el = new my;
		el->a = fuct(mnog1, i) + fuct(mnog2, i);
		el->n = i;
		el->next = NULL;
		if (res == NULL)
			res = el;
		else
			pre->next = el;
		pre = el;
	};
	el = res;
       cout <<"результирующий Многочлен"<<endl;
	while (el != NULL)
	{
		cout << "коэфф: " << el->a << "  степень:" << el->n << endl;
		el = el->next;
	};
	system("pause");
	while (mnog1 != NULL)
	{
		el = mnog1->next;
		delete mnog1;
		mnog1 = el;
	};
	while (mnog2 != NULL)
	{
		el = mnog2->next;
		delete mnog2;
		mnog2 = el;
	};
	while (res != NULL)
	{
		el = res->next;
		delete res;
		res = el;
	};
	return 0;
}
