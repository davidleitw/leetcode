package golang

func maxSumAfterPartitioning(arr []int, k int) int {
	size := len(arr)
	dp := make([]int, size)

	max_value := 0
	for i := 0; i < k; i++ {
		max_value = max(max_value, arr[i])
		dp[i] = max_value * (i + 1)
	}

	for i := k; i < size; i++ {
		max_value = 0
		for j := 0; j < k && i-j > 0; j++ {
			max_value = max(max_value, arr[i-j])
			dp[i] = max(dp[i], max_value*(j+1)+dp[i-j-1])
		}
	}
	return dp[size-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Runtime: 4 ms, faster than 100.00% of Go online submissions for Partition Array for Maximum Sum.
// Memory Usage: 2.9 MB, less than 50.00% of Go online submissions for Partition Array for Maximum Sum.
