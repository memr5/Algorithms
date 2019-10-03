//u have to enter sorted array or have to sort by any method convinient to you
#include<stdio.h>
#include<stdlib.h>
int min(int x,int y)
{
  if(x>y)
  return x;
  else
  return y;
}

int binarysearch(int *a,int l,int r,int value)
{
  int j=-1;
  int mid=(r+l)/2;
  if(a[mid]==value)
  {
    j=mid;
  }
  else if(value<a[mid])
  {
    j=binarysearch(a,l,mid-1,value);
  }
  else
  {
    j=binarysearch(a,mid+1,r,value);
  }
  return j;
}
int exponentialsearch(int *a,int n,int x)
{
  int i=1,j=-1;
  if(a[0]==x)
  {j=0;}
  while(i<n&&a[i]<=x)
  {i=i*2;}
  j=binarysearch(a,i/2,min(i,n),x);
  return j;
}
void main()
{
  int *a,n,i,j;
  printf("how many number u want to enter :\n");
  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);
  printf("enter numbers:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("enter num u want to search:");
  scanf("%d",&i);
  j=exponentialsearch(a,n,i);
  if(j!=-1)
  {
    printf("search succesful:value %d is present at index %d",i,j);
  }
  else
  {
    printf("searched number is not present");
  }
}
