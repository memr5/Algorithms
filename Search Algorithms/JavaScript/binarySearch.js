// Binary Search
const binarySearch = (x, arr) => {
  let left = 0;
  let right = arr.length - 1;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] === x) {
      return `Congratulations! Found at position ${mid}`;
    }
    if (arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
};
const arr = [3, 6, 8, 32, 45, 76, 89, 92, 94, 100];
const x = binarySearch(76, arr);
const y = binarySearch(200, arr);

console.log(x);
// Output : Congratulations! Found at position 5
console.log(y);
// Output : -1
