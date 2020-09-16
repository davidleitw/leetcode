package golang

func findMaxConsecutiveOnes(nums []int) int {
	var maxConsecutive int
	var currConsecutive int
	length := len(nums)
	for i := 0; i < length; i++ {
		if nums[i] == 1 {
			currConsecutive++
		} else {
			currConsecutive = 0
		}

		if currConsecutive > maxConsecutive {
			maxConsecutive = currConsecutive
		}
	}

	return maxConsecutive
}

// Runtime: 36 ms, faster than 96.94% of Go online submissions for Max Consecutive Ones.
// Memory Usage: 6.4 MB, less than 96.94% of Go online submissions for Max Consecutive Ones.
