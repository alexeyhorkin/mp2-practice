#pragma once
#include <string>
using namespace std;
// моном (data for Node)

struct monom
{
private:
	int abc;
	double coeff;
public:
	monom(int abc_a = 0, double coef_f = 0)
	{
		abc = abc_a;
		coeff = coef_f;
	}
	double GetCoeff();
	void AddCoeff(double A);
	int Getabc();
	void Set_X(char X);
	void Set_Y(char X);
	void Set_Z(char X);
	void ChangeCoeff();
	bool  operator ==(const monom &A) const;
	monom& operator = (const monom&A);
	bool  operator !=(const monom &A);
	monom& operator = (const string &A);
	bool  operator <(const monom &A);
	bool  operator >(const monom &A);
	bool IsEmptyCoeff(monom &A);
	void AddCoef(const monom&A);
};




