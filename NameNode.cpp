#include "Node.cpp"

class NameNode: public Node{
	public:
		bool operator<(Node *n) {return this->data->name < n->data->name;}
		bool operator>(Node *n) {return this->data->name > n->data->name;}
		bool operator==(Node *n) {return this->data->name == n->data->name;}
};
