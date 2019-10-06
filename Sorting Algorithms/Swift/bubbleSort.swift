func swap(Arr: inout [Int], x: Int, y: Int) {
    let temp = Arr[x]
    Arr[x] = Arr[y]
    Arr[y] = temp
}

func bubbleSort(Arr: inout [Int]) {
    for _ in 0 ..< Arr.count {
        for i in 0 ..< Arr.count - 1 {
            if Arr[i] > Arr[i+1] {
                swap(Arr: &Arr, x: i, y: i+1)
            }
        }
    }
}

let unsortedIntegers = [5, 8, 3, 4, -1, 3, 8, 32423423]
var sortedIntegers = unsortedIntegers
bubbleSort(Arr: &sortedIntegers)

print("Unsorted Integers: \(unsortedIntegers)")
print("Sorted Integers: \(sortedIntegers)")
