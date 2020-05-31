package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func Kadane(n []int) int {
	msf := 0
	meh := 0
	for _, i := range n {
		meh += i
		meh = max(meh, 0)
		msf = max(msf, meh)
	}
	return msf
}
