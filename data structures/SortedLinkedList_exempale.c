#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
typedef struct item {
	int val;
	struct item* next;
	struct item* prev;
}item;

void printLinkedList(struct item* head);

int main() {

	int check;
	struct item* curr = NULL;
	struct item* head = NULL;
	struct item* tail = NULL;

	time_t i = time();
	srand(i);

	for (int i = 0; i < 10; i++) {
		check = rand();
		curr = malloc(sizeof(item));
		
		if (head == NULL) {
			curr->val = check;
			head = curr;
			tail = curr;
			curr->next = NULL;
		}
		else {
			if (check > head->val) {
				struct item* runner = head;
				while (runner->val < check && runner->next != NULL) {
					runner = runner->next;
				}
				if (runner->next == NULL && runner->val < check) {
					runner->next = curr;
					curr->prev = runner;
					curr->val = check;
					tail = curr;
					tail->next = NULL;
				}
				else{
				runner->prev->next = curr;
				curr->prev = runner->prev;
				runner->prev = curr;
				curr->next = runner;
				curr->val = check;
				if (curr->next == NULL) {
					tail = curr;
					tail->next = NULL;
				}
				}
			}
			else {
				curr->next = head;
				head->prev = curr;
				head = curr;
				head->val = check;
			}

		}
		
	}
	printLinkedList(head);
}

void printLinkedList(struct item* head) {
	struct item* r = head;

	while (r->next != NULL) {
		printf(" %d ->", r->val);
		r = r->next;
	}
	printf(" NULL");
}
