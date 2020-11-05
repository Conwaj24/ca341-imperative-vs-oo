#include "extra.c"
#include "phonebook.c"

#define RED(s) "\e[91m" s "\e[39m"
void exploreTree(node *root) {
	
}

int main() {
	phonebookEntry *pbe = newPhonebookEntry("steve", "nowhere", 10);
	node *root = newNode(pbe);

	addToTree(newPhonebookEntry("john", "a", 6), root);
	addToTree(newPhonebookEntry("jill", "b", 18), root);
	addToTree(newPhonebookEntry("sam", "c", 12), root);
	addToTree(newPhonebookEntry("guy", "d", 0), root);
	addToTree(newPhonebookEntry("norm elman", "e", 32), root);
	addToTree(newPhonebookEntry("stew", "f", 17), root);
	addToTree(newPhonebookEntry("alice", "g", 9), root);
	addToTree(newPhonebookEntry("kevin", "h", 1), root);
	addToTree(newPhonebookEntry("kate", "i", 3), root);
	addToTree(newPhonebookEntry("jamie", "j", 7), root);

	//display(searchTreeForNumber(root, 12));
	//display(searchTreeForNumber(root, 6));
	freeNode(root);
	return 0;
}
