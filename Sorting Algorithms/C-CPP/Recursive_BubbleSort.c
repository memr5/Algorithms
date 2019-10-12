#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int c=0;
void bubbleSort(int arr[], int n) 
{ 
    int swap;
    if (n == 1) 
        return ; 
    for (int i=0; i<n-1; i++) 
    {
        
        if (arr[i] > arr[i+1]) 
        {
           swap=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=swap;
        }
    }
    c++;
    bubbleSort(arr, n-1);
    
}

int main() 
{
    int m,i;
    int arr[1000];
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&arr[i]);
    bubbleSort(arr,m);
    printf("recursion has been called %d times\n",c);
    for(i=0;i<m;i++)
        printf("%d ",arr[i]);
    
}

