package solution

func runningSum(nums []int) []int {
	var sum int = 0
	solve := make([]int, len(nums))

	for idx, val := range nums {
		sum += val
		solve[idx] = sum
	}
	return solve
}

// 4 ms, faster than 40.00% of Go online submissions for Running Sum of 1d Array.
// 2.8 MB, less than 100.00% of Go online submissions for Running Sum of 1d Array.
