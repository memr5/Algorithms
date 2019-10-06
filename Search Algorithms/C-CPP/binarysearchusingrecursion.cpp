#include<iostream>
using namespace std;
int binarysearch(int a[],int f,int l,int find)
{
	if(l>=f)
	{
		int mid=f+(l-f)/2;
		if(a[mid]==find)
		{
			return mid;
			
		}
		if(a[mid]>find)
		{
			return binarysearch(a,f,mid-1,find);
		}
			return binarysearch(a,mid+1,l,find);
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int find;
	cin>>find;
	int f,l;
	f=0;
	l=n-1;
	int result=binarysearch(a,f,l,find);
	if(result==-1)
	{
		cout<<"Not Found";
	}
	else
	{
		cout<<"Found at "<<result+1;
	}
}
