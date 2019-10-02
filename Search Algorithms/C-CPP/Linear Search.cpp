#include<iostream>
using namespace std; 
  
int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
int main(void) 
{   
	int n,x; 
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int result=search(arr,n,x);
	if(result==-1)
	{
		cout<<"element not found";
	}
	else
		cout<<"element found:"<<result;
} 