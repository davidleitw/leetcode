package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return false
	}

	faster := head

	for faster != nil && faster.Next != nil {
		head = head.Next
		faster = faster.Next.Next
		if head == faster {
			return true
		}
	}

	return false
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Linked List Cycle.
// Memory Usage: 3.9 MB, less than 46.90% of Go online submissions for Linked List Cycle.
