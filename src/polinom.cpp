#include "polinom.h"
#include <iostream>
using namespace std;
Polinom::Polinom(const string &S)
{
	int i = 0;
	List.InsertoTail(); // вставляем нулевую Node
	string MonomStr = "";
	while (i+1 <= S.length())
	{
		if ((S[i + 1] != '+') && (S[i + 1] != '-') && (S[i + 1] != '\0'))
		{
			MonomStr.push_back(S[i]);
			i += 1;
		}
		else
		{
			MonomStr.push_back(S[i]);
			Node<monom> A(MonomStr);
			Insert(A);
			MonomStr = "";
			i++;
		}
	}
}

void Polinom:: Insert(const Node<monom> N)
{
	int i = 0;
	int flag = 0;
	Node<monom>*PtrNode = List.GetHead();
	while ((PtrNode != List.GetCurrent()) && (flag == 0))
	{
		if (*PtrNode == N)
		{
			monom res(PtrNode->GetData().Getabc(), PtrNode->GetData().GetCoeff() + N.GetData().GetCoeff());
			PtrNode->SetData(res);
			if(PtrNode->GetData().GetCoeff()==0)
				List.Delete(PtrNode);
			flag = 1;
		}
		else if ((*PtrNode < N) && (*(PtrNode->GetNext())>N))
		{
			List.InsertAfter(PtrNode, N.GetData());
			flag = 1;
		}
		PtrNode = PtrNode->GetNext();
	}
	if ((PtrNode == List.GetCurrent()) && (flag == 0))
	{
		if (*PtrNode == N)
			PtrNode->AddCoeff(N);
		else List.InsertoTail(N.GetData());
	}
}

Polinom::~Polinom()
{
	List.clear();
}

Node<monom>* Polinom::GetH() const
{
	return List.GetHead();
}

Polinom& Polinom :: operator=(const Polinom& Polinom2)
{
	List = Polinom2.List;
	return *this;
}

Polinom Polinom :: operator + (const Polinom& Polinom2)
{
	Polinom Res;
	Node<monom>* I = List.GetHead(); // ходилка по this
	Node<monom>* J = Polinom2.List.GetHead(); // ходилка по Polinom2
	while ((I->GetNext() != List.GetHead()) && (J->GetNext() != Polinom2.List.GetHead()))
	{
		if (*I == *J)
		{
			monom res(I->GetData().Getabc(), I->GetData().GetCoeff() + J->GetData().GetCoeff());
			Res.List.InsertoTail(res);
			if (res.GetCoeff() == 0)
			{
				Node<monom>* ptr = Res.List.GetCurrent();
				Res.List.Delete(ptr);
			}
			I = I->GetNext();
			J = J->GetNext();
		}
		else if (*I < *J)
		{

			monom res(I->GetData());
			Res.List.InsertoTail(res);
			I = I->GetNext();
		}
		else if (*I > *J)
		{
			monom res(J->GetData());
			Res.List.InsertoTail(res);
			J = J->GetNext();
		}

	} 
	// последняя итерация цикла
	if (*I == *J)
	{
	monom res(I->GetData().Getabc(), I->GetData().GetCoeff() + J->GetData().GetCoeff());
	Res.List.InsertoTail(res);
	if (res.GetCoeff() == 0)
		{
		Node<monom>* ptr = Res.List.GetCurrent();
		Res.List.Delete(ptr);
		}
	I = I->GetNext();
	J = J->GetNext();
	}
	else if (*I < *J)
		{

		monom res(I->GetData());
		Res.List.InsertoTail(res);
	I = I->GetNext();
		}
	else if (*I > *J)
		{
		monom res(J->GetData());
		Res.List.InsertoTail(res);
	J = J->GetNext();
		}
	// конец последней итерации цикла

		if ((I == List.GetHead()) && (J->GetNext() != Polinom2.List.GetHead())) // I в начале J не в конце
		{
			while(J->GetNext() != Polinom2.List.GetHead())
				{
					monom res(J->GetData());
					Res.List.InsertoTail(res);
					J = J->GetNext();
				}

		}
		else if ((I->GetNext() != List.GetHead()) && (J == Polinom2.List.GetHead())) // I не в конце J в начале
		{
			while (I->GetNext() != List.GetHead())
			{
				monom res(I->GetData());
				Res.List.InsertoTail(res);
				I = I->GetNext();
			}
		}

		else if ((I == List.GetHead()) && (J->GetNext() == Polinom2.List.GetHead())) // I в начале J  в конце
		{
				monom res(J->GetData());
				Res.List.InsertoTail(res);
				J = J->GetNext();
		}
		else if ((I->GetNext() == List.GetHead()) && (J == Polinom2.List.GetHead())) // I в конце J в начале
		{
				monom res(I->GetData());
				Res.List.InsertoTail(res);
				I = I->GetNext();
		}

	return Res;
}

Polinom Polinom :: operator - (const Polinom& Polinom2)
{

	Polinom Res;
	Node<monom>* I = List.GetHead(); // ходилка по this
	Node<monom>* J = Polinom2.List.GetHead(); // ходилка по Polinom2
	while ((I->GetNext() != List.GetHead()) && (J->GetNext() != Polinom2.List.GetHead()))
	{
		if (*I == *J)
		{
			monom res(I->GetData().Getabc(), I->GetData().GetCoeff() - J->GetData().GetCoeff());
			Res.List.InsertoTail(res);
			if (res.GetCoeff() == 0)
			{
				Node<monom>* ptr = Res.List.GetCurrent();
				Res.List.Delete(ptr);
			}
			I = I->GetNext();
			J = J->GetNext();
		}
		else if (*I < *J)
		{

			monom res(I->GetData());
			Res.List.InsertoTail(res);
			I = I->GetNext();
		}
		else if (*I > *J)
		{
			monom res(J->GetData());
			res.ChangeCoeff();
			Res.List.InsertoTail(res);
			J = J->GetNext();
		}

	}
	// последняя итерация цикла
	if (*I == *J)
	{
		monom res(I->GetData().Getabc(), I->GetData().GetCoeff() - J->GetData().GetCoeff());
		Res.List.InsertoTail(res);
		if (res.GetCoeff() == 0)
		{
			Node<monom>* ptr = Res.List.GetCurrent();
			Res.List.Delete(ptr);
		}
		I = I->GetNext();
		J = J->GetNext();
	}
	else if (*I < *J)
	{

		monom res(I->GetData());
		Res.List.InsertoTail(res);
		I = I->GetNext();
	}
	else if (*I > *J)
	{
		monom res(J->GetData());
		res.ChangeCoeff();
		Res.List.InsertoTail(res);
		J = J->GetNext();
	}
	// конец последней итерации цикла

	if ((I == List.GetHead()) && (J->GetNext() != Polinom2.List.GetHead()))
	{
		while (J->GetNext() != Polinom2.List.GetHead())
		{
			monom res(J->GetData());
			res.ChangeCoeff();
			Res.List.InsertoTail(res);
			J = J->GetNext();
		}

	}
	else if ((I->GetNext() != List.GetHead()) && (J == Polinom2.List.GetHead()))
	{
		while (I->GetNext() != List.GetHead())
		{
			monom res(I->GetData());
			Res.List.InsertoTail(res);
			I = I->GetNext();
		}
	}
	else if ((I == List.GetHead()) && (J->GetNext() == Polinom2.List.GetHead())) // I в начале J  в конце
	{
		
			monom res(J->GetData());
			res.ChangeCoeff();
			Res.List.InsertoTail(res);
			J = J->GetNext();

	}

	else if ((I->GetNext() == List.GetHead()) && (J == Polinom2.List.GetHead())) // I в конце J в начале
	{
			monom res(I->GetData());
			res.ChangeCoeff();
			Res.List.InsertoTail(res);
			I = I->GetNext();
	}
	return Res;
}

Polinom Polinom :: operator * (const Polinom& Polinom2)
{
	Polinom Res;
	Node<monom>* I = List.GetHead(); // ходилка по this
	Node<monom>* J = Polinom2.List.GetHead(); // ходилка по Polinom2

	while (I->GetNext() != List.GetHead())
	{
		while (J->GetNext() != Polinom2.List.GetHead())
		{
			monom res(I->GetData().Getabc() + J->GetData().Getabc(), I->GetData().GetCoeff() * J->GetData().GetCoeff());
			if (res.Getabc() > 999)
				throw "Error";
			Node<monom> A(res);
			Res.Insert(A);
			J = J->GetNext();
		}
		I = I->GetNext();
		J = Polinom2.List.GetHead();
	}
	//последняя итерация цикла
	 I=List.GetCurrent();
	 J = Polinom2.List.GetHead();
	 while (J->GetNext() != Polinom2.List.GetHead())
	 {
		 monom res(I->GetData().Getabc() + J->GetData().Getabc(), I->GetData().GetCoeff() * J->GetData().GetCoeff());
		 if (res.Getabc() > 999)
			 throw "Error";
		 Node<monom> A(res);
		 Res.Insert(A);
		 J = J->GetNext();
	 } 
	 //
	 monom res(I->GetData().Getabc() + J->GetData().Getabc(), I->GetData().GetCoeff() * J->GetData().GetCoeff());
	 if (res.Getabc() > 999)
		 throw "Error";
	 Node<monom> A(res);
	 Res.Insert(A);
	 I = List.GetHead();
//
	while (I->GetNext() != List.GetHead())
	{
		monom res(I->GetData().Getabc() + J->GetData().Getabc(), I->GetData().GetCoeff() * J->GetData().GetCoeff());
		if (res.Getabc() > 999)
			throw "Error";
		Node<monom> A(res);
		Res.Insert(A);
		I = I->GetNext();
	}

	return Res;
}


ListRing<monom> Polinom:: GetList() const
{
	return List;

}
ostream& operator<<(ostream& os, const Polinom& P)
{
	Node<monom>* I = P.List.GetHead(); //Ходилка по листу
	while (I->GetNext() != P.List.GetHead())
	{  if(I->GetData().GetCoeff()==0)
		I = I->GetNext();
	else {
		if (I->GetData().GetCoeff() > 0)
			os << '+';

			os << I->GetData().GetCoeff();
			ostringstream oss;               //  преобразование int в string
			oss << I->GetData().Getabc();
		    string ABC = oss.str();          //   конец преобразования

			if (ABC.length() == 1)           // если abc =1
			{
				if(ABC=="0")
					I = I->GetNext();
				else {
					os << "z^" << ABC[0];
					I = I->GetNext();
				}
			}
			else if (ABC.length() == 2)		 // если abc =2
			{
				os << "y^"<< ABC[0]<<"z^"<<ABC[1];
				I = I->GetNext();
			}
			else if (ABC.length() == 3)		 // если abc =3
			{
				os<<"x^"<<ABC[0] << "y^" << ABC[1] << "z^" << ABC[2];
				I = I->GetNext();
			}

	     }
	}
	// последняя итерация цикла
	if (I->GetData().GetCoeff() == 0)
		I = I->GetNext();
	else {
		if (I->GetData().GetCoeff() > 0)
			os << '+';

		os << I->GetData().GetCoeff();
		ostringstream oss;               //  преобразование int в string
		oss << I->GetData().Getabc();
		string ABC = oss.str();          //   конец преобразования

		if (ABC.length() == 1)           // если abc =1
		{
			os << "z^" << ABC[0];
			I = I->GetNext();
		}
		else if (ABC.length() == 2)		 // если abc =2
		{
			os << "y^" << ABC[0] << "z^" << ABC[1];
			I = I->GetNext();
		}
		else if (ABC.length() == 3)		 // если abc =3
		{
			os << "x^" << ABC[0] << "y^" << ABC[1] << "z^" << ABC[2];
			I = I->GetNext();
		}

	}
	os << endl;
	return os;
}
