#include "NameNode.cpp"
#include "NumberNode.cpp"

class PhoneBook {
	NumberNode *numRoot;
	NameNode *nameRoot;
	public:
		PhoneBook(PhoneBookEntry *pbe) {
			numRoot = new NumberNode(pbe);
			nameRoot = new NameNode(pbe);
		}

		void add(PhoneBookEntry *pbe) {
			numRoot->add(new NumberNode(pbe));
			nameRoot->add(new NameNode(pbe));
		}
};
