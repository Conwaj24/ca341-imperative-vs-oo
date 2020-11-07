#include "extra.c"
#include "phonebook.c"
#define RED(s) "\e[91m" s "\e[39m"

void exploreTree(node *curr) {
	for (;;) {
		display(curr);
		char c = getUserInput();
		switch (c) {
			case 'j':
				exploreTree(curr->left);
				break;
			case 'l':
				exploreTree(curr->right);
				break;
			case 'k':
				return;
				break;
			case 'x':
				removeFromTree(curr->data->number);
				exploreTree(root);
			default:
				error("invalid key");
		}
	}
}

int main() {
	root = newNode(newPhonebookEntry("steve", "nowhere", 10));

	addToTree(newPhonebookEntry("john", "a", 6));
	addToTree(newPhonebookEntry("jill", "b", 18));
	addToTree(newPhonebookEntry("sam", "c", 12));
	addToTree(newPhonebookEntry("guy", "d", 0));
	addToTree(newPhonebookEntry("norm elman", "e", 32));
	addToTree(newPhonebookEntry("stew", "f", 17));
	addToTree(newPhonebookEntry("alice", "g", 9));
	addToTree(newPhonebookEntry("kevin", "h", 1));
	addToTree(newPhonebookEntry("kate", "i", 3));
	addToTree(newPhonebookEntry("jamie", "j", 7));

	exploreTree(root);
	freeNode(root);
	return 0;
}
