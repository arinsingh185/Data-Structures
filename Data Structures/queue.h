#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>

class Queue {
private:
	struct Node {
		T data{};

		Node* next;
		Node* prev;

		Node() : data(0), next(nullptr), prev(nullptr) {}
		Node(T val) : data(val), next(nullptr), prev(nullptr) {}
	};

	Node* headptr;
	Node* tailptr;

public:
	Queue();
	Queue(T val);
	void Enqueue(T val);
	void Dequeue();
	T peek();
	bool isEmpty();
	void printAll();
};

#include "queue.tpp"
#endif