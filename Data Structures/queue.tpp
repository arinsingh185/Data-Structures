template <typename T>
Queue<T>::Queue() {
	headptr = nullptr;
	tailptr = nullptr;
}

template <typename T>
Queue<T>::Queue(T val) {
	headptr = new Node(val);
	tailptr = headptr;
}

template <typename T>
void Queue<T>::Enqueue(T val) {
	Node* newNode = new Node(val);
	if (headptr == nullptr) {
		headptr = newNode;
		tailptr = headptr;
	}
	tailptr->next = newNode;
	tailptr->prev = tailptr;
	tailptr = newNode;
}

template <typename T>
void Queue<T>::Dequeue() {
	Node* tempNode = headptr;
	if (headptr == nullptr) {
		std::cout << isEmpty() << "\n";
		return;
	}
	headptr = headptr->next;
	delete tempNode;
}
template <typename T>
T Queue<T>::peek() {
	return headptr->data;
}
template <typename T>
bool Queue<T>::isEmpty() {
	return headptr == nullptr;
}


template <typename T>
void Queue<T>::printAll() {
	Node* currNode = headptr;
	while (currNode != nullptr) {
		std::cout << currNode->data << "\n";
		currNode = currNode->next;
	}
}

