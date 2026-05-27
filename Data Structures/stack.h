
#ifndef STACK_H
#define STACK_H

#include <iostream>


template<typename T>

class Stack {
private:
	struct Node {
		T data{};

		Node* next;

		Node() : data(0), next(nullptr) {}
		Node(T val) : data(val), next(nullptr) {}
	};

	Node* headptr;

public:
	Stack();
	Stack(T val);
	void push(T val);
	void pop();
	T peek();
	bool isEmpty();
	void printAll();
};

#include "stack.tpp"
#endif