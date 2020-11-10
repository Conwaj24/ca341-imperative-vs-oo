#pragma once
#include "PhoneBookEntry.cpp"

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

		Node<T> search(T target) {
			if (this > target && left)
				return left->search(target);
			else if (this < target && right)
				return right->search(target);
			else
				return this;
		}

		void orphan() {
			if (!parent)
				return;
			if (parent->left == this)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}

		void display() {
			data.display();
		}

		void remove() {
			if (!parent) //not our responsibility if we are the root node
				return;

			orphan();
			if (left) {
				parent->add(left);
				left = nullptr;
			} if (right) {
				parent->add(right);
				right = nullptr;
			}
			delete this;
		}

		~Node() {
			orphan();
			delete left;
			delete right;
		}
};
