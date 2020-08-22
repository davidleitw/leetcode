package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

// Monotonic stack solution.
func nextLargerNodes(head *ListNode) []int {
	var nums []int
	// nums := make([]int, 0)
	for head != nil {
		nums = append(nums, head.Val)
		head = head.Next
	}

	// stack := make([]int, 0)
	var stack []int
	solution := make([]int, len(nums))
	for idx := len(nums) - 1; idx >= 0; idx-- {
		// stack[len(stack) - 1] ==> stack.top(), the last element
		for len(stack) != 0 && nums[idx] >= nums[stack[len(stack)-1]] {
			stack = stack[:len(stack)-1] // pop
		}

		if len(stack) == 0 {
			solution[idx] = 0 // if stack.empty()
		} else {
			solution[idx] = nums[stack[len(stack)-1]] // solution[idx] = nums[stack.top()]
		}
		stack = append(stack, idx) // save index in stack
	}
	return solution
}

// 56 ms, faster than 97.01% of Go online submissions for Next Greater Node In Linked List.
// 7.1 MB, less than 52.24% of Go online submissions for Next Greater Node In Linked List.

func nextLargerNodes2(head *ListNode) []int {
	var nums []int
	for head != nil {
		nums = append(nums, head.Val)
		head = head.Next
	}

	var stack []int
	length := len(nums)
	solution := make([]int, length)
	for idx := 0; idx < length; idx++ {
		num := nums[idx]
		for len(stack) != 0 && num > nums[stack[len(stack)-1]] {
			solution[stack[len(stack)-1]] = num
			stack = stack[:len(stack)-1]
		}

		stack = append(stack, idx)
	}

	return solution
}

// Runtime: 56 ms, faster than 97.01% of Go online submissions for Next Greater Node In Linked List.
// Memory Usage: 7.1 MB, less than 47.76% of Go online submissions for Next Greater Node In Linked List.
