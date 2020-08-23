package golang

func nextGreaterElements(nums []int) []int {
	var stack []int
	var solution []int
	length := len(nums)

	for idx := 0; idx < length; idx++ {
		solution = append(solution, -1)
	}

	for idx := 0; idx < 2*length-1; idx++ {
		val := nums[idx%length]
		for len(stack) != 0 && val > nums[stack[len(stack)-1]] {
			top := len(stack) - 1
			solution[stack[top]] = val
			stack = stack[:top]
		}

		if idx < length {
			stack = append(stack, idx)
		}
	}

	return solution
}
