#pragma once

template <typename Element>
class AVLTree {
	struct Node {
		Node* left, * right, * parent;
		Element data;
		signed char balance;
		Node(const Element& X) : right(nullptr), left(nullptr), parent(nullptr), data(X), balance(0) {}
		~Node() {
			if (left) delete left;
			if (right) delete right;
			left = right = parent = nullptr;
		}
		Node* minimum() {
			Node* now = this;
			while (now->left) now = now->left;
			return now;
		}
		Node* maximum() {
			Node* now = this;
			while (now->right) now = now->right;
			return now;
		}
		Node* next() {
			if (right) return right->minimum();
			Node* p = parent, * now = this;
			while (p) {
				if (now == p->left) break;
				now = p;
				p = p->parent;
			}
			return p;
		}
		Node* prev() {
			if (left) return left->maximum();
			Node* p = parent, * now = this;
			while (p) {
				if (now == p->right) break;
				now = p;
				p = p->parent;
			}
			return p;
		}
		int level()const {
			int L = (left) ? left->level() : 0;
			int R = (right) ? right->level() : 0;
			return L > R ? L + 1 : R + 1;
		}
	};
	Node* root;
	unsigned int count;
	Node* _RightRotate(Node*);
	Node* _LeftRotate(Node*);
	Node* _DoubleRightRotate(Node*);
	Node* _DoubleLeftRotate(Node*);
public:
	AVLTree() : root(nullptr), count(0) {}
	~AVLTree() {
		if (root)
			delete root;
		root = nullptr;
	}
	unsigned int size()const { return count; }
	int height()const { return (root) ? root->level() : 0; }
	void clear() {
		if (root) delete root;
		root = nullptr;
	}
	void insert(const Element& X) {
		++count;
		if (root == nullptr) {
			root = new Node(X);
			return;
		}
		Node* now, * p;
		bool toLeft;
		now = root;
		do {
			p = now;
			if (X < now->data) {
				now = now->left; toLeft = true;
			}
			else {
				now = now->right; toLeft = false;
			}
		} while (now);
		now = new Node(X);
		if (toLeft) p->left = now; else p->right = now;
		now->parent = p;

		// âîññòàíîâëåíèå áàëàíñà
		do {
			if (now->parent->left == now) now->parent->balance -= 1;
			else now->parent->balance += 1;
			now = now->parent;
			switch (now->balance) {
			case 2:
				if (now->right->balance == -1) now = _DoubleLeftRotate(now);
				else now = _LeftRotate(now);
				break;
			case -2:
				if (now->left->balance == 1) now = _DoubleRightRotate(now);
				else now = _RightRotate(now);
				break;
			}
		} while (now != root && now->balance != 0);

	}

	class iterator {
		
	public:
		Node* now;
		iterator(Node* p = nullptr) : now(p) {}
		Element& operator*(){ return now->data; }
		bool operator==(const iterator& p)const { return now == p.now; }
		bool operator!=(const iterator& p)const { return now != p.now; }
		iterator& operator++() { if (now) now = now->next(); return *this; }
		iterator operator++(int) {
			Node* tmp = now;
			if (now) now = now->next();
			return iterator(tmp);
		}
		friend class AVLTree;
	};
	iterator begin()const {
		if (root) return iterator(root->minimum());
		return end();
	}
	iterator end()const {
		return iterator(nullptr);
	}
	class reverse_iterator {
		Node* now;
	public:
		reverse_iterator(Node* p = nullptr) : now(p) {}
		const Element& operator*()const { return now->data; }
		bool operator==(const reverse_iterator& p)const { return now == p.now; }
		bool operator!=(const reverse_iterator& p)const { return now != p.now; }
		reverse_iterator& operator++() { if (now) now = now->prev(); return *this; }
		reverse_iterator operator++(int) {
			Node* tmp = now;
			if (now) now = now->prev();
			return reverse_iterator(tmp);
		}
	};
	reverse_iterator rbegin()const {
		if (root) return reverse_iterator(root->maximum());
		return rend();
	}
	reverse_iterator rend()const { return reverse_iterator(nullptr); }
	iterator find(const Element& X)const {
		Node* now = root;
		while (now) {
			if (X == now->data) break;
			if (X < now->data) now = now->left;
			else now = now->right;
		}
		return iterator(now);
	}
	void erase(iterator); // Óäàëåíèå óçëà â äåðåâå
};

template <typename Element>
void AVLTree<Element>::erase(typename AVLTree<Element>::iterator pos) {
	Node* toDelete = pos.now;
	if (toDelete == nullptr) return;
	Node* Alt;
	if (toDelete->right == nullptr)
		Alt = toDelete->left;
	else if (toDelete->left == nullptr)
		Alt = toDelete->right;
	else {
		Alt = toDelete->right->minimum();
		if (Alt->parent != toDelete) {
			Alt->parent->left = Alt->right;
			if (Alt->right) Alt->right->parent = Alt->parent;
			Alt->right = toDelete->right;
			toDelete->right->parent = Alt;
		}
		Alt->left = toDelete->left;
		toDelete->left->parent = Alt;
	}

	Node* notBalanced;
	if (Alt == nullptr) {
		notBalanced = toDelete->parent;
		if (notBalanced) {
			if (notBalanced->left == toDelete) notBalanced->balance += 1;
			else notBalanced->balance -= 1;
		}
	}
	else {
		Alt->balance = toDelete->balance;
		if (Alt->parent == toDelete) {
			notBalanced = Alt;
			if (Alt == toDelete->left) notBalanced->balance += 1;
			else notBalanced->balance -= 1;
		}
		else {
			notBalanced = Alt->parent;
			notBalanced->balance += 1;
		}
	}


	if (toDelete->parent == nullptr) {
		root = Alt;
	}
	else {
		if (toDelete->parent->left == toDelete)
			toDelete->parent->left = Alt;
		else
			toDelete->parent->right = Alt;
	}
	if (Alt != nullptr) {
		Alt->parent = toDelete->parent;
	}

	toDelete->right = nullptr; toDelete->left = nullptr;
	delete toDelete;
	--count;

	// âîññòàíîâëåíèå áàëàíñèðîâêè
	while (notBalanced) {
		switch (notBalanced->balance) {
		case 2:
			if (notBalanced->right->balance == -1)
				notBalanced = _DoubleLeftRotate(notBalanced);
			else
				notBalanced = _LeftRotate(notBalanced);
			break;
		case -2:
			if (notBalanced->left->balance == 1)
				notBalanced = _DoubleRightRotate(notBalanced);
			else
				notBalanced = _RightRotate(notBalanced);
			break;
		}
		if (notBalanced->balance == 1 || notBalanced->balance == -1)
			break;
		if (notBalanced->parent) {
			if (notBalanced->parent->left == notBalanced)
				notBalanced->parent->balance += 1;
			else
				notBalanced->parent->balance -= 1;
		}
		notBalanced = notBalanced->parent;
	}
}

template <typename Element>
typename AVLTree<Element>::Node*
AVLTree<Element>::_LeftRotate(typename AVLTree<Element>::Node* a) {
	if (a->balance != 2) return a;
	Node* b = a->right;
	if (b->balance == -1) return a;

	a->right = b->left;
	if (b->left) b->left->parent = a;

	b->parent = a->parent;
	if (a->parent) {
		if (a->parent->left == a)
			a->parent->left = b;
		else
			a->parent->right = b;
	}
	else {
		root = b;
	}

	b->left = a;
	a->parent = b;

	if (b->balance == 1) {
		a->balance = 0; b->balance = 0;
	}
	else {
		a->balance = 1; b->balance = -1;
	}
	return b;
}

template <typename Element>
typename AVLTree<Element>::Node*
AVLTree<Element>::_RightRotate(typename AVLTree<Element>::Node* b) {
	if (b->balance != -2) return b;
	Node* a = b->left;
	if (a->balance == 1) return b;

	b->left = a->right;
	if (a->right) a->right->parent = b;

	a->parent = b->parent;
	if (b->parent) {
		if (b->parent->left == b)
			b->parent->left = a;
		else
			b->parent->right = a;
	}
	else {
		root = a;
	}

	a->right = b;
	b->parent = a;

	if (a->balance == -1) {
		a->balance = 0; b->balance = 0;
	}
	else {
		a->balance = 1; b->balance = -1;
	}

	return a;
}

template <typename Element>
typename AVLTree<Element>::Node*
AVLTree<Element>::_DoubleLeftRotate(typename AVLTree<Element>::Node* a) {
	if (a->balance != 2) return a;
	Node* c = a->right;
	if (c->balance != -1) return a;
	Node* b = c->left;

	a->right = b->left; if (b->left) b->left->parent = a;
	c->left = b->right; if (b->right) b->right->parent = c;

	b->parent = a->parent;
	if (a->parent) {
		if (a->parent->left == a)
			a->parent->left = b;
		else
			a->parent->right = b;
	}
	else {
		root = b;
	}

	b->left = a;  a->parent = b;
	b->right = c; c->parent = b;

	if (b->balance == 0) {
		a->balance = 0;  c->balance = 0;
	}
	else if (b->balance == 1) {
		a->balance = -1; c->balance = 0;
	}
	else {
		a->balance = 0;  c->balance = 1;
	}
	b->balance = 0;
	return b;
}

template <typename Element>
typename AVLTree<Element>::Node*
AVLTree<Element>::_DoubleRightRotate(typename AVLTree<Element>::Node* c) {
	if (c->balance != -2) return c;
	Node* a = c->left;
	if (a->balance != 1) return c;
	Node* b = a->right;

	a->right = b->left; if (b->left) b->left->parent = a;
	c->left = b->right; if (b->right) b->right->parent = c;

	b->parent = c->parent;
	if (c->parent) {
		if (c->parent->left == c)
			c->parent->left = b;
		else
			c->parent->right = b;
	}
	else {
		root = b;
	}

	b->left = a;  a->parent = b;
	b->right = c; c->parent = b;

	if (b->balance == 0) {
		a->balance = 0;  c->balance = 0;
	}
	else if (b->balance == 1) {
		a->balance = -1; c->balance = 0;
	}
	else {
		a->balance = 0;  c->balance = 1;
	}
	b->balance = 0;

	return b;
}
