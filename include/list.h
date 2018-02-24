#pragma once
#include "node.h"

template <typename Type>
class ListRing 
{
private:
	Node<Type>* Head;
	Node<Type>* Current;

public:
	ListRing(); // конструктор 
	ListRing(const ListRing<Type> &ListForCopy); // конструктор копирования
	bool IsEmpty();
	void InsertoTail(Type A); //вставка в конец
	void InsertAfter(const Node<Type>* A, Type data); //вставка после А


};
template <typename Type>
ListRing<Type>::ListRing() 
{
	Head = NULL;
	Current = NULL;
}

template <typename Type>
bool ListRing<Type>::IsEmpty()
{
	if (Head = NULL)
		return true;
	else return false;
}

template <typename Type>
void ListRing<Type> :: InsertoTail(Type A) 
{
	if (this->IsEmpty())
	{
		Head = new Node<Type>(A, NULL)
			Head->Next = Head;
			Current = Head;
	}
	else 
	{
		Current->Next = new Node <Type>(A, Head);
		Current = Current->Next;
	}



}

template <typename Type>
void ListRing<Type> :: InsertAfter(const Node<Type>* A, Type data)
{
	if (Head == NULL)
		throw "ListRing is empty";
	else 
	{
		Node<Type>* ptr = Head;
		while ((ptr != A)&&(ptr->Next!=Head))
			ptr = ptr->Next;
		if (ptr == A)
		{
			Node<Type>* Ptr2 = ptr->Next;
			ptr->Next = new Node<Type>(data, Ptr2);
		}
		else
			throw "net";
	
	}




}

template <typename Type>
ListRing<Type> ::ListRing(const ListRing<Type> &ListForCopy)
{
	if (ListForCopy.IsEmpty())
		Head = NULL;
	else 
	{
		Head = new Node<Type>(ListForCopy.Head->Data);
		Current = Head;
		Node<Type>* ptr2 = ListForCopy.Head->Next;
		while (ptr2 != ListForCopy.Current)
		{
			Current->Next = new Node<Type>(ptr2->Data);
			Current = Current->Next;
			ptr2 = ptr2->Next;
		}
		Current->Next = new Node<Type>(ptr2->Data, Head);
		Current =Current-> Next;
	}


}