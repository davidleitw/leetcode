package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	a := headA
	b := headB
	for a != b {
		if a != nil {
			a = a.Next
		} else {
			a = headB
		}

		if b != nil {
			b = b.Next
		} else {
			b = headA
		}
	}
	return a
}

// Runtime: 28 ms, faster than 100.00% of Go online submissions for Intersection of Two Linked Lists.
// Memory Usage: 8.5 MB, less than 20.82% of Go online submissions for Intersection of Two Linked Lists.
