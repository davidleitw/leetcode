package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

func middleNode(head *ListNode) *ListNode {
	var num int = 0
	solve := head

	for head != nil {
		head = head.Next
		num++
	}

	var middle int = num / 2
	for t := 0; t < middle; t++ {
		solve = solve.Next
	}
	return solve
}
