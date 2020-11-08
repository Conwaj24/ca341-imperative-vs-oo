#include "PhoneBookEntry.cpp"

class Node {
	public:
		PhoneBookEntry *data;

		Node(PhoneBookEntry *data) {
			this->data=data;

			left = nullptr;
			right = nullptr;
			parent = nullptr;
		}

	private:
		Node *left;
		Node *right;
		Node *parent;
};
