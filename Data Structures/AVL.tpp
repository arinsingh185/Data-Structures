template <typename T>
AVL<T>::AVL() {
	root = nullptr;
}

template <typename T>
AVL<T>::AVL(T val) {
	root = new Node(val);
}

template <typename T> 
int AVL<T>::getHeight(Node* cursor) {
	if (cursor == nullptr) {
		return 0;
	}
	return cursor->height;
}


template <typename T>
typename AVL<T>::Node* AVL<T>::leftRotation(Node* cursor) {
	Node* newRoot = cursor->right;
	newRoot->right = newRoot->right;
	newRoot->left = cursor;
	newRoot->height = 1 + std::max(getHeight(cursor->left), getHeight(cursor->left));
	cursor->height = 1 + std::max(getHeight(cursor->left), getHeight(cursor->left));
	return newRoot;
}

template <typename T>
typename AVL<T>::Node* AVL<T>::rightRotation(Node* cursor) {
	Node* newRoot = cursor->left;
	newRoot->right = cursor;
	newRoot->left = newRoot->left;;
	newRoot->height = 1 + std::max(getHeight(cursor->left), getHeight(cursor->left));
	cursor->height = 1 + std::max(getHeight(cursor->left), getHeight(cursor->left));
	return newRoot;
}

template <typename T>
void AVL<T>::insert(T val) {
	root = insertUtility(root, val);
}

template <typename T>
typename AVL<T>::Node* AVL<T>::insertUtility(Node* cursor, T val) {
	if (cursor == nullptr) {
		cursor = new Node(val);
		return cursor;
	}

	if (val > cursor->data) {
		cursor->right = insertUtility(cursor->right, val);
		cursor->height = 1 + std::max(getHeight(cursor->left), getHeight(cursor->left));
	}
	else {
		cursor->left = insertUtility(cursor->left, val);
		cursor->height = 1 + std::max(getHeight(cursor->left), getHeight(cursor->left));
	}

	int balance = getHeight(cursor->left) - getHeight(cursor->right);

	if (balance > 1) {
		if (val > cursor->left->data) {
			cursor->left = rightRotation(cursor->left);
		}
		else {
			return leftRotation(cursor);
		}
	}
	else if (balance < -1) {
		if (val < cursor->right->data) {
			cursor->right = leftRotation(cursor->right);
		}
		else {
			return rightRotation(cursor);
		}
	}
	return cursor;
}

template <typename T>
void AVL<T>::printAll() {
	inOrder(root);
}

template <typename T>
void AVL<T>::inOrder(Node* cursor) {
	if (cursor == NULL) {
		return;
	}

	inOrder(cursor->left);
	std::cout << cursor->data << " ";
	inOrder(cursor->right);
}