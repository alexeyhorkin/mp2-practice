#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <ostream>
#include "TablesUnord.h"
#include "TablesOrdered.h"
#include "TablesHash.h"
using namespace std;

int main()
{
	int c = 0;
	int k;
	int SIZE;

	cout << "Create table, please enter size of table" << endl;
	cin >> SIZE;
	TableUnord<string, Polinom> A(SIZE);
	TableOrdered<string, Polinom> B(SIZE);
	HashTable<string, Polinom> C(SIZE);

	while (c != 1)
	{
		system("cls");
		cout << "Chouse operation" << endl;
		cout << "1 - Insert" << endl;
		cout << "2 - Dell" << endl;
		cout << "3 - Search" << endl;
		cout << "4 - Print" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			string str;
			cout << "Write your Polinom" << endl;
			cin >> str;
			Polinom a(str);
			A.Insert(str, a);
			B.Insert(str, a);
			C.Insert(str, a);
			cout << "Unordered :" << endl;
			cout << A << endl;
			cout << "Ordered :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		case 2:
		{
			string str;
			cout << "Write your Polinom" << endl;
			cin >> str;
			Polinom a(str);
			A.Dell(str);
			B.Dell(str);
			C.Dell(str);
			cout << "Unordered :" << endl;
			cout << A << endl;
			cout << "Ordered :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		case 3:
		{
			string str;
			cout << "Write your Polinom" << endl;
			cin >> str;
			Polinom a(str);
			if (A.Search(str) == NULL)
				cout << "Element doesn't exest"<< endl;
			else cout << " You have found " << A.Search(str)->Data;
			if (B.Search(str) == NULL)
				cout << "Element doesn't exest"<<endl;
			else cout << " You have found " << B.Search(str)->Data;
			if (C.Search(str) == NULL)
				cout << "Element doesn't exest"<<endl;
			else cout << " You have found " << C.Search(str)->Data;
			break;
		}
		case 4:
		{
			cout << "Unordered :" << endl;
			cout << A << endl;
			cout << "Ordered :" << endl;
			cout << B << endl;
			cout << "Hash :" << endl;
			cout << C << endl;
			break;
		}
		default:
		{
			cout << "ERROR, choose again" << endl;
			break;
		}
		}

		cout << "Exit - 1" << endl;
		cin >> c;
	}
	return 0;
}