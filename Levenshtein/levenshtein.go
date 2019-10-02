package main

func min(v1 int, vn ...int) (m int) {
	m = v1
	for i := 0; i < len(vn); i++ {
		if vn[i] < m {
			m = vn[i]
		}
	}
	return
}

// Levenshtein calculates the Levenshtein distance between the two input strings
func Levenshtein(a, b string) int {
	if len(a) == 0 {
		return len(b)
	}

	if len(b) == 0 {
		return len(a)
	}

	var c = 0
	if a[len(a)-1] != b[len(b)-1] {
		c = 1
	}

	return min(
		Levenshtein(a[:len(a)-1], b)+1,
		Levenshtein(a, b[:len(b)-1])+1,
		Levenshtein(a[:len(a)-1], b[:len(b)-1])+c,
	)
}
