package golang

type Node struct {
	Val   int
	Prev  *Node
	Next  *Node
	Child *Node
}

func flatten(root *Node) *Node {
	solution := root
	var stack []*Node
	for root != nil {
		if root.Child != nil {
			if root.Next != nil {
				stack = append(stack, root.Next)
			}
			root.Next = root.Child
			root.Next.Prev = root
			root.Child = nil
		}

		if root.Next == nil {
			break
		}
		root = root.Next
	}

	for len(stack) != 0 {
		top := len(stack) - 1
		root.Next = stack[top]
		root.Next.Prev = root
		stack = stack[:top]
		for root.Next != nil {
			root = root.Next
		}
	}
	return solution
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Flatten a Multilevel Doubly Linked List.
// Memory Usage: 2.9 MB, less than 70.27% of Go online submissions for Flatten a Multilevel Doubly Linked List.
