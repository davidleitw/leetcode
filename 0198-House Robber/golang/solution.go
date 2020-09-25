package golang

func rob(nums []int) int {
	length := len(nums)
	if length == 0 {
		return 0
	}
	if length == 1 {
		return nums[0]
	}

	dp := make([]int, length)
	dp[0] = nums[0]
	dp[1] = max(nums[0], nums[1])

	for idx := 2; idx < length; idx++ {
		dp[idx] = max(dp[idx-1], dp[idx-2]+nums[idx])
	}
	return dp[length-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for House Robber.
// Memory Usage: 2 MB, less than 62.25% of Go online submissions for House Robber.
