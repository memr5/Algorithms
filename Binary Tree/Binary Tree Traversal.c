#include<stdio.h>
#include<stdlib.h>

typedef struct cell{
	int elem;
	struct cell * left;
	struct cell * right;
}*Tree;

void initTree(Tree *T);
void insertTree(Tree *T, int elem);
void displayInOrder(Tree T);
void displayPreOrder(Tree T);
void displayPostOrder(Tree T);
void deleteTree(Tree *T, int elem);

int main(void){
	
	Tree T;
	initTree(&T);
	
	insertTree(&T, 50);
	insertTree(&T, 30);
	insertTree(&T, 20);
	insertTree(&T, 40);
	insertTree(&T, 70);
	insertTree(&T, 60);
	insertTree(&T, 80);
	
	
	printf("In Order: \n");
	displayInOrder(T);
	
	printf("\n\nPre Order: \n");
	displayPreOrder(T);
	
	printf("\n\nPost Order: \n");
	displayPostOrder(T);
	
//	deleteTree(&T, 50);
//	printf("In Order: \n");
//	displayInOrder(T);
	return 0;
}

void initTree(Tree *T){
	*T = NULL;
}

void insertTree(Tree *T, int elem){
	Tree temp, *trav;
	for(trav = T; *trav!=NULL && (*trav)->elem!=elem;){
		trav = ((*trav)->elem < elem)? &(*trav)->right : &(*trav)->left; 
	}
	
	if(*trav == NULL){
		temp = (Tree)malloc(sizeof(struct cell));
		if(temp!=NULL){
			temp->elem = elem;
			temp->left = temp->right = NULL;
			*trav = temp;
		}
	}
}


void displayInOrder(Tree T){
	if(T!=NULL){
		displayInOrder(T->left);
		printf("\n%d\n", T->elem);
		displayInOrder(T->right);
	}
}

void displayPreOrder(Tree T){
	if(T!=NULL){
		printf("\n%d\n", T->elem);
		displayPreOrder(T->left);
		displayPreOrder(T->right);
	}
}

void displayPostOrder(Tree T){
	if(T!=NULL){
		displayPostOrder(T->left);
		displayPostOrder(T->right);
		printf("\n%d\n", T->elem);
	}
}

void deleteTree(Tree *T, int elem){
	Tree *trav, temp;
	for (trav = T; *trav != NULL && (*trav)->elem != elem; ){	
		if ((*trav)->elem > elem) {
			trav = &(*trav)-> left;
		} else {
			trav = &(*trav)-> right;
		}
		// trav = ((*trav)->elem > elem ) ? &(*trav)-> left : &(*trav)-> right		
	}
	
	if (*trav != NULL) {
		temp = *trav;
		if ((*trav)->right == NULL) {
			*trav = (*trav)->left;
		} else if ((*trav)->left == NULL) {
			*trav = (*trav)->right;
		} else if ((*trav)->right != NULL && (*trav)->left != NULL){
			for (trav = &(*trav)->left; (*trav)->right != NULL; trav = &(*trav)->right) {}
			temp->elem = (*trav)->elem;
			temp = *trav;
			*trav = temp->left;
		}
		free(temp);
	}
	
}
