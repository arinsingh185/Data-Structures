template <typename T>
List<T>::List() {
	head = nullptr;
	tail = nullptr;
}

template <typename T>
List<T>::List(T val) {
	push_front(val);
}

template <typename T>
void List<T>::insert(T val) {

}

template<typename T>
void List<T>::push_front(T val) {
	if (head == nullptr) {
		head = new Node(val);
		tail = head;
	}
	
	Node* insertNode = new Node(val);
	head->next = head;
	head = insertNode;
	delete insertNode;
}