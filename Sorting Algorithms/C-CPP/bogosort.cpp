// C++ implementation of Bogo Sort 
#include<bits/stdc++.h> 
using namespace std; 
  
// To check if array is sorted or not 
bool isSorted(int a[], int n) 
{ 
    for(int i=0; i<n-1; i++){
		if(a[i] > a[i+1])
			return false;
	}
    return true; 
} 
  
// To generate permuatation of the array 
void shuffle(int a[], int n){ 
    for (int i=0; i < n; i++) 
        swap(a[i], a[rand()%n]); 
} 
  
// Sorts array a[0..n-1] using Bogo sort 
void bogosort(int a[], int n){ 
    // if array is not sorted then shuffle 
    // the array again 
    while (!isSorted(a, n)) 
        shuffle(a, n); 
} 
  
// prints the array 
void printArray(int a[], int n) 
{ 
    for (int i=0; i<n; i++) 
        printf("%d ", a[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int n;
    cout << "Please enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Please enter the elements of the array which will be sorted: \n";
    for(int i=0; i<n; i++) cin >> a[i];
    bogosort(a, n); 
    printf("Here is the sorted array :\n"); 
    printArray(a,n); 
    return 0; 
} 
