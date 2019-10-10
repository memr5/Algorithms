#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree
{
	int info;
	struct tree *left,*right;
	
};
struct tree *root=NULL;
struct tree *create_tree(struct tree *node,int n);

void preorder(struct tree *node);
void inorder(struct tree *node);
void postorder(struct tree *node);

main()
{
	int n, choice;
	while(1)
	{
		printf("\n MAIN MENU");
		printf("\n1.create tree");
		printf("\n2.preorder travesing");
		printf("\n3.inorder travesing");
		printf("\n4.post traversing");
		printf("\n5.exit");
	    printf("\n  enter your choice(1-5):");
		
		scanf("%d",&choice);
		switch(choice)
	{
		case 1:
			printf("enter the value");
			scanf("%d",&n);
			root=create_tree(root,n);
			break;
			
			
		case 2:
		    preorder(root);
			break;
			
		case 3:
		     inorder(root);
			 break;
		case 4:
		    postorder(root);
			break;
			
		case 5:
		   exit(0);		 			
		}	
				
	}
}// end of switch//
// end of while//
// end of main()//



// function for create tree

struct tree *create_tree(struct tree *node,int value)
{
	if(node==NULL)
	{
		struct tree* tree = (struct tree*)malloc(sizeof(struct tree));	 
		node->info=NULL;
		node->left=NULL;
		node->right=NULL;
		
		return(node);
	}
	else
	{
		if(value<node->info)
		{
			node->left=create_tree(node->left,value);
		}
		else{
			node->right=create_tree(node->right,value);
		}
	}
		
		
		return(node);
	}
	// end of create tree//

//non recrusive function for preoder tree

void preorder(struct tree *node)
{
	struct tree *stack[10];
	int top=1;
	stack [0]=NULL;
	while(node!=NULL)
	{
		printf("%d \t",node->info);
		if(node->right!=NULL)
		{
			stack[top++]=node->right;
			node=node->left;
		}
		else
		{
			node=stack[--top];
		}
	}
}// end of preorder//



// non recrusive function for inorder travesing

void inorder(struct tree *node)
{
	struct tree *stack[10];
	int top=1;
	stack [0]=NULL;
	repeat:
		while(node!=NULL)
		{
			stack[top++]=node;
			node=node->left;
			
		}
		node=stack[--top];
		while(node!=NULL)
		{
			printf("%d \t",node->info);
			
			if(node->right!=NULL)
			{
				node=node->right;
				goto repeat;
			}
			else
			{
				node=stack[--top];
			}
		
		}
	}
		
		// end of inorder///
		
		// non recrusive function for postorder
		
		
		void postorder(struct tree *node)
		{
			struct tree *stack1[10],*stack2[10];
			int top1=1,top2=0,i;
	        while(node!=NULL)
			{
				stack2[top2++]=node;
		        if(node->left!=NULL)
		        {\
		        	stack1[top1++]=node->left;
				}
				if(node->right!=NULL)
		        {
		        	stack1[top1++]=node->right;
				}
				node=stack1[--top1];
			}	
			for(i=top2-1;i>=0;i--)
			{
				node=stack2[i];
				printf("%d \t",node->info);
			}
			
			
			
		}
	

