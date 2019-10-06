//Linear research with a flag value that interrupts research until the value is found.
#include <iostream>
#define ELEMENTS 10
using namespace std;

bool research(int numSearch, int arr[]);

int main(){

    int array[ELEMENTS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    int search;
    bool found;
    
    cout << "Array: ";
    for(i=0; i<ELEMENTS; i++)
        cout << " " << array[i];

    cout << endl << "Insert number to search: ";
    cin >> search;

    found = research(search, array);

    if(found)
        cout << "The element is in the array." << endl;
    else
        cout << "Element not in the array." << endl; 
    
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