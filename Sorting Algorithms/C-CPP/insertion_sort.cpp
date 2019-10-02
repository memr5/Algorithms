#include<iostream>
using namespace std;

void InsertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(a[j]<a[j-1] && j>0){
            int temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            --j;
        }
    }
}

int main(){
    int a[]={12, 11, 13, 5, 6};

    InsertionSort(a,5);

    for(int i=0;i<5;i++){
        cout<<a[i]<<' ';
    }
return 0;
}
