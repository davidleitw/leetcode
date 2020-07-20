package golang

func shuffle(nums []int, n int) []int {
	solve := make([]int, 2*n)
	for idx := 0; idx < n; idx++ {
		solve[2*idx] = nums[idx]
		solve[2*idx+1] = nums[idx+n]
	}
	return solve
}

// Time: O(n)
// 4 ms, faster than 95.13% of Go online submissions for Shuffle the Array.
// 3.7 MB, less than 100.00% of Go online submissions for Shuffle the Array.
