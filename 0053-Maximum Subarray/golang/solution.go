package golang

import "math"

func maxSubArray(nums []int) int {
	sum := 0
	solution := math.MinInt32
	for _, num := range nums {
		sum += num
		if num > sum {
			sum = num
		}
		if sum > solution {
			solution = sum
		}
	}

	return solution
}

// Runtime: 4 ms, faster than 97.88% of Go online submissions for Maximum Subarray.
// Memory Usage: 3.3 MB, less than 73.13% of Go online submissions for Maximum Subarray.
