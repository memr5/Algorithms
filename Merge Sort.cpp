#include<iostream>
using namespace std;

#define MAXSIZE 100

void Merge(int a[],int l1,int h1,int l2,int h2){
    int i=0,j,low=l1;
    int b[MAXSIZE];

    while( l1<=h1 && l2<=h2 ){
        if(a[l1]<a[l2]){
            b[i++]=a[l1++];
        }
        else{
            b[i++]=a[l2++];
        }
    }

    while(l1<=h1){
        b[i++]=a[l1++];
    }

    while(l2<=h2){
        b[i++]=a[l2++];
    }

    for(j=0;j<i;j++){
        a[low++]=b[j];
    }
}

void Merge_Sort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;

        Merge_Sort(a,low,mid);
        Merge_Sort(a,mid+1,high);
        Merge(a,low,mid,mid+1,high);
    }
}

int main(){
    int n;
    cout<<"Enter Number of Elements you want to add in array (Max Size 100) : ";
    cin>>n;
    int a[n];
    cout<<"Enter all elements separated: "
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Befor Sorting: ";

    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
    Merge_Sort(a,0,n-1);

    cout<<"After Sorting: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
return 0;
}
