// To swap the element of the array
const swap = (arr, index) => {
  const temp = arr[index];
  arr[index] = arr[index + 1];
  arr[index + 1] = temp;
};
// Bubble sort
const bubbleSort = (arr) => {
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j);
      }
    }
  }
};
const unSortedArray = [43, 67, 25, 98, 32, 1, 5, 8, 2, 35];

// Before sorting the array
console.log(unSortedArray);
// Output : [43, 67, 25, 98, 32, 1, 5, 8, 2, 35]
selectionSort(unSortedArray);
// After sorting the array
console.log(unSortedArray);
// Output : [1, 2, 5, 8, 25, 32, 35, 43, 67, 98]
