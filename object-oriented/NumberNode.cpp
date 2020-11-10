#include "Node.cpp"

class NumberNode: public Node<int>{
	public:
		NumberNode(PhoneBookEntry *pbe)     : Node(*pbe) {};

		bool operator<(Node& n) {return this->data.number < n.data.number;}
		bool operator>(Node& n) {return this->data.number > n.data.number;}
		bool operator==(Node& n) {return this->data.number == n.data.number;}

		bool operator<(int i) {return this->data.number < i;}
		bool operator>(int i) {return this->data.number > i;}
		bool operator==(int i) {return this->data.number == i;}
};
