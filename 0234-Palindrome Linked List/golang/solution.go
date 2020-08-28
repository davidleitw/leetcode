package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

func isPalindrome(head *ListNode) bool {
	fast := head
	slow := head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}

	if fast != nil {
		slow = slow.Next
	}

	var prev *ListNode
	var next *ListNode

	for slow != nil {
		next = slow.Next
		slow.Next = prev
		prev = slow
		slow = next
	}

	for prev != nil {
		if head.Val != prev.Val {
			return false
		}
		head = head.Next
		prev = prev.Next
	}
	return true
}

// Runtime: 8 ms, faster than 100.00% of Go online submissions for Palindrome Linked List.
// Memory Usage: 6 MB, less than 92.43% of Go online submissions for Palindrome Linked List.
