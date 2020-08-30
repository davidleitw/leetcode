package golang

//Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func oddEvenList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	var index int = 1
	odd := new(ListNode)
	even := new(ListNode)

	odd_iter := odd
	even_iter := even

	for head != nil {
		temp := head.Next
		head.Next = nil

		if (index & 1) == 1 {
			odd_iter.Next = head
			odd_iter = odd_iter.Next
		} else {
			even_iter.Next = head
			even_iter = even_iter.Next
		}

		head = temp
		index++
	}
	odd_iter.Next = even.Next
	return odd.Next
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Odd Even Linked List.
// Memory Usage: 3.3 MB, less than 100.00% of Go online submissions for Odd Even Linked List.
