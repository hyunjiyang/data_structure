#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct node {
	int data;
	node* left;
	node* right;
}node;

typedef struct list {
	struct node* head;
	struct node* tail;
	int cnt;
}list;


void Init(linkedList* L) { 
	L->head = NULL; L->tail = NULL; L->cnt = 0; 
}

void create_node() {
	struct node* head = malloc(sizeof(node));
}



void main() {

	int middle;
	int data[] = { 1, 3, 5, 6, 7, 8, 11, 12, 14, 15, 24, 26, 42, 43, 49, 48, 51, 55, 56, 59, 66, 67, 69, 70, 71, 73, 75, 80, 96, 99 };
	int search;

	printf("찾을 숫자 : ");
	scanf_s("%d", &search);

	binsearch(list, search);

	return 0;
}


void display(tree* p) {
	if (p != NULL)
		printf("(");
	display(p->left);
	printf("%d", p->key.data);
	display(p->right);
}

int compare(element e1, element e2) {
	if (e1.data < e2.data) return -1;
	if (e1.data == e2.data) return 0;
	if (e1.data > e2.data) return 1;
}

void* search(tree* root, element key) {
	tree* p = root;
	element e1, e2;
	while (p != NULL) {
		switch (compare(key, p->key)) {
		case -1:
			p = p->left;
			break;
		case 0:
			return p;
		case 1:
			p = p->right;
			break;
		}
	}
	return p;
}


void* search(tree* node, int key) {
	while (node != NULL) {
		if (key == node->key)) return node;
		p = t;
		if (compare(key, t->key) < 0) t = t->left;
		else
			t = t->right;
	}


	void insert(tree * *root, element key) {
		tree* p, * t;
		tree* n;
		t = *root;
		p = NULL;

		//탐색먼저
		while (t != NULL) {
			if (compare(key, t->key) == 0) return;
			p = t;
			if (compare(key, t->key) < 0) t = t->left;
			else
				t = t->right;
		}

		n = (node*)malloc(sizeof(node));
		if (n = NULL) return;
		n->key = key;
		n->left = n->right = NULL;

		if (p != NULL)
			if (compare(key, t->key) < 0)
				p->left = n;
			else p->right = n;
		else *root = n;
	}

	void main() {
		element e;
		tree* root = NULL;
		tree* tmp;
		int i;

		for (i = 0; i < 30; i++) {
			printf("입력할 숫자 :");
			scanf_s(e.data);
			insert(&root, e);
		}

		printf("찾을 숫자 : ");
		scanf_s(e.data);
		tmp = search(root, e);
		if (tmp != NULL)
			printf("숫자\n", e.data);
	}
