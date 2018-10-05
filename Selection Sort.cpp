#include<iostream>
//The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order)
// from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

//1) The subarray which is already sorted.
//2) Remaining subarray which is unsorted.

//In every iteration of selection sort,
//the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
using namespace std;

void SelectionSort(int a[],int n){
    int x=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                x=j;
            }
        }
        int temp=a[i];
        a[i]=a[x];
        a[x]=temp;
    }
}

int main(){
    int a[]={64,22,25,12,11};

    SelectionSort(a,5);

    for(int i=0;i<5;i++){
        cout<<a[i]<<' ';
    }
return 0;
}
