package main

import "fmt"

func bubbleSort(numbers []int) []int {
	if numbers != nil && len(numbers) > 0 {
		for i := 0; i < len(numbers); i++ {
			for j := 0; j < len(numbers); j++ {
				if numbers[i] < numbers[j] {
					temp := numbers[i]
					numbers[i] = numbers[j]
					numbers[j] = temp
				}
			}
		}
	} else {
		fmt.Println("Empty or Null Array")
	}
	return numbers
}

// main function
func main() {

	fmt.Println("Bubble Sort \n")

	// creating an integer array with values
	numbers := []int{4, 2, 1, 5, 3}

	fmt.Println("Before Sorting:", numbers)

	// calling the bubbleSort function
	numbers = bubbleSort(numbers)

	fmt.Println("\nAfter Sorting:", numbers)
}
