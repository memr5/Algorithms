/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<stdio.h>
int main(){
    int n,x,i,min,j,tv;
    char temp;
    scanf("%d %d",&n,&x);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d%c",&a[i],&temp);
    }
    j=0;
    while(x--){
        min=j;
        for(i=j+1;i<n;i++){
            if(a[min]>a[i]){
                min=i;
            }
        }
        tv=a[j];
        a[j]=a[min];
        a[min]=tv;
        j++;
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
return 0;
}
