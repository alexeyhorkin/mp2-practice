#pragma once

template <typename T> 
class Node 
{
private:
	Node* Next;
	T Data;
public:
	Node(T Data= 0, Node* NextPtr= NULL);
	Node(const Node<T> &NodaCopy);
	~Node();
};

template <typename T>
Node<T> :: Node( T data, Node* NextPtr ) 
{
	Data = data;
	Next = NextPtr;
}

template <typename T>
Node<T> :: Node(const Node<T> &NodaCopy)
{
	Data = NodaCopy<T>.Data;
	Next = NodaCopy<T>.Next;
}

template <typename T>
Node<T> :: ~Node()
{
	delete Mext;
}