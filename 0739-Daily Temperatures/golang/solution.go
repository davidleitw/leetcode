package golang

func dailyTemperatures(T []int) []int {
	solution := make([]int, len(T))
	var stack []int

	for idx, val := range T {
		for (len(stack) != 0) && (val > T[stack[len(stack)-1]]) {
			index := stack[len(stack)-1]
			solution[index] = idx - index
			stack = stack[:len(stack)-1]
		}

		stack = append(stack, idx)
	}
	return solution
}

// Runtime: 48 ms, faster than 99.32% of Go online submissions for Daily Temperatures.
// Memory Usage: 7.1 MB, less than 25.34% of Go online submissions for Daily Temperatures.
