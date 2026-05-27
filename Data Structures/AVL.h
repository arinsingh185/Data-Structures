#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
class AVL {
private:
	struct Node {
		T data;
		int height;
		Node* left;
		Node* right;
		Node() : left(nullptr), right(nullptr), data(0), height(0) {}
		Node(T val) : left(nullptr), right(nullptr), data(val), height(0) {}
		
	};

	int getHeight(Node* cursor);

	Node* root;
	Node* rightRotation(Node* cursor);
	Node* leftRotation(Node* cursor);

	Node* insertUtility(Node* cursor, T val);

	void inOrder(Node* cursor);
public:
	AVL();
	AVL(T val);
	T search(Node* cursor);
	void insert(T val);
	void remove(T val);
	void printAll();
	
};

#include "AVL.tpp"
#endif
