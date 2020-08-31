package golang

//Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var s1 []int
	var s2 []int

	for l1 != nil {
		s1 = append(s1, l1.Val)
		l1 = l1.Next
	}
	for l2 != nil {
		s2 = append(s2, l2.Val)
		l2 = l2.Next
	}

	var sum int = 0
	solution := new(ListNode)
	for len(s1) != 0 || len(s2) != 0 {
		if length := len(s1); length > 0 {
			sum += s1[length-1]
			s1 = s1[:length-1]
		}
		if length := len(s2); length > 0 {
			sum += s2[length-1]
			s2 = s2[:length-1]
		}
		solution.Val = sum % 10
		iter := new(ListNode)
		iter.Val = sum / 10
		iter.Next = solution
		solution = iter
		sum = sum / 10
	}
	if solution.Val == 0 {
		return solution.Next
	} else {
		return solution
	}
}

// Runtime: 4 ms, faster than 98.91% of Go online submissions for Add Two Numbers II.
// Memory Usage: 5.7 MB, less than 25.00% of Go online submissions for Add Two Numbers II.
