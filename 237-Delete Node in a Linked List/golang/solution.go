package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteNode(node *ListNode) {
	node.Val = node.Next.Val
	node.Next = node.Next.Next
}

// 0 ms, faster than 100.00% of Go online submissions for Delete Node in a Linked List.
// 2.9 MB, less than 59.49% of Go online submissions for Delete Node in a Linked List.
