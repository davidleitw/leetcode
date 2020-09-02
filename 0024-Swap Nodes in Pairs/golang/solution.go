package golang

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	var prev *ListNode
	solution := head.Next
	for head != nil {
		if head.Next != nil {
			tmp := head.Next
			head.Next = tmp.Next
			tmp.Next = head
			if prev != nil {
				prev.Next = tmp
			}
			prev = head
		}
		head = head.Next
	}

	return solution
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Swap Nodes in Pairs.
// Memory Usage: 2.1 MB, less than 55.56% of Go online submissions for Swap Nodes in Pairs.
