#include <iostream>
#include <ctime>
#include <stdlib.h> 
using namespace std;
struct baum
{
	int date;
	baum *left;
	baum *right;
};
baum(*a[100]) = { NULL };
void balance(baum **root);
//первый элемент
baum *first(int a)
{
	baum *ptr = new baum;
	ptr->date = a;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
};
//добавление
baum *findplace(baum *root, int a, baum(*b[100]))
{

	int i = 0;
	for (i = 0; i < 100; i++)
	{
		b[i] = NULL;
	}
	baum *ptr = root;
	baum *pre = NULL;
	while (ptr != NULL)
	{
		pre = ptr;
		if (ptr->date == a) { return NULL; }
		if (a > ptr->date) { b[i] = ptr->right; ptr = ptr->right; }
		else {
			b[i] = ptr->left; ptr = ptr->left;
		}
		i++;

	};
	baum *now = new baum;
	now->date = a;
	now->left = NULL;
	now->right = NULL;
	i++;
	if (a < pre->date) {
		pre->left = now; b[i] = pre->left;
	}
	else { pre->right = now; b[i] = pre->right; }
	return now;
};
//определение высоты 
int hight(baum *root)
{
	if (root == NULL) return 0;
	int left, right, date;
	if (root->left != NULL)
	{
		left = hight(root->left);
	}
	else left = -1;
	if (root->right != NULL)
	{
		right = hight(root->right);
	}
	else right = -1;
	(right >= left ? date = right : date = left);
	return date + 1;
};
//функции вращения
void SL(baum **root)
{
	baum *ptr = (*root);
	baum *now = ptr->right;
	ptr->right = now->left;
	now->left = ptr;
	*root = now;

};
void SR(baum **root)
{
	baum *ptr = (*root);
	baum *now = ptr->left;
	ptr->left = now->right;
	now->right = ptr;
	*root = now;
};
void BL(baum **root)
{
	SR(&((*root)->right));
	SL(&(*root));
};
void BR(baum **root)
{
	SL(&((*root)->left));
	SR(&(*root));
};
void balance(baum **root)
{
	baum *ptr = *root;
	baum *now = NULL;
	if (hight(ptr->left) - hight(ptr->right) == -2)
	{
		now = ptr->right;
		(hight(now->left) - hight(now->right) == 1 ? BL(&(*root)) : SL(&(*root)));
	}
	else if (hight(ptr->left) - hight(ptr->right) == 2)
	{
		now = ptr->left;
		(hight(now->left) - hight(now->right) == -1 ? BR(&(*root)) : SR(&(*root)));
	};
};

void printer(baum *p, int level)
{
	if (p) {
		printer(p->left, level + 1);
		for (int i = 0; i < level; i++)cout << " ";
		cout << p->date << endl;
		printer(p->right, level + 1);
	};
};
baum *dooo()
{
	int k;
	int b[] = { 1, 3, 4, 5, 6, 7, 8, 10, 13 };
	baum *start = first(b[0]);
	baum *ptr = NULL;
	for (int i = 1; i <9; i++)
	{
		ptr = findplace(start, b[i], &a[100]);
		if (hight(start->left) - hight(start->right) > 1 || hight(start->left) - hight(start->right) < -1)
			balance(&start);
		
	};
	balance(&start->left->left);
	balance(&start->left);
	balance(&start->right->right);
	balance(&start->right);

	
	
	return start;
};
baum *sea(baum *root, baum(*b[100]), int a)
{
	baum *ptr = root;
	int i = 0;
	while (ptr->date != a)
	{
		if (ptr->date > a)
		{
			b[i] = ptr->right;
			ptr = ptr->right;
		}
		else if (ptr->date < a)
		{
			b[i] = ptr->left;
			ptr = ptr->left;
		}
                                              else break;
		i++;
	};

	return ptr;
};

void del(baum **root, baum(*b[100]), baum *ptr)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		if (b[i] == ptr) break;
	};
	baum *now;
	if (ptr->left == NULL && ptr->right == NULL)
	{
		delete ptr; now = b[i - 1]; now->left = now->right = NULL;
	}
	else 
	{
		baum *now;
		now = ptr->right;
		while (now->left->left != NULL)
			now = now->left;
		ptr->date = now->left->date;
		delete now->left;
		now->left = NULL;
	}
	while (i != 2)
	{
		now = b[i - 2];
		balance(&now);
		i--;
	};
};

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "веберете действие: 1.составить дерево поиска 2. добавить элемент 3.удалить элемент 4.задание: ";
	int num;
	bool err = true;
	cin >> num;
	baum* first = NULL;
	baum *now = NULL;
	while (err)
	{
		switch (num)
		{
		case 1:
		{
			first = dooo();
			printer(first, 0);
			break;
		};
		case 2:
		{
			cout << "введите значение: ";
			int b;
			cin >> b;
			now = findplace(first, b, (&a[100]));
			for (b = 0; b < 100; b++)
				if (a[b] == NULL) break;
			b = b - 3;
			while (b > 0)
			{
				balance(&first);
				b--;
			}
			printer(first, 0);
			break;
		};
		case 3:
		{
			cout << "введите значение: ";
			int b;
			cin >> b;
			now = sea(first, (&a[100]), b);
			del(&first, (&a[100]), now);
			for (b = 0; b < 100; b++)
				if (a[b] == NULL) break;
			b = b - 3;
			while (b > 0)
			{
				balance(&first);
				b--;
			}
			printer(first, 0);
			break;
		};
		case 4:
		{

			now = farst;
			int k;
			baum *max = farst;
			while (now->left != NULL)
				now = now->left;
			while (max->right != NULL)
				max = max->right;
			k = max->date;
			max->date = now->date;
			now->date = k;
			printer(farst, 0);	};
		default:err = false; break;
			break;
		}
	};
	system("pause");
	return 0;
}
