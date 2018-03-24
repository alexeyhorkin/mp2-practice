#include "monom.h"
#include <cstdlib>

bool determinatechar(char s) //если char это цифра, то вернём true;
{
	int k = s;
	if ((k>47) && (k<58)) // (k > '0') && (k <= '9') // isdigit(k) 
		return true;
	else if ((s == '+') || (s == '-'))
		return true;
	else return false;
}
bool monom:: operator ==(const monom &A) const
{
	if (this->abc == A.abc)  return 1; else return 0;
}

double monom::GetCoeff()
{
	return coeff;
}

void  monom :: AddCoeff(double A)
{
	coeff += A;
}

int  monom::Getabc()
{
	return abc;
}
bool monom:: operator !=(const monom &A)
{
	if ((this->abc == A.abc) && (this->coeff == A.coeff)) return 0; else return 1;
}

bool monom:: operator <(const monom &A) 
{ 
if(this->abc < A.abc) return 1; else return 0;
}

bool monom:: operator >(const monom &A) 
{ 
if(this->abc > A.abc) return 1; else return 0;
}

void monom::Set_X(char X)
{
	int x = atof(&X);
	abc = abc + 100 * x;

}
void monom::Set_Y(char X)
{
	int x = atof(&X);
	abc = abc + 10 * x;

}
void monom::Set_Z(char X)
{
	int x = atof(&X);
	abc = abc + x;
}

monom& monom :: operator = (const string &A) 
{
	int i = 0;
	abc = 0;
	if (!determinatechar(A[0]))
	{
		string Coeff = "";
		Coeff.push_back('1');
		coeff = atof(&Coeff[0]);
	}

	while (i<A.length())
	{	
		if (determinatechar(A[i]))
		{
			string Coeff = "";
			if (determinatechar(A[i]) && (!determinatechar(A[i + 1])) && (i+1<A.length()))
			{
				Coeff.push_back(A[i]);
				Coeff.push_back('1');
				coeff = atof(&Coeff[0]);
			}
			while ((determinatechar(A[i]) || A[i] == '.'))
			{
				Coeff.push_back(A[i]);
				i++;
			}
			coeff = atof(&Coeff[0]);

		}
		else if ((A[i] == 'x') && (A[i + 1] == '^'))
		{
			Set_X(A[i + 2]); i += 3;
		}
		else if ((A[i] == 'y') && (A[i + 1] == '^'))
		{
			Set_Y(A[i + 2]); i += 3;
		}
		else if ((A[i] == 'z') && (A[i + 1] == '^'))
		{
			Set_Z(A[i + 2]); i += 3;
		}
		else if ((A[i] == 'x') && (A[i + 1] != '^'))
		{
			Set_X('1');
			i += 1;
		}
		else if ((A[i] == 'y') && (A[i + 1] != '^'))
		{
			Set_Y('1');
			i += 1;
		}
		else if ((A[i] == 'z') && (A[i + 1] != '^'))
		{
			Set_Z('1');
			i += 1;
		}
		else i++;

	}
	return *this;
}

void monom::AddCoef(const monom&A)
{
	coeff = coeff + A.coeff;
}

bool monom ::IsEmptyCoeff(monom &A)
{
	if (0.0 == A.coeff)
		return 1;
	else return 0;
}

void monom :: ChangeCoeff() 
{
	coeff = coeff * (-1);
}

monom& monom :: operator = (const monom&A) 
{
	abc = A.abc;
	coeff = A.coeff;
	return *this;
}