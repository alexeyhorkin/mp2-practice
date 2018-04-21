#pragma once
#define NULL 0
#include "node.h"
/*������ � �������*/
template <typename T>
class list {
private:
	Node<T>* current; // ��� ������ �������� �������
	Node<T>* Head; // ��� ���������� � ��������� ����� ... ���� �� ��� ������
public:
	list();
	list(const list<T> &list2);    
	~list();   
	list<T>& operator = (const list<T> &list2); 
	bool IsEmpty() const; 
	void Insert_to_tail(const T con = 0); 
	void clear();
	bool operator == (const list<T> &list2) const; 
	bool operator != (const list<T> &list2) const;
	void reset();//reset - ������� � ������
	void Dellcurrent();
	void getnext();//Getnext - ������� � ����� �� ��������� �� ���
	T getcurrentdate();//GetCurrent - ���������� ������ data
	T getcurrentnextdata(); // ���������� ������ ��������� �� �������
	void InsertAfterCurrent(const T con = 0); // ������� ����� ��������
	void ChangeCurrent(const T con = 0); // ������� � �������



	bool IsEnd();//����� �� �� �����
};
template <typename T>
bool list<T>::IsEnd() {
	if (current->Next == Head->Next) return true; else return false;
}
template <typename T>
void list<T>::getnext() {
	current = current->Next;
}

template <typename T>
T list<T>::getcurrentdate() {
	return current->Data;
}
template <typename T>
void list<T>::reset() {
	if (!IsEmpty()) current = Head->Next;
}
template <typename T>
list<T>::list() {
	Head = new Node<T>;
	Head->Next = Head;
	current = NULL;
}
template <typename T>
bool list<T>::IsEmpty() const {
	if (current == NULL)
		return true;
	else
		return false;
}


template <typename T>
void list<T>::Insert_to_tail(const T con) {
	if (!IsEmpty()) {
		while (current->Next != Head->Next) current = current->Next;
		current->Next = new Node<T>(con, Head->Next);
	}
	else {
		Head->Next = new Node<T>(con);
		Head->Next->Next = Head->Next;
		current = Head->Next;
	}
}

template <typename T>
list<T>::list(const list<T> &list2) {
	Head = new Node<T>;
	Head->Next = Head;
	current = NULL;
	if (!list2.IsEmpty()) {
		//����� ����� � list2
		Node<T>* ptr2 = list2.Head;//��������� �� ��������� list2 ����
		ptr2 = ptr2->Next;//  ���� � ������� � ���� �� ���� �������
		Head->Next = new Node<T>(ptr2);
		Node<T>* ptrend = ptr2;
		current = Head->Next; // current �� ���� � ������� � ���������
		while (ptrend->Next != ptr2) ptrend = ptrend->Next;
		ptr2 = ptr2->Next;
		while (ptr2 != list2.Head->Next) {
			current->Next = new Node<T>(ptr2);
			current = current->Next;
			ptr2 = ptr2->Next;
		}
		//���������
		current->Next = Head->Next;
	}
}
template <typename T>
list<T>::~list() {
	this->clear();
}
template <typename T>
void list<T>::clear() {
	if (!IsEmpty()) {
		reset();
		Node<T>* end;
		while (!IsEnd()) getnext();
		end = current;
		reset();
		while (!IsEnd()) {
			Node<T>* ptr = current->Next;
			delete current;
			Head->Next = ptr;
			current = ptr;
			end->Next = ptr;
		}
		delete current;
		current = NULL;
		Head->Next = Head;
	}
}
template <typename T>
list<T>& list<T>:: operator = (const list<T> &list2) {   //���������� ���������� ��� ����������
	this->clear();
	if (!list2.IsEmpty()) {
		//����� ����� � list2
		Node<T>* ptr2 = list2.Head;//��������� �� ��������� list2 ����
		ptr2 = ptr2->Next;//  ���� � ������� � ���� �� ���� �������
		Head->Next = new Node<T>(ptr2);
		Node<T>* ptrend = ptr2;
		current = Head->Next; // current �� ���� � ������� � ���������
		while (ptrend->Next != ptr2) ptrend = ptrend->Next;
		ptr2 = ptr2->Next;
		while (ptr2 != list2.Head->Next) {
			current->Next = new Node<T>(ptr2);
			current = current->Next;
			ptr2 = ptr2->Next;
		}
		//���������
		current->Next = Head->Next;
	}
	return (*this);
}


template <typename T>
bool  list<T> ::operator == (const list<T> &list2) const {
	bool res = true;
	if (list2.IsEmpty() && this->IsEmpty()) return true;
	else {
		Node<T>* listc = Head->Next; //����� ������ ������� ����� ���� � ��������
		Node<T>* list2c = list2.Head->Next;  //����� ������ ������� ����� ���� � ��������
		if (listc->Data != list2c->Data) res = false;
		listc = listc->Next;
		list2c = list2c->Next;
		while (listc != Head->Next && list2c != list2.Head->Next) {
			if (listc->Data != list2c->Data) res = false;
			listc = listc->Next;
			list2c = list2c->Next;
		}
		if (listc != Head->Next || list2c != list2.Head->Next) res = false;
	}
	return res;
}
template <typename T>
bool  list<T> ::operator != (const list<T> &list2) const {
	if (*this == list2) return 0; else return 1;
}

template <typename T>
void list<T> :: InsertAfterCurrent(const T con ) // ������� ����� ��������
{
	Node<T> * PtrNext = current->Next;
	current->Next = new Node<T>(con);
	current->Next->Next = PtrNext;
}

template <typename T>
void list<T> :: ChangeCurrent(const T con ) // ������� � �������
{
	current->Data = con;
}

template <typename T>
T  list<T> ::getcurrentnextdata()
{
	return current->Next->Data;
}// ���������� ������ ��������� �� �������

template <typename T>
void list<T> ::Dellcurrent() 
{
	if (!this->IsEmpty())
	{
		Node<T> * Ptr = Head->Next;
		Node<T> * Ptrnext = current->Next;
		if (current == Head->Next)
		{
			delete Head->Next;
			Head->Next = Ptrnext;
			if (Ptrnext == Head->Next)
				current = NULL;
		}
		else {
			while (Ptr->Next != current) Ptr = Ptr->Next;
			Ptr->Next = Ptrnext;
			delete current;
			current = Ptr;
		}
	}
}