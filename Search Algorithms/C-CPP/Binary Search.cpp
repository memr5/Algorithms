#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],i,x,left,right,mid,f=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>x;		//number to be searched
	left=0;
	right=n-1;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==x)
		{
			cout<<"present in the array at "<<mid+1;
			f=1;
			break;
		}
		else if(a[mid]>x)
			right=mid-1;
		else
			left=mid+1;
	}
	if(left>right && f==0)
		cout<<"Does not exist in the array";
	return 0;
}
