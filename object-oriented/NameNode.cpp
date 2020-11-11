#include "Node.cpp"

class NameNode: public Node<string>{
	public:
		NameNode(PhoneBookEntry *pbe) : Node(*pbe) {};
		string getKey() const {return data.name;}
};
