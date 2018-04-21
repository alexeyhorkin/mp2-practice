#pragma once
#include <string>
using namespace std;
// ����� (data for Node)

struct monom
{
public:
	int abc;
	double coeff;
	monom(int abc_a = 0, double coef_f = 0);
	monom(const string &A);
	bool  operator ==(const monom &A) const;
	monom& operator = (const monom&A);
	bool  operator !=(const monom &A) const;
	bool  operator <(const monom &A) const;
	bool  operator >(const monom &A) const;
private:
	//������� ��� ������ � char
	bool determinatechar(char s); //private
	bool determinatecharonly(char s); //private
};




