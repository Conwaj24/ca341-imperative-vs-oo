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

void addToTree(phonebookEntry *item, node *root) {
}

void display(phonebookEntry *pbe){
	fprintf(stdout, "%s\n%s\n%i\n", pbe->name, pbe->address, pbe->number);
}

int main() {
	phonebookEntry *pbe = newPhonebookEntry("steve", "nowhere", 19216811);
	display(pbe);
	node *n = newNode(pbe);
	freeNode(n);
	return 0;
}
