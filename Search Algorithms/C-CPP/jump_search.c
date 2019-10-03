//u have to enter sorted array or have to sort by any method convinient to you
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int jumpsearch(int *a,int n,int x)
{
  int temp,j=-1;
  int jumpstep=sqrt(n);//step to be jumped to serach a number
  while(a[jumpstep-1]<x)
  {
    jumpstep+=sqrt(n);
    if(jumpstep>n)
    {break;}
  }
  temp=jumpstep;
  jumpstep-=sqrt(n);
  while(a[temp-1]!=x)
  {
    temp--;
    if(temp==jumpstep)
    break;
  }
  if(a[temp-1]==x)
  {
    j=temp-1;//u have to enter sorted array or have to sort by any method convinient to you
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int jumpsearch(int *a,int n,int x)
{
  int temp,j=-1;
  int jumpstep=sqrt(n);//step to be jumped to serach a number
  while(a[jumpstep-1]<x)
  {
    jumpstep+=sqrt(n);
    if(jumpstep>n)
    {break;}
  }
  temp=jumpstep;
  jumpstep-=sqrt(n);
  while(a[temp-1]!=x)
  {
    temp--;
    if(temp==jumpstep)
    break;
  }//u have to enter sorted array or have to sort by any method convinient to you
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int jumpsearch(int *a,int n,int x)
{
  int temp,j=-1;
  int jumpstep=sqrt(n);//step to be jumped to serach a number
  while(a[jumpstep-1]<x)
  {
    jumpstep+=sqrt(n);
    if(jumpstep>n)
    {break;}
  }
  temp=jumpstep;
  jumpstep-=sqrt(n);
  while(a[temp-1]!=x)
  {
    temp--;
    if(temp==jumpstep)
    break;
  }
  if(a[temp-1]==x)
  {
    j=temp-1;
  }
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
    j=jumpsearch(a,n,i);
    if(j!=-1)
    {
      printf("search succesful:value %d is present at index %d",i,j);
    }
    else
    {
      printf("searched number is not present");
    }
  }

  if(a[temp-1]==x)
  {
    j=temp-1;
  }
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
    j=jumpsearch(a,n,i);
    if(j!=-1)
    {
      printf("search succesful:value %d is present at index %d",i,j);
    }
    else
    {
      printf("searched number is not present");
    }
  }

  }
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
    j=jumpsearch(a,n,i);
    if(j!=-1)
    {
      printf("search succesful:value %d is present at index %d",i,j);
    }
    else
    {
      printf("searched number is not present");
    }
  }
