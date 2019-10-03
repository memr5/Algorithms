#include<stdio.h>
void BinarySearch(int arr[],int n,int item)			//Function for Binary Search
{
	int beg=0,mid,end,count=0;
	end=n-1;
	while(beg!=end)
	{
		mid=(beg+end)/2;
		if(arr[mid]==item)
		{
			printf("\nItem found. Index is= %d",mid+1);
			count++;
			break;
		}
		else if(arr[mid]<item)
		{
			beg=mid+1;
		}
		else if(arr[mid]>item)
		{
			end=mid-1;
		}
	}
	if(count==0)
	{
		printf("\nItem not found");
	}
}
int main()
{
	int n,item,i;
	printf("\nEnter the number of elements you want you enter= ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the array=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to be searched= ");
	scanf("%d",&item);
	BinarySearch(a,n,item);
	return 0;
}
