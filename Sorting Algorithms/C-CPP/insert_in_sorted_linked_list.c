#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node* next;
};

// insert value while keeping linked list sorted
struct node* insertInSorted(struct node *s, int x) {
	struct node* p;
	p = (struct node*) malloc(sizeof(struct node));
	p->val = x;
	if (s == NULL) {
		s = p;
		p->next = NULL;
	}
	else if (x <= s->val) {
		p->next = s;
		s = p;
	}
	else {
		struct node *q = s;
		while (q->next != NULL && q->next->val < x) {
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
	}
	return s;
}

// delete value x in a sorted linked list
struct node* deleteNodeInSorted(struct node* s, int x) {
	struct node *p = NULL, *q = s;
	if (s == NULL)
		return s;
	while (q != NULL && q->val < x) {
		p = q;
		q = q->next;
	}
	if (q != NULL && q->val == x) {
		if (p == NULL)
			s = q->next;
		else
			p->next = q->next;
		free(q);
	}
	return s;
}

void display(struct node *s) {
	struct node *p = s;
	while (p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

int main() {

	struct node *s = NULL;
	printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");

	while (1) {

		int choice, x;
		scanf("%d", &choice);

		switch (choice) {

		case 1:
			printf("\nEnter value to insert: ");
			scanf("%d", &x);
			s = insertInSorted(s, x);
			break;

		case 2:
			printf("\nEnter value to delete: ");
			scanf("%d", &x);
			s = deleteNodeInSorted(s, x);
			break;

		case 3:
			display(s);

		case 4:
			exit(1);

		default:
			printf("Invalid option selected");
		}
	}

	return 0;
}