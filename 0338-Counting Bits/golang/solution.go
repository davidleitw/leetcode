package golang

func countBits(num int) []int {
	dp := make([]int, num+1)
	dp[0] = 0
	for idx := 1; idx <= num; idx++ {
		if idx%2 == 0 {
			dp[idx] = dp[idx/2]
		} else {
			dp[idx] = dp[idx/2] + 1
		}
	}
	return dp
}

// Runtime: 4 ms, faster than 95.54% of Go online submissions for Counting Bits.
// Memory Usage: 4.5 MB, less than 38.22% of Go online submissions for Counting Bits.
