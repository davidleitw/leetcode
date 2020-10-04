package golang

func hammingWeight(num uint32) int {
	sum := 0
	for idx := 0; idx < 32; idx++ {
		sum += int(num & 1)
		num >>= 1
	}
	return sum
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Number of 1 Bits.
// Memory Usage: 2 MB, less than 78.95% of Go online submissions for Number of 1 Bits.
