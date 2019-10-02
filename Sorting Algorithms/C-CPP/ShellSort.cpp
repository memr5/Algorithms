#include <iostream>
using namespace std;

void shellSort(int a[],int n)
 for (int gap = n / 2; gap > 0; gap /= 2) { 
 for (int i = gap; i < n; i += 1) { 
 int temp = a[i]; 
 int j;
  for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
   a[j] = a[j - gap]; 
   a[j] = temp; 
        } 
    } 
} 

void display(int a[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    cout << a[i] << " "; 
    cout << "\n"; 
} 

int main(){

int a[] = { 92, 50, 28, 43 }; 
    int n = sizeof(a) / sizeof(arr[0]); 
  
    cout << "Array before sorting: \n"; 
    display(a, n); 
  
    shellSort(a, n); 
  
    cout << "Array after sorting: \n"; 
    display(a, n); 
    
    return 0;
} 
