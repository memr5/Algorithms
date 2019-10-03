package linear

// Search searches v in an given list arr.
func Search(arr []int, v int) int {
	for i := 0; i < len(arr); i++ {
		if arr[i] == v {
			return arr[i]
		}
	}
	return -1
}
