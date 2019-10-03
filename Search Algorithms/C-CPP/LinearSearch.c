#include<stdio.h>
  
int search(int arr[], int n, int x) 		//Function for linear search
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i+1; 
    return -1; 
} 
int main(void) 
{   
	int n,x,i;
	printf("\nEnter the number of elements:- "); 
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements:- ");
	for( i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nEnter the elements you want to search:- ");
	scanf("%d",&x);
	int result=search(arr,n,x);
	if(result==-1)
	{
		printf("\nelement not found");
	}
	else
		printf("element found at index:- %d",result);
		
	return 0;
}
