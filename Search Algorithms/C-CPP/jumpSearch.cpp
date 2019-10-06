// C++ program to implement Jump Search 

#include <bits/stdc++.h> 
using namespace std; 

int jumpSearch(int arr[], int x, int n) 
{ 
	int step = sqrt(n); 
	int prev = 0; 
	while (arr[min(step, n)-1] < x) 
	{ 
		prev = step; 
		step += sqrt(n); 
		if (prev >= n) 
			return -1; 
	} 
	while (arr[prev] < x) 
	{ 
		prev++; 
		if (prev == min(step, n)) 
			return -1; 
	} 
	if (arr[prev] == x) 
		return prev; 

	return -1; 
} 

// Main function 
int main() 
{ 
	int n;
	cout << "Enter the number of elements :" << endl;
	cin >> n;
	int arr[n];
	cout << "Enter elements :" << endl;
	for(int i=0; i<n; i++)
		cin >> arr[i]; 
	int key = 0;
	cout << "Enter Key to be found : " << endl;
	cin >> key;  
	int index = jumpSearch(arr, key, n); 
	cout << "\nNumber " << key << " is at index " << index; 
	return 0; 
}
