package golang

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func getMinimumDifference(root *TreeNode) int {
	var stack []*TreeNode
	var prevVal int = 0
	var prevExist bool = false
	var solution int = math.MaxInt32

	for root != nil || len(stack) != 0 {
		if root != nil {
			stack = append(stack, root)
			root = root.Left
		} else {
			tmp := stack[len(stack)-1]   // tmp := stack.top()
			stack = stack[:len(stack)-1] // stack.pop()
			if prevExist {
				val := tmp.Val - prevVal
				if solution > val {
					solution = val
				}
			}
			prevVal = tmp.Val
			prevExist = true
			root = tmp.Right
		}
	}

	return solution
}

// Runtime: 8 ms, faster than 94.23% of Go online submissions for Minimum Absolute Difference in BST.
// Memory Usage: 6 MB, less than 53.85% of Go online submissions for Minimum Absolute Difference in BST.

func getMinimumDifference2(root *TreeNode) int {
	var nums []int
	inorder(root, &nums)
	var solution int = math.MaxInt32
	for idx := 0; idx < len(nums)-1; idx++ {
		if nums[idx+1]-nums[idx] < solution {
			solution = nums[idx+1] - nums[idx]
		}
	}
	return solution
}

func inorder(root *TreeNode, nums *[]int) {
	if root == nil {
		return
	}
	inorder(root.Left, nums)
	*nums = append(*nums, root.Val)
	inorder(root.Right, nums)
	return
}

// Runtime: 0 ms, faster than 100.00% of Go online submissions for Minimum Absolute Difference in BST.
// Memory Usage: 6.1 MB, less than 42.31% of Go online submissions for Minimum Absolute Difference in BST.
