template <typename T>
Stack<T>::Stack() {
	headptr = nullptr;
}
template <typename T>
Stack<T>::Stack(T val) {
	headptr = new Node(val);
}

template <typename T>
void Stack<T>::push(T val) {
	if (headptr == nullptr) {
		headptr = new Node(val);
	}

	Node* currNode = headptr;
	Node* newNode = new Node(val);
	headptr = newNode;
	headptr->next = currNode;
}

template <typename T>
void Stack<T>::pop() {
	Node* currNode = headptr;
	headptr = headptr->next;
	delete currNode;
}

template <typename T>
T Stack<T>::peek() {
	return headptr->data;
}

template <typename T>
bool Stack<T>::isEmpty() {
	if (headptr == nullptr) {
		return true;
	}
	return false;
}

template <typename T>
void Stack<T>::printAll() {
	Node* currNode = headptr;
	while(currNode->next != nullptr){
		std::cout << currNode->data << "\n";
		currNode = currNode->next;
	}
}
