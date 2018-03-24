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
	~ListRing(); // деструктор
	Node<Type>* GetHead() const;
	Node<Type>* GetCurrent() const;
	bool IsEmpty() const; //проверка на пустоту
	void InsertoTail(Type A=0); //вставка в конец
	void InsertAfter(const Node<Type>* A, Type data); //вставка после А
	ListRing<Type>& operator = (const ListRing<Type> &list2);
	//ListRing<Type>& operator=(const ListRing& list2); //оператор = 
	void clear(); //удаление 
	void Delete(Node<Type>* NodePtr); // удаленеи ноды по указателю
	Node<Type>* GetH();
	Node<Type>* GetAdres(const Type A);
};
template <typename Type>
ListRing<Type>::ListRing() 
{
	Head = NULL;
	Current = NULL;
}

template <typename Type>
bool ListRing<Type>::IsEmpty() const 
{
	if (Head == NULL)
		return true;
	else return false;
}

template <typename Type>
Node<Type>* ListRing<Type>:: GetHead() const
{
	return Head;
}

template <typename Type>
Node<Type>*ListRing<Type>:: GetCurrent() const
{
	return Current;
}



template <typename Type>
void ListRing<Type> :: InsertoTail(Type A) 
{
	if (Head == NULL)
	{
		Head = new Node<Type>(A, NULL);
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

template<typename Type>
 void ListRing<Type>::clear()
{
	if (Head != NULL)
	{
		Node<Type>* ptr = Head;
		Node<Type>* ptr_next;
		while (ptr != Current)
		{
			ptr_next = ptr->Next;
			delete ptr;
			ptr = ptr_next;
		}
		delete ptr;
		Head = NULL;
		Current = NULL;
	}
}

template <typename Type>
ListRing<Type> :: ~ListRing()
{
	if (Head != NULL)
	{
		Node<Type>* ptr = Head;
		Node<Type>* ptr_next;
		while (ptr != Current)
		{
			ptr_next = ptr->Next;
			delete ptr;
			ptr = ptr_next;
		}
		delete ptr;
		Head = NULL;
		Current = NULL;
	}
}

template <typename Type>
ListRing<Type>& ListRing<Type>:: operator = (const ListRing<Type> &list2)
{
	clear();
	if (!list2.IsEmpty())
	{
		Node<Type>* ptr2 = list2.Head->Next;
		Head = new Node<Type>(list2.Head->Data);
		Current = Head;
		while (ptr2 != list2.Current) {
			Current->Next = new Node<Type>(ptr2->Data);
			Current = Current->Next;
			ptr2 = ptr2->Next;
		}
		Current->Next = new Node<Type>(ptr2->Data, Head);
		Current = Current->Next;
	}
	return (*this);
}


template <typename Type>
void ListRing<Type> :: Delete(Node<Type>* NodePtr) 
{
	Node<Type>* BeliverPointer = Head;
	while ((BeliverPointer != Current)&&(BeliverPointer!=NodePtr))
			BeliverPointer = BeliverPointer->Next;
	if(BeliverPointer==NodePtr)
	{
		Node<Type>* ptr = Head;
		if (NodePtr == Head)
		{
			if (ptr->Next == Head)
			{
				delete ptr;
				Head = NULL;
				Current = NULL;
			}
			else
			{
				ptr->Next;
				delete Head;
				Head = ptr;
			}
		}
		else {
			while (ptr->Next != NodePtr)
				ptr = ptr->Next;
			if (Current == ptr->Next)
			{
				delete ptr->Next;
				ptr->Next = Head;
				Current = ptr;
			}
			else
			{
				Node<Type>* Ptr2 = ptr->Next->Next;
				delete ptr->Next;
				ptr->Next = Ptr2;
			}
		}
	}
	else  throw "I had not found";
	}
	
template <typename Type>
Node<Type>* ListRing<Type> :: GetH() 
{
	return Head;
}

template <typename Type>
Node<Type>* ListRing<Type>::GetAdres(const Type A) 
{
	Node<Type>* ptr = Head;
	while ((ptr->Data != A) && (ptr != Current)) ptr = ptr->next;
	if (ptr == Current) if (ptr->Date == A) return ptr; else throw"netu";
	else return ptr;
}


 






