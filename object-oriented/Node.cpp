#pragma once
#include "PhoneBookEntry.cpp"
#include "IComparable.cpp"

class Node: public IComparable<Node *> {
	Node *left;
	Node *right;
	Node *parent;

	public:
		PhoneBookEntry *data;

		Node(PhoneBookEntry *data) {
			this->data=data;

			left = nullptr;
			right = nullptr;
			parent = nullptr;
		}

		void setLeft(Node *n) { left = n; }
		void setRight(Node *n) { right = n; }
		void setParent(Node *n) { parent = n; }

		Node *getLeft() { return left; }
		Node *getRight() { return right; }
		Node *getParent() { return parent; }

		void add(Node *n) {
			if (n < this) {
				if (left)
					left->add(n);
				else {
					left = n;
					n->setParent(this);
				}
			} else {
				if (right)
					right->add(n);
				else {
					right = n;
					n->setParent(this);
				}
			}
		}

		void display() {
			data->display();
		}
};
