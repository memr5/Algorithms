#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int a[], int n){
	int i, j, key;
	for (j = 1;j < n; j++)
	{
	    key = a[j];
	    i = j - 1;
	    while (i >= 0 && a[i] > key){	//for decreasing order, use a[i]<key instead of a[i]>key.
	      a[i+1] = a[i];
	      i--;
	    }
	    a[i+1] = key;
  	}
}

int main(){

  int a[] ={5, 3, 7, 2, 1};
  int n = sizeof(a)/sizeof(a[0]);
  	
  insertion_sort(a, n);

  for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
//Time complexity: O(n^2)
