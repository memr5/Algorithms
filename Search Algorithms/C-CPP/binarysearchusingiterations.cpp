#include<iostream>
using namespace std;
int binarysearch(int a[],int f,int l,int find)
{
	while(f<=l)
	{
		int m=f+(l-f)/2;
		if(a[m]==find)
		{
			return m;
		}
		else if(a[m]>find)
		{
			l=m-1;
		}
		else
		f=m+1;
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
	int f=0;
	int l=n-1;
	int result=binarysearch(a,f,l,find);
	if(result==-1)
	{
		cout<<"Not Found";
	}
	else
	{
		cout<<"Found at index "<<result+1;
	}
}
