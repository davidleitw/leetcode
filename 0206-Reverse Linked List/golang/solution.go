package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	var solve *ListNode = nil
	for head != nil {
		temp := head.Next
		head.Next = solve
		solve = head
		head = temp
	}
	return solve
}

// 0 ms, faster than 100.00% of Go online submissions for Reverse Linked List.
// 2.5 MB, less than 99.03% of Go online submissions for Reverse Linked List.
