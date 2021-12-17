// To swap the element of the array
const swap = (arr, minIndex, currentIndex) => {
  const temp = arr[minIndex];
  arr[minIndex] = arr[currentIndex];
  arr[currentIndex] = temp;
};
// Selection sort
const selectionSort = (arr) => {
  let minIndex;
  for (let i = 0; i < arr.length; i++) {
    minIndex = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[minIndex] > arr[j]) {
        minIndex = j;
      }
      swap(arr, minIndex, i);
    }
  }
};

const unSortedArray = [267, 1, 23, 62, 62, 76, 7, 9];
// Before sorting the array
console.log(unSortedArray);
// Output : [267, 1, 23, 62, 62, 76, 7, 9]
selectionSort(unSortedArray);
// After sorting the array
console.log(unSortedArray);
// Output : [1, 9, 7, 62, 23, 62, 76, 267]
