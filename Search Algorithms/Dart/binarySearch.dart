main() {
  var A = [3, 6, 8, 10, 12];
  
  print(binarySearch(A, 1)); // null
  print(binarySearch(A, 8)); // 2
  print(binarySearch(A, 12)); // 4
}

int binarySearch(List<int> input,int x) {
  int lowerBound = 0;
  int upperBound = input.length - 1;
  while (lowerBound <= upperBound) {
    int mid = (lowerBound + (upperBound - lowerBound) / 2).toInt();
    if (x == input[mid]) {
      return mid;
    } else if (x < input[mid]) {
      upperBound = mid - 1;
    } else {
      lowerBound = mid + 1;
    }
  }
  return null;
}
