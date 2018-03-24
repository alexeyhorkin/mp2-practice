#pragma once
#include <string>
#include "monom.h"
#include <sstream>
using namespace std;
template <typename Type>
class ListRing;
template <typename T> 
class Node 
{
private:
	Node* Next;
	T Data;
public:
	Node(T Data= 0, Node* NextPtr= NULL);
	Node(const Node<T> &NodaCopy);
	Node(const string A);
	T GetData() const;
	Node<T>* GetNext();
	void SetData(const T A);
	void AddCoeff(const Node<T> &N);
	bool IsEmptyCoef();
	friend class ListRing<T>;
	bool  operator ==(const Node<T> &A);
	bool  operator !=(const Node<T> &A);
	bool  operator <(const Node<T> &A);
	bool  operator > (const Node<T> &A);

};

template <typename T>
Node<T> :: Node( T data, Node* NextPtr ) 
{
	Data = data;
	Next = NextPtr;
}

template <typename T>
Node<T>* Node<T> :: GetNext()
{
	return Next;
}

template <typename T>
Node<T> :: Node(const Node<T> &NodaCopy)
{
	Data = NodaCopy.Data;
	Next = NodaCopy.Next;
}

template <typename T>
Node<T>::Node(const string A)
{
 Data = A;
 Next = NULL;
}

template <typename T>
T Node<T> :: GetData() const
{
	return Data;
}
template <typename T>
void Node<T> :: SetData(const T A)
{
	Data = A;
}
template <typename T>
bool Node<T>:: operator ==(const Node<T> &A)
{
	if (Data == A.Data)
		return true;
	else return false;
}

template <typename T>
bool Node<T>:: operator !=(const Node<T> &A)
{
	if (Data != A.Data)
		return true;
	else return false;
}
template <typename T>
bool Node<T> :: operator <(const Node<T> &A)
{
	if (Data < A.Data)
		return true;
	else return false;
}

template <typename T>
bool Node<T> :: operator > (const Node<T> &A)
{
	if (Data > A.Data)
		return true;
	else return false;
}

template <typename T>
	void Node<T> :: AddCoeff(const Node<T> &N)
{
	Data.AddCoef(N.Data);
}

	template <typename T>
	bool Node<T> :: IsEmptyCoef()
	{
		if (IsEmptyCoeff(Data))
			return 1;
		else return 0;
	}


