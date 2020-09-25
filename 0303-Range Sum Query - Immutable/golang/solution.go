package golang

type NumArray struct {
	DP []int
}

func Constructor(nums []int) NumArray {
	var numArray NumArray
	if len(nums) == 0 {
		return numArray
	}

	var dp []int
	dp = append(dp, nums[0])
	for idx := 1; idx < len(nums); idx++ {
		dp = append(dp, dp[idx-1]+nums[idx])
	}
	numArray.DP = dp
	return numArray
}

func (this *NumArray) SumRange(i int, j int) int {
	if i == 0 {
		return this.DP[j]
	}
	return this.DP[j] - this.DP[i-1]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */

// Runtime: 32 ms, faster than 75.44% of Go online submissions for Range Sum Query - Immutable.
// Memory Usage: 12.1 MB, less than 5.26% of Go online submissions for Range Sum Query - Immutable.
