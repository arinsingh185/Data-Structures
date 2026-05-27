

#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>

template <typename T>
class Linklist{
private:

	struct Node {
		T data{};
		Node* next;
		
		Node() : data(0), next(nullptr) {}
		Node(T val) : data(val), next(nullptr) {}

	};
	
public:
	Linklist();
	~Linklist();
	void append(T item);
	void printAll() const;
	void pop(T item);
	T getHead() const;
	int getSize() const;
	bool isEmpty() const;
	

private:
	void clear(Node* head);


	
	Node* head;
	int size;

	
};

#include "Linklist.tpp"
#endif
