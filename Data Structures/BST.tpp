template <typename T>
BST<T>::BST() {
	root = nullptr;
}

template <typename T>
BST<T>::BST(T val) {
	insert(val);
}

template <typename T>
void BST<T>::insert(T val) {
	root = insertion(val, root);
}

template <typename T>
typename BST<T>::Node* BST<T>::insertion(T val, Node* cursor) {
	if (cursor == nullptr) {
		cursor = new Node(val);
		nodeInOrder.Enqueue(cursor);
		return cursor;
	}

	if (val < cursor->data) {
		cursor->leftptr = insertion(val, cursor->leftptr);
	}
	else {
		cursor->rightptr = insertion(val, cursor->rightptr);
	}

	return cursor;
}


template <typename T>
void BST<T>::printAll() {
	inOrder(root);
}


template<typename T>
void BST<T>::postOrder(Node* cursor) {
	if (cursor == NULL)
		return;
	postOrder(cursor->leftptr);
	postOrder(cursor->rightptr);
	std::cout << cursor->data << " ";
	
}

template<typename T>
void BST<T>::inOrder(Node* cursor) {
	if (cursor == NULL)
		return;
	inOrder(cursor->leftptr);
	std::cout << cursor->data << " ";
	inOrder(cursor->rightptr);
	
}

template<typename T>
void BST<T>::preOrder(Node* cursor) {
	if (cursor == NULL)
		return;

	std::cout << cursor->data << " ";
	preOrder(cursor->leftptr);
	preOrder(cursor->rightptr);
	

}

template<typename T>
void BST<T>::levelOrder(Node* cursor) {
	std::cout << cursor->data << " ";
	preOrder(cursor->leftptr);
	preOrder(cursor->rightptr);

	if (cursor == NULL)
		return;
}

template <typename T>
bool BST<T>::isEmpty(Node* cursor) const{
	if (cursor != nullptr) {
		return false;
	}
	return true;
}

template <typename T>
void BST<T>::findIt(T val) {
	find(val, root);
}

template <typename T>
typename BST<T>::Node* BST<T>::find(T val, Node* cursor) {
	bool found = true;
	if (isEmpty(cursor)) {
		std::cout << "the tree is empty" << "\n";
		return nullptr;
	}

	
	while (cursor != nullptr) {
		if (cursor->data = val) {
			found = false;
			std::cout << "Data: " << val << " has been found" << "\n";
			return cursor;
		}
		else if (val < cursor->data) {
			cursor = cursor->leftptr;
		}
		else {
			cursor = cursor->rightptr;
		}
	}

	if (!found) {
		std::cout << "Data: " << val << "could not be found" << '\n';
	}

	return nullptr;
	
	
   
    /* if (isEmpty(cursor)) {
		std::cout << "the tree is empty" << "\n";
		return nullptr;
	}

	if (cursor->data == val) {
		std::cout << "Data: " << val << " has been found" << '\n';
		return cursor;
	}
	else if (val < cursor->data) {
		return find(val, cursor->leftptr);
	}
	else {
		return find(val, cursor->rightptr);
	}

	std::cout << "Data: " << val << "could not be found" << '\n';
	return nullptr;
	*/
	
}

template <typename T>
void BST<T>::remove(T val) {
	Node* deleteNode = find(val);
	if (deleteNode->leftptr == nullptr && deleteNode->rightptr == nullptr) {
		delete deleteNode;
		return;
	}
	else if (deleteNode->leftptr != nullptr && deleteNode->rightptr == nullptr) {

	}
}

template <typename T>
typename BST<T>::Node* BST<T>::minValue(Node* cursor) const{
	if (cursor == nullptr) {
		return nullptr;
	}
	else if(cursor->leftptr == nullptr){
		std::cout << cursor->data << "\n";
		return cursor;
	}

	return minValue(cursor->leftptr);
}

template <typename T>
typename BST<T>:: Node* BST<T>::getRoot() const {
	return root;
}

template <typename T>
typename BST<T>::Node* BST<T>::getParent(Node* cursor) {
	Node* parent = cursor;

	while (parent != nullptr) {

	}
}