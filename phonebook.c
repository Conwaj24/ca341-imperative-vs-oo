#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	char *name;
	char *address;
	int number;
} phonebookEntry;

typedef struct node {
	struct node *parent;
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
	out->left = NULL;
	out->right = NULL;
	out->parent = NULL;
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

node *searchTreeForNumber(int number, node *root) {
	if (root->left && number < root->data->number)
		return searchTreeForNumber(number, root->left);
	if (root->right && number > root->data->number)
		return searchTreeForNumber(number, root->right);
	return root;
}

void addNodeToTree(node *n, node *root) {
	if (n == NULL)
		return;
	node *parent = searchTreeForNumber(n->data->number, root);
	n->parent = parent;
	if (n->data->number < parent->data->number) {
		n->left = parent->left;
		parent->left = n;
	} else {
		n->right = parent->right;
		parent->right = n;
	}
}

void addToTree(phonebookEntry *item, node *root) {
	node *n = newNode(item); 
	addNodeToTree(n, root);
}

node *findNode(node *root, int number) {
	node *n = searchTreeForNumber(number, root);
	if (n->data->number != number)
		n = NULL;
	return n;
}

bool kidnap(node *n) {
	//remove node from its parent
	if (! n->parent)
		return false;

	if (n->parent->left == n)
		n->parent->left = NULL;
	else
		n->parent->right = NULL;
	return true;
}
	
void removeNodeFromTree(node* n) {
	kidnap(n);
	addNodeToTree(n->left, n->parent);
	n->left = NULL;
	addNodeToTree(n->right, n->parent);
	n->right = NULL;
	freeNode(n);
}

void removeFromTree(int key, node *root) {
	node *n = findNode(root, key);
	if (n != NULL) 
		removeNodeFromTree(n);
}

