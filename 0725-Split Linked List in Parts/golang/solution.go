package golang

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func splitListToParts(root *ListNode, k int) []*ListNode {
	var container []*ListNode
	for root != nil {
		container = append(container, root)
		root = root.Next
	}

	var solution []*ListNode
	length := len(container)
	if length < k {
		for i := 0; i < length; i++ {
			container[i].Next = nil
			solution = append(solution, container[i])
		}
		for i := 0; i < k-length; i++ {
			solution = append(solution, nil)
		}
		return solution
	}

	index := 0
	avg := length / k // 7/3 = 2
	exp := length % k // 7%3 = 1
	step := avg + 1
	for turn := 0; turn < exp; turn++ {
		container[index+step-1].Next = nil
		solution = append(solution, container[index])
		index += step
	}
	step--
	for turn := 0; turn < k-exp; turn++ {
		container[index+step-1].Next = nil
		solution = append(solution, container[index])
		index += step
	}
	return solution
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Split Linked List in Parts.
// Memory Usage: 2.9 MB, less than 23.53% of Go online submissions for Split Linked List in Parts.
