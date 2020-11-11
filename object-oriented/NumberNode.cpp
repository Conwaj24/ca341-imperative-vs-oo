#include "Node.cpp"

class NumberNode: public Node<int>{
	public:
		NumberNode(PhoneBookEntry *pbe)     : Node(*pbe) {};
		int getKey() const {return data.number;}

};
