/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.
*/

#include<bits/stdc++.h>  
using namespace std; 

int lis( int arr[], int n )  
{  
    int lis[n]; 
   
    lis[0] = 1;    
  
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    return *max_element(lis, lis+n); 
}  
    
int main()  
{  
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
    int n = sizeof(arr)/sizeof(arr[0]);  
    printf("Length of lis is %d\n", lis( arr, n ) );  
    return 0;  
}
