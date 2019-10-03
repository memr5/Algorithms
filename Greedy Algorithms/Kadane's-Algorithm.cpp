// Kadane's Algorithm to find largest sum contigous subarray
#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n){
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    for(int i = 0; i < n; i++){
        maxEndingHere = maxEndingHere + arr[i];
        if(maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
        if(maxEndingHere < 0)
            maxEndingHere = 0;
    }
    return maxSoFar;
}

int main(){
  int n = 10;
  int arr[] ={5, -9, 3, -4, 1, 4, 4, -10, 12, 13};
  int sum = kadane(arr, n);
  cout<<"Largest Sum = "<<sum;
  return 0;
}
