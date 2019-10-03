package main

import (
	"Golang/linear"
	"fmt"
)

func main() {
	arr := []int{1, 2, 3, 4, 5}
	r := linear.Search(arr, 2)
	if r != -1 {
		fmt.Println("Found ", r, "!")
	}
}
