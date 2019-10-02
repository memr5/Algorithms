#include<stdio.h>

void bbSort(int arr[], int N)       //Function for Bubble Sorting
 {
    int i, j, aux;
    for (i = 1; i < N; i++)
    for (j = 0; j < N - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            aux = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = aux;
        }
    }
}

int main()
{
    int N, aux;
    printf("\nEnter the number of elements= ");
    scanf(" %d", &N);
    int arr[N];
    printf("\nEnter the elements= ");
    for(int i = 0; i < N; i++)
	{
        scanf(" %d", &aux);
        arr[i] = aux;
    }
    bbSort(arr, N);
    printf("\nThe sorted elements= \n");
    for(int i = 0; i < N; i++)
    {
        printf("\n%d", arr[i]);
    }
    return 0;
}
