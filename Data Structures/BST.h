#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include "queue.h"

template <typename T>
class BST {
private:
	struct Node {
		Node* leftptr;
		Node* rightptr;
		
		T data;

		Node() : data(0), leftptr(nullptr), rightptr(nullptr) {}
		Node(T val) : data(val), leftptr(nullptr), rightptr(nullptr) {}
	};

	Queue<Node*> nodeInOrder;

	Node* root;
	Node* insertion(T val, Node* cursor);
	void postOrder(Node* cursor);
	void inOrder(Node* cursor);
	void preOrder(Node* cursor);
	void levelOrder(Node* cursor);
	void BFS(Node* cursor);
	Node* getParent(Node* cursor);

public:


	BST(); 
	BST(T val);

	void insert(T val);
	void remove(T val);
	bool isEmpty(Node* cursor) const;
	void printAll();




	Node* getRoot() const;
	Node* find(T val, Node* cursor);
	void findIt(T val);
	Node* minValue(Node* cursor) const;

};

#include "BST.tpp"
#endif 