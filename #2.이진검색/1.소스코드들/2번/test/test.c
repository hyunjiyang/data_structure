#include <stdio.h>
#include <stdlib.h>


// 노드 구조체
typedef struct node{
	int data;
	node* next;
}node;

node* head;
int count;

void add(node* target, int data) { //노드추가함수
	node* new = malloc(sizeof(node)); //새 노드 생성
	new->next = target->next; //새 노드 다음에 기준 노드의 다음노드 지정.
	new->data = data; //새노드 데이터 저장.
	target->next = new; //새노드를 기준노드로 지정
}
int main() {
	node* head = malloc(sizeof(node)); //머리노드생성
	head->next = NULL; //머리는 비어있음

	add(head, 1); add(head, 3);	add(head, 5); add(head, 6);	add(head, 7); add(head, 8);	add(head, 11);	add(head, 12);	add(head, 14);	add(head, 15);	add(head, 24); 	add(head, 26);	add(head, 42);	add(head, 43);	add(head, 49);	add(head, 48); 	add(head, 51);	add(head, 55);	add(head, 56); 	add(head, 59);	add(head, 66);	add(head, 67);	add(head, 69);	add(head, 70);	add(head, 71);	add(head, 73);	add(head, 75);	add(head, 80);	add(head, 96);	add(head, 99);



	int search;

	printf("찾을 숫자 : ");
	scanf_s("%d", &search);
}


node* cur = head->next;

while (curr != NULL) {
	curr->data = count
}


void* search(node* node, int key) {
	while (node != NULL) {
		if (key == node->key)) return node;
		p = t;
		if (compare(key, t->key) < 0) t = t->left;
		else
			t = t->right;
	}