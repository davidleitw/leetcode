package golang

func xorOperation(n int, start int) int {
	var solve int = 0
	for idx := 0; idx < n; idx++ {
		solve ^= start + 2*idx
	}
	return solve
}

// 0 ms, faster than 100.00% of Go online submissions for XOR Operation in an Array.
// 1.9 MB, less than 100.00% of Go online submissions for XOR Operation in an Array.
