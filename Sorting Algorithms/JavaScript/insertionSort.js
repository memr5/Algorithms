// Insertion sort
const insertionSort = (arr) => {
  let i, j, element;
  for (i = 1; i < arr.length; i++) {
    element = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > element) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = element;
  }
};

const unSortedArray = [34, 67, 32, 12, 56, 2, 65, 21, 32];
// Before sorting the array
console.log(unSortedArray);
// Output : [34,67,32,12,56,2,65,21,32]
insertionSort(unSortedArray);
// After sorting the array
console.log(unSortedArray);
// Output : [2, 12, 21, 32, 32, 34, 56, 65, 67]
