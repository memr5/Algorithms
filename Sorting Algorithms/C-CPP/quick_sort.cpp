#include <iostream>
using namespace std;
void swap(int *a,int *b)
{
    int p=*a;
    *a=*b;
    *b=p;
}
int partition(int h,int l,int s[])
{
    int pivot=s[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++)
    {
        if (s[j]<=pivot)
        {
                /* code */
            i++;
            swap(&s[i],&s[j]);
        }
    }
    swap(&s[i+1],&s[h]);
    return (i+1);
}
void quicksort(int l,int h,int k[])
{
    if(l<h)
    {
        int pi=partition(h,l,k);
        quicksort(l,pi-1,k);
        quicksort(pi+1,h,k);
    }
}
int main()
{
    
}