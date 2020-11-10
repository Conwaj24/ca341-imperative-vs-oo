#pragma once
#include "PhoneBookEntry.cpp"
#include "IComparable.cpp"

template <typename T>
class Node {
	Node *left;
	Node *right;
	Node *parent;
	public:
		PhoneBookEntry& data;

		Node(PhoneBookEntry &givenData) : data(givenData) {
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

		virtual bool operator<(Node& cmp) = 0;
		virtual bool operator>(Node& cmp) = 0;
		virtual bool operator==(Node& cmp) = 0;

		virtual bool operator<(T cmp) = 0;
		virtual bool operator>(T cmp) = 0;
		virtual bool operator==(T cmp) = 0;

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
			data.display();
		}
};
