#pragma once

template<typename T>
Linklist<T>::Linklist() {
	head = nullptr;
}
template<typename T>
Linklist<T>::~Linklist() {
	clear(head);
}

template<typename T>
void Linklist<T>::append(T item) {
	Node* newNode = new Node(item);
	if (head == nullptr) {
		head = newNode;
		size++;
		return;
	}
	Node* currNode = head;

	while (currNode->next != nullptr) {
		currNode = currNode->next;
	}

	currNode->next = newNode;
	size++;
}

template<typename T>
 void Linklist<T>::printAll() const{
	 Node* currNode = head;

	 while (currNode != nullptr) {
		 std::cout << currNode->data << "\n";
		 currNode = currNode->next;
	 }
}

 template<typename T>
 void Linklist<T>::pop(T item) {
	 Node* currNode = head;
	 Node* prev = nullptr;

	 if (head->data == item) {
		 Node* nodeToDelete = head;
		 head = head->next;
		 delete nodeToDelete;
		 return;
	 }
	 
	 while (currNode != nullptr) {
		 if (currNode->data == item) {
			 prev->next = currNode->next;
			 delete currNode;
			 return;
		 }
		 prev = currNode;
		 currNode = currNode->next;
	 }
 }

 template <typename T>
 T Linklist<T>::getHead() const{
	 return head->data;
 }

 template <typename T>
 int Linklist<T>::getSize() const {
	 return size;
 }
 
 template <typename T>

 bool Linklist<T>::isEmpty() const{
	 if (head == nullptr) {
		 return true;
	 }
	 return false;
 }

 template <typename T> 
 void Linklist<T>::clear(Node* head) {
	 Node* currNode = head;
	 if (currNode->next != nullptr) {
		 clear(currNode->next);
	 }

	 delete currNode;
 }