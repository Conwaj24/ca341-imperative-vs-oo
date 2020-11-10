#include "Node.cpp"

class NameNode: public Node<string>{
	public:
		NameNode(PhoneBookEntry *pbe) : Node(*pbe) {};

		bool operator<(Node& n) {return this->data.name < n.data.name;}
		bool operator>(Node& n) {return this->data.name > n.data.name;}
		bool operator==(Node& n) {return this->data.name == n.data.name;}
};
