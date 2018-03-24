#pragma once
#include <string>
#include "list.h"
#include "monom.h"
using namespace std;
class Polinom
{
public:
	Polinom(const string &A ="");
	void Insert(const Node<monom> A);
	~Polinom();
	Node<monom> * GetH() const;
	ListRing<monom> GetList() const;
	void Dell();
	Polinom& operator=(const Polinom& Polinom2); //оператор = 
	Polinom operator+(const Polinom& Polinom2); //оператор +
	Polinom operator-(const Polinom& Polinom2); //оператор -
	Polinom operator * (const Polinom& Polinom2); //опрератор *
	friend ostream& operator<<(ostream& os, const Polinom& P);

private:
	ListRing<monom> List;

};

