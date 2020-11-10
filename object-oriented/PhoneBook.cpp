#include "NameNode.cpp"
#include "NumberNode.cpp"

class PhoneBook {
	NumberNode numRoot;
	NameNode nameRoot;
	public:
	void add(PhoneBookEntry pbe) {
		numRoot.add(new NumberNode(pbe));
		nameRoot.add(new NameNode(pbe));
	}
};
