#include<iostream>
using namespace std;
void BinarySearch(int arr[],int n,int item)			//Function for Binary Search
{
	int beg=0,mid,end,count=0;
	end=n-1;
	while(beg!=end)
	{
		mid=(beg+end)/2;
		if(arr[mid]==item)
		{
			cout<<"\nItem found. Index is= "<<mid+1;
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
		cout<<"\nItem not found.";
	}	
}
int main()
{
	int n,item;
	cout<<"\nEnter the number of elements you want you enter= ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the array elements(in ascending order)=";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\nEnter the element to be searched= ";
	cin>>item;
	BinarySearch(a,n,item);
	return 0;
}
