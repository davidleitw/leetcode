package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeElements(head *ListNode, val int) *ListNode {
	if head == nil {
		return nil
	}
	for head != nil && head.Val == val {
		head = head.Next
	}

	prev := new(ListNode)
	start := head

	for start != nil {
		if start.Val == val {
			prev.Next = start.Next
		} else {
			prev = start
		}
		start = start.Next
	}
	return head
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Remove Linked List Elements.
// Memory Usage: 4.7 MB, less than 81.88% of Go online submissions for Remove Linked List Elements.
