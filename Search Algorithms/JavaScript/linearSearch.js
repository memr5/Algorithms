// Linear Search
const linearSearch = (x, arr) => {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === x) {
      return `Congratulations! Found at position ${i}`;
    }
  }
  return -1;
};
const arr = [2, 4, 67, 78, 6, 23, 56, 97];
const x = linearSearch(78, arr);
const y = linearSearch(100, arr);

console.log(x);
// Output : Congratulations! Found at position 3
console.log(y);
// Output : -1
