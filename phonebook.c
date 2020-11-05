#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *name;
	char *address;
	int number;
} phonebookEntry;

typedef struct node {
	struct node *left;
	struct node *right;
	phonebookEntry *data;
} node;

phonebookEntry *newPhonebookEntry(char *name, char *address, int number) {
	phonebookEntry *out = malloc(sizeof(phonebookEntry));
	out->name = strdup(name);
	out->address = strdup(address);
	out->number = number;
	return out;
}

void freePhonebookEntry(phonebookEntry *pbe) {
	free(pbe->name);
	free(pbe->address);
	free(pbe);
}

node *newNode(phonebookEntry *data) {
	node *out = malloc(sizeof(node));
	out->data = data;
	return out;
}

void freeNode(node *n) {
	free(n->left);
	free(n->right);
	freePhonebookEntry(n->data);
	free(n);
}

void displaypbe(phonebookEntry *pbe){
	fprintf(stdout, "%s\n%s\n%i\n", pbe->name, pbe->address, pbe->number);
}

void display(node *n){
	if (n)
		displaypbe(n->data);
	else
		printf("NULL\n");
	printf("");
}

node *searchTreeForNumber(node *root, int number) {
	if (root->left && number < root->data->number)
		return searchTreeForNumber(root->left, number);
	if (root->right && number > root->data->number)
		return searchTreeForNumber(root->right, number);
	return root;
}

void addToTree(phonebookEntry *item, node *root) {
	node *n = newNode(item); 
	node *parent = searchTreeForNumber(root, item->number);
	if (item->number < parent->data->number) {
		n->left = parent->left;
		parent->left = n;
	} else {
		n->right = parent->right;
		parent->right = n;
	}
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
