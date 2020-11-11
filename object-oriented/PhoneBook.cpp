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

		PhoneBookEntry searchForNumber(int number) {
			PhoneBookEntry out = numRoot->search(number).data;
			if (out.number != number) {
				cerr << "Could not find " << number << endl;
				return NULL;
			}
			return out;
		}

		PhoneBookEntry searchForName(string name) {
			PhoneBookEntry out = nameRoot->search(name).data;
			if (out.name != name) {
				cerr << "Could not find " << name << endl;
				return NULL;
			}
			return out;
		}
};
