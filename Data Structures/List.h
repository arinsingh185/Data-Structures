#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
private:
	struct Node {
		Node* next;
		T data;

		Node() : next(nullptr), data(NULL) {}
		Node(T val) : next(nullptr), data(val) {}
	};
public:
	Node* head;
	Node* tail;

	List();
	List(T val);
	
	void insert(T val);
	void push_back(T val);
	void push_front(T val);
	
};

#include "list.tpp"
#endif