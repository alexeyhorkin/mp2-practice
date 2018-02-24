#pragma once
#include <string>
#include "list.h"
#include "monom.h"
using namespace std;
class Polinom
{
public:
	Polinom(const string A);
	~Polinom();
private:
	ListRing<monom> List;

};

