//Linear research with a flag value that interrupts research until the value is found.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ELEMENTS 10

bool research(int numSearch, int arr[]);

int main(){

    int array[ELEMENTS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    int search;
    bool found;
    
    printf("Array: ");
    for(i=0; i<ELEMENTS; i++)
        printf("%d", array[i]); 

    printf("Insert number to search: ");
    scanf("%d", &search);

    found = research(search, array);

    if(found){
        printf("The element is in the array.\n");
    }  
    else {
        printf("Element not in the array.\n");
    }
    
    return 0;
}

bool research(int numSearch, int arr[]){

    bool found = false;
    int i;

    for (i=0; found == false && i<ELEMENTS; i++){
        if(numSearch == arr[i])
            found = true;
        else 
            found = false;
    }

    return found;
}