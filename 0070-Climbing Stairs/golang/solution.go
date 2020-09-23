package golang

func climbStairs(n int) int {
	if n == 1 {
		return 1
	}
	step1 := 1
	step2 := 2
	for idx := 2; idx < n; idx++ {
		tmp := step1 + step2
		step1 = step2
		step2 = tmp
	}
	return step2
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Climbing Stairs.
// Memory Usage: 1.9 MB, less than 94.67% of Go online submissions for Climbing Stairs.
