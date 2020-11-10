#include "Node.cpp"

class NumberNode: public Node{
	public:
		bool operator<(Node *n) {return this->data->number < n->data->number;}
		bool operator>(Node *n) {return this->data->number > n->data->number;}
		bool operator==(Node *n) {return this->data->number == n->data->number;}
};
