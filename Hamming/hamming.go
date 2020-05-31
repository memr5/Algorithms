package main

// HammingWeight calculates the Hamming weight of the input number
func HammingWeight(x uint64) int {
	var c int
	for c = 0; x != 0; c++ {
		x = x & (x - 1)
	}
	return c
}

//HammingDistance calculates the Hamming distance between the two input numbers
func HammingDistance(x, y uint64) int {
	return HammingWeight(x ^ y)
}
