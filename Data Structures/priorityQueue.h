#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>
#include <vector>
template <typename T>
class PriorityQueue {

	std::vector<T> queue;
	void bubbleDown();
	void bubbleUp();
public:
	PriorityQueue();
	PriorityQueue(T val);

	bool isEmpty();
	void insert(T val);
	T deleteMin();
};

#include <priorityQueue.tpp>
#endif