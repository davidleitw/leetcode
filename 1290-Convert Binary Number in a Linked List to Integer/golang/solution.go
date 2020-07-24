package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

func getDecimalValue(head *ListNode) int {
	var solve int = 0
	for head != nil {
		if head.Val == 1 {
			solve |= head.Val
		}

		head = head.Next
		if head != nil {
			solve = solve << 1
		}
	}
	return solve
}

// 0 ms, faster than 100.00% of Go online submissions for Convert Binary Number in a Linked List to Integer.
// 2 MB, less than 78.26% of Go online submissions for Convert Binary Number in a Linked List to Integer.
